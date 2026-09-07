#include <iostream>
#include <string>
using namespace std;

class Pegawai
{
protected:
  string id;
  int usia;
  int tipe;
  int income;

public:
  Pegawai()
  {
    id = "";
    usia = income = 0;
    tipe = 1;
  }
  void set(string pid, int u, int t)
  {
    id = pid;
    usia = u;
    tipe = t;
  }
  string getID() { return id; }
  // void show() { printf("%s %d %d\n", id, tipe, income); }
  void show()
  {
    cout << id << " " << tipe << " " << income << endl;
  }
};

class PegawaiTetap : public Pegawai
{
private:
  int gaji_pokok, uang_lembur;

public:
  PegawaiTetap() : Pegawai(), gaji_pokok(0), uang_lembur(0) {};
  void setPegawaiTetap(string id_pegawai, int usia_pegawai, int gaji)
  {
    id = id_pegawai;
    usia = usia_pegawai;
    tipe = 1;
    gaji_pokok = gaji;
    income += gaji_pokok;
  }
  void setUangLembur(int ulembur)
  {
    uang_lembur = ulembur;
    income += uang_lembur;
  }
};

class PegawaiHarian : public Pegawai
{
private:
  int upah;

public:
  PegawaiHarian() : Pegawai(), upah(0) {};
  void setPegawaiHarian(string id_pegawai, int usia_pegawai)
  {
    id = id_pegawai;
    usia = usia_pegawai;
    tipe = 2;
  }
  void setUpah(int u)
  {
    upah = u;
    income = upah;
  }
};

int main()
{
  int n;
  cin >> n;

  PegawaiTetap pt[n];
  PegawaiHarian ph[n];
  int coutPt = 0, coutPh = 0;

  for (int i = 0; i < n; i++)
  {
    string id;
    int usia, tipe, gaji;
    cin >> id >> usia >> tipe;

    if (tipe == 1)
    {
      cin >> gaji;
      // PERBAIKAN 1: Gunakan coutPt sebagai index
      pt[coutPt].setPegawaiTetap(id, usia, gaji);
      coutPt++;
    }
    else
    {
      // PERBAIKAN 1: Gunakan coutPh sebagai index
      ph[coutPh].setPegawaiHarian(id, usia);
      coutPh++;
    }
  }

  string id;
  int upah;
  // PERBAIKAN 2: Menggunakan cin biasa alih-alih getline
  while (cin >> id && id != "END")
  {
    cin >> upah;

    // PERBAIKAN 3: Loop berdasarkan jumlah spesifik masing-masing tipe
    for (int i = 0; i < coutPt; i++)
    {
      if (pt[i].getID() == id)
      {
        pt[i].setUangLembur(upah);
        break; // Hentikan pencarian jika id sudah ditemukan
      }
    }
    for (int i = 0; i < coutPh; i++)
    {
      if (ph[i].getID() == id)
      {
        ph[i].setUpah(upah);
        break; // Hentikan pencarian jika id sudah ditemukan
      }
    }
  }

  // Output Data
  for (int i = 0; i < coutPt; i++)
  {
    pt[i].show();
  }
  for (int i = 0; i < coutPh; i++)
  {
    ph[i].show();
  }

  return 0;
}