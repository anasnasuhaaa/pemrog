#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Kendaraan
{
protected:
  string nomorPlat;
  string jenisKendaraan;
  int jamMasuk;
  int jamKeluar;

public:
  Kendaraan(string plat, string jenis, int masuk, int keluar)
  {
    nomorPlat = plat;
    jenisKendaraan = jenis;
    jamMasuk = masuk;
    jamKeluar = keluar;
  }

  int hitungDurasi()
  {
    return jamKeluar - jamMasuk;
  }
  virtual double hitungTarif()
  {
    return 0.0;
  }
  virtual void tampilkanInfo()
  {
    cout << "Nomor Plat      : " << nomorPlat << endl;
    cout << "Jenis Kendaraan : " << jenisKendaraan << endl;

    cout << "Durasi Parkir   : " << hitungDurasi() << " Jam (";

    cout << setfill('0') << setw(2) << jamMasuk << ":00 - ";
    cout << setfill('0') << setw(2) << jamKeluar << ":00)" << endl;
    cout << setfill(' ');
  }
  virtual ~Kendaraan() {}
};

class Mobil : public Kendaraan
{
private:
  int kapasitasPenumpang;

public:
  Mobil(
      string plat,
      string jenis,
      int kapasitas,
      int masuk,
      int keluar) : Kendaraan(plat, jenis, masuk, keluar)
  {
    kapasitasPenumpang = kapasitas;
  }
  double hitungTarif() override
  {
    int durasi = hitungDurasi();

    if (durasi <= 0)
    {
      return 0;
    }

    if (durasi == 1)
    {
      return 5000;
    }
    return 5000 + (durasi - 1) * 3000;
  }
  void tampilkanInfo() override
  {
    cout << "Kendaraan       : Mobil" << endl;

    Kendaraan::tampilkanInfo();

    cout << "Kapasitas       : "
         << kapasitasPenumpang
         << " Penumpang" << endl;

    cout << "Total Tarif     : Rp "
         << static_cast<long long>(hitungTarif())
         << endl;
  }
};

class Motor : public Kendaraan
{
private:
  string jenisMotor;

public:
  Motor(
      string plat,
      string jenis,
      string tipeMotor,
      int masuk,
      int keluar) : Kendaraan(plat, jenis, masuk, keluar)
  {
    jenisMotor = tipeMotor;
  }
  double hitungTarif() override
  {
    int durasi = hitungDurasi();

    if (durasi <= 0)
    {
      return 0;
    }

    if (durasi == 1)
    {
      return 2000;
    }

    return 2000 + (durasi - 1) * 1000;
  }
  void tampilkanInfo() override
  {
    cout << "Kendaraan       : Motor" << endl;

    Kendaraan::tampilkanInfo();

    cout << "Tipe Motor      : "
         << jenisMotor
         << endl;

    cout << "Total Tarif     : Rp "
         << static_cast<long long>(hitungTarif())
         << endl;
  }
};

int main()
{
  int N;
  cin >> N;

  vector<Kendaraan *> daftarKendaraan;

  for (int i = 0; i < N; i++)
  {
    string tipe;
    string nomorPlat;
    string jenisKendaraan;

    int jamMasuk;
    int jamKeluar;

    cin >> tipe;

    if (tipe == "Mobil")
    {
      int kapasitas;

      cin >> nomorPlat >> jenisKendaraan >> kapasitas >> jamMasuk >> jamKeluar;

      daftarKendaraan.push_back(
          new Mobil(
              nomorPlat,
              jenisKendaraan,
              kapasitas,
              jamMasuk,
              jamKeluar));
    }
    else if (tipe == "Motor")
    {
      string jenisMotor;

      cin >> nomorPlat >> jenisKendaraan >> jenisMotor >> jamMasuk >> jamKeluar;

      daftarKendaraan.push_back(
          new Motor(
              nomorPlat,
              jenisKendaraan,
              jenisMotor,
              jamMasuk,
              jamKeluar));
    }
  }

  for (int i = 0; i < daftarKendaraan.size(); i++)
  {
    cout << "--- DATA PARKIR KENDARAAN "
         << i + 1
         << " ---"
         << endl;

    daftarKendaraan[i]->tampilkanInfo();

    if (i != daftarKendaraan.size() - 1)
    {
      cout << endl;
    }
  }

  for (Kendaraan *kendaraan : daftarKendaraan)
  {
    delete kendaraan;
  }
  return 0;
}