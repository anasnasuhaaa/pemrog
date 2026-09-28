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
  Kendaraan(string nomorPlat, string jenisKendaraan,
            int jamMasuk, int jamKeluar)
      : nomorPlat(nomorPlat),
        jenisKendaraan(jenisKendaraan),
        jamMasuk(jamMasuk),
        jamKeluar(jamKeluar)
  {
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
    cout << "Nomor Plat      : " << nomorPlat << '\n';
    cout << "Jenis Kendaraan : " << jenisKendaraan << '\n';

    cout << "Durasi Parkir   : "
         << hitungDurasi()
         << " Jam ("
         << setfill('0') << setw(2) << jamMasuk
         << ":00 - "
         << setw(2) << jamKeluar
         << ":00)"
         << setfill(' ')
         << '\n';
  }

  virtual ~Kendaraan() = default;
};

class Mobil : public Kendaraan
{
private:
  int kapasitasPenumpang;

public:
  Mobil(string nomorPlat, string jenisKendaraan,
        int kapasitasPenumpang,
        int jamMasuk, int jamKeluar)
      : Kendaraan(nomorPlat, jenisKendaraan, jamMasuk, jamKeluar),
        kapasitasPenumpang(kapasitasPenumpang)
  {
  }

  double hitungTarif() override
  {
    int durasi = hitungDurasi();

    if (durasi <= 1)
      return 5000;

    return 5000 + (durasi - 1) * 3000;
  }

  void tampilkanInfo() override
  {
    cout << "Kendaraan       : Mobil\n";

    Kendaraan::tampilkanInfo();

    cout << "Kapasitas       : "
         << kapasitasPenumpang
         << " Penumpang\n";

    cout << "Total Tarif     : Rp "
         << static_cast<long long>(hitungTarif())
         << '\n';
  }
};

class Motor : public Kendaraan
{
private:
  string jenisMotor;

public:
  Motor(string nomorPlat, string jenisKendaraan,
        string jenisMotor,
        int jamMasuk, int jamKeluar)
      : Kendaraan(nomorPlat, jenisKendaraan, jamMasuk, jamKeluar),
        jenisMotor(jenisMotor)
  {
  }

  double hitungTarif() override
  {
    int durasi = hitungDurasi();

    if (durasi <= 1)
      return 2000;

    return 2000 + (durasi - 1) * 1000;
  }

  void tampilkanInfo() override
  {
    cout << "Kendaraan       : Motor\n";

    Kendaraan::tampilkanInfo();

    cout << "Tipe Motor      : "
         << jenisMotor
         << '\n';

    cout << "Total Tarif     : Rp "
         << static_cast<long long>(hitungTarif())
         << '\n';
  }
};

int main()
{
  int N;
  cin >> N;

  vector<Kendaraan *> kendaraan;

  for (int i = 0; i < N; i++)
  {
    string tipe;
    string plat;
    string jenis;
    int jamMasuk;
    int jamKeluar;

    cin >> tipe;

    if (tipe == "Mobil")
    {
      int kapasitas;

      cin >> plat >> jenis >> kapasitas >> jamMasuk >> jamKeluar;

      kendaraan.push_back(
          new Mobil(
              plat,
              jenis,
              kapasitas,
              jamMasuk,
              jamKeluar));
    }
    else if (tipe == "Motor")
    {
      string jenisMotor;

      cin >> plat >> jenis >> jenisMotor >> jamMasuk >> jamKeluar;

      kendaraan.push_back(
          new Motor(
              plat,
              jenis,
              jenisMotor,
              jamMasuk,
              jamKeluar));
    }
  }

  for (int i = 0; i < N; i++)
  {
    cout << "--- DATA PARKIR KENDARAAN "
         << i + 1
         << " ---\n";

    kendaraan[i]->tampilkanInfo();

    if (i < N - 1)
      cout << '\n';
  }

  for (Kendaraan *k : kendaraan)
  {
    delete k;
  }

  return 0;
}