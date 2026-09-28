#include <bits/stdc++.h>
using namespace std;

class Karyawan
{
private:
  string id;
  string nama;

public:
  Karyawan() : id(""), nama("") {};
  virtual double hitungGajiTotal() = 0;
  virtual ~Karyawan() = default;
};

class KaryawanTetap : public Karyawan
{
private:
  double gajiPokok;
  double tunjanganJabatanTetap;
  double bonusKinerja;

public:
  KaryawanTetap() : Karyawan(), gajiPokok(0), tunjanganJabatanTetap(0), bonusKinerja(0) {};
  double hitungGajiTotal()
  {
    return gajiPokok + tunjanganJabatanTetap + bonusKinerja;
  }
};

class KontrakTahunan : public Karyawan
{
private:
  double nilaiKontrakTahunan;
  double tunjanganPenyelesaianProyakAktif;

public:
  KontrakTahunan() : Karyawan(), nilaiKontrakTahunan(0), tunjanganPenyelesaianProyakAktif(0) {};
  double hitungGajiTotal()
  {
    return (nilaiKontrakTahunan / 12.0) + tunjanganPenyelesaianProyakAktif;
  }
};

class KaryawanHarian : public Karyawan
{
private:
  double upahHarian;
  int totalHariHadir;
  double insentifPerJamLembur = 30000;
  int totalJamLemburHarian;

public:
  KaryawanHarian() : Karyawan(), upahHarian(0), totalHariHadir(0) {};
  double hitungGajiTotal()
  {
    return upahHarian * totalHariHadir;
  }
};

int main()
{

  return 0;
}