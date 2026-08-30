#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Person
{
private:
  string nama;
  int usia;
  int tinggi;
  double berat;

public:
  // Constructor
  Person()
  {
    nama = "";
    usia = 0;
    tinggi = 0;
    berat = 0.0;
  }

  // Setter / Mutator
  void setPerson(string nm, int u, int t, double b)
  {
    nama = nm;
    usia = u;
    tinggi = t;
    berat = b;
  }

  // Getter / Accessor
  string getNama() { return nama; }
  int getUsia() { return usia; }
  int getTinggi() { return tinggi; }
  double getBerat() { return berat; }

  double getIMT()
  {
    // Pembagian dengan 100.0 otomatis mengubah int ke double
    return berat / ((tinggi / 100.0) * (tinggi / 100.0));
  }

  string getStatusGizi(double imt)
  {
    // Logika disederhanakan karena dieksekusi berurutan
    if (imt >= 28.0)
      return "sangat gemuk";
    if (imt >= 25.0)
      return "gemuk";
    if (imt >= 18.5)
      return "normal";
    if (imt >= 17.0)
      return "kurus";
    return "sangat kurus";
  }
};

int main()
{
  int n;
  if (!(cin >> n))
    return 0; // Guard clause untuk keamanan input

  Person p[100];
  double avgHeight = 0.0;

  // Loop 1: Membaca input sekaligus mengakumulasi total tinggi
  for (int i = 0; i < n; i++)
  {
    string nama;
    int usia, tinggi;
    double berat;

    cin >> nama >> usia >> tinggi >> berat;
    p[i].setPerson(nama, usia, tinggi, berat);
    avgHeight += tinggi;
  }

  // Menghitung rata-rata tinggi
  avgHeight /= n;

  int count_overAvgHeight = 0;
  int count_sk = 0, count_k = 0, count_n = 0, count_g = 0, count_sg = 0;

  // Loop 2: Menampilkan output baris-per-baris sekaligus menghitung statistik
  for (int i = 0; i < n; i++)
  {
    double imt = p[i].getIMT();
    string status = p[i].getStatusGizi(imt);

    // Cetak data individu
    cout << p[i].getNama() << " "
         << p[i].getUsia() << " "
         << p[i].getTinggi() << " "
         << fixed << setprecision(2) << p[i].getBerat() << " "
         << fixed << setprecision(2) << imt << " "
         << status << endl;

    // Cek jika tinggi di atas rata-rata
    if (p[i].getTinggi() > avgHeight)
    {
      count_overAvgHeight++;
    }

    // Akumulasi perhitungan status gizi
    if (status == "sangat gemuk")
      count_sg++;
    else if (status == "gemuk")
      count_g++;
    else if (status == "normal")
      count_n++;
    else if (status == "kurus")
      count_k++;
    else
      count_sk++;
  }

  // Cetak rekapitulasi data (sesuai format soal)
  cout << fixed << setprecision(2) << avgHeight << endl;
  cout << count_overAvgHeight << endl;
  cout << count_sk << " " << count_k << " " << count_n << " " << count_g << " " << count_sg << endl;

  return 0;
}