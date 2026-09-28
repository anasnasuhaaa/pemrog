#include <bits/stdc++.h>
using namespace std;

class Karyawan
{
protected:
  string id;
  string nama;

public:
  Karyawan(string id, string nama) : id(id), nama(nama) {}

  virtual double totalGaji() = 0;
  virtual ~Karyawan() = default;
};

class KaryawanTetap : public Karyawan
{
private:
  double gajiPokokBulanan;
  double tunjanganJabatanTetap;
  double bonusKinerjaBulanan;

public:
  KaryawanTetap(string id, string nama, double gpb, double tjt, double bkb)
      : Karyawan(id, nama),
        gajiPokokBulanan(gpb),
        tunjanganJabatanTetap(tjt),
        bonusKinerjaBulanan(bkb) {}

  double totalGaji() override
  {
    return gajiPokokBulanan +
           tunjanganJabatanTetap +
           bonusKinerjaBulanan;
  }
};

class KaryawanKontrakTahunan : public Karyawan
{
private:
  double nilaiKontrakTahunan;
  double tunjangan;

public:
  KaryawanKontrakTahunan(string id, string nama, double nkt, double t)
      : Karyawan(id, nama),
        nilaiKontrakTahunan(nkt),
        tunjangan(t) {}

  double totalGaji() override
  {
    return (nilaiKontrakTahunan / 12.0) + tunjangan;
  }
};

class KaryawanHarianLepas : public Karyawan
{
private:
  double upahHarian;
  double totalHariHadir;
  double insentifJamLemburHarian;

public:
  KaryawanHarianLepas(string id, string nama, double uh, double thh, double ijlh)
      : Karyawan(id, nama),
        upahHarian(uh),
        totalHariHadir(thh),
        insentifJamLemburHarian(ijlh) {}

  double totalGaji() override
  {
    return (upahHarian * totalHariHadir) +
           (insentifJamLemburHarian * totalHariHadir);
  }
};

string thousandSeparator(long long n)
{
  string num = to_string(n);

  for (int i = num.length() - 3; i > 0; i -= 3)
  {
    num.insert(i, ",");
  }

  return num;
}

int main()
{
  string input;

  while (getline(cin, input))
  {
    if (input.empty())
      continue;

    vector<string> tokens;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, ','))
    {
      tokens.push_back(temp);
    }

    Karyawan *k = nullptr;

    if (tokens[0] == "1")
    {
      k = new KaryawanTetap(
          tokens[1],
          tokens[2],
          stod(tokens[3]),
          stod(tokens[4]),
          stod(tokens[5]));
    }
    else if (tokens[0] == "2")
    {
      k = new KaryawanKontrakTahunan(
          tokens[1],
          tokens[2],
          stod(tokens[3]),
          stod(tokens[4]));
    }
    else if (tokens[0] == "3")
    {
      k = new KaryawanHarianLepas(
          tokens[1],
          tokens[2],
          stod(tokens[4]),
          stod(tokens[3]),
          stod(tokens[5]));
    }

    if (k != nullptr)
    {
      long long gaji = llround(k->totalGaji());

      cout << tokens[1]
           << " : "
           << thousandSeparator(gaji)
           << '\n';

      delete k;
    }
  }

  return 0;
}