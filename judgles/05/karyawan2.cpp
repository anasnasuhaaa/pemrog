#include <bits/stdc++.h>
using namespace std;

class Karyawan
{
protected:
  string id;
  string nama;

public:
  Karyawan(string id, string nama)
      : id(id), nama(nama) {}

  virtual long double totalGaji() const = 0;

  string getId() const
  {
    return id;
  }

  virtual ~Karyawan() = default;
};

class KaryawanTetap : public Karyawan
{
private:
  long double gajiPokokBulanan;
  long double tunjanganJabatanTetap;
  long double bonusKinerjaBulanan;

public:
  KaryawanTetap(
      string id,
      string nama,
      long double gpb,
      long double tjt,
      long double bkb)
      : Karyawan(id, nama),
        gajiPokokBulanan(gpb),
        tunjanganJabatanTetap(tjt),
        bonusKinerjaBulanan(bkb) {}

  long double totalGaji() const override
  {
    return gajiPokokBulanan + tunjanganJabatanTetap + bonusKinerjaBulanan;
  }
};

class KaryawanKontrakTahunan : public Karyawan
{
private:
  long double nilaiKontrakTahunan;
  long double tunjangan;

public:
  KaryawanKontrakTahunan(
      string id,
      string nama,
      long double nkt,
      long double t)
      : Karyawan(id, nama),
        nilaiKontrakTahunan(nkt),
        tunjangan(t) {}

  long double totalGaji() const override
  {
    return (nilaiKontrakTahunan / 12.0L) + tunjangan;
  }
};

class KaryawanHarianLepas : public Karyawan
{
private:
  long double upahHarian;
  long double totalHariHadir;
  long double insentifJamLemburHarian;

public:
  KaryawanHarianLepas(
      string id,
      string nama,
      long double uh,
      long double thh,
      long double ijlh)
      : Karyawan(id, nama),
        upahHarian(uh),
        totalHariHadir(thh),
        insentifJamLemburHarian(ijlh) {}

  long double totalGaji() const override
  {
    return (upahHarian * totalHariHadir) + (insentifJamLemburHarian * totalHariHadir);
  }
};

class ThousandSeparator : public numpunct<char>
{
protected:
  char do_thousands_sep() const override
  {
    return ',';
  }

  string do_grouping() const override
  {
    return "\3";
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cout.imbue(locale(cout.getloc(), new ThousandSeparator));

  string input;

  while (getline(cin, input))
  {
    if (input.empty())
      continue;

    if (!input.empty() && input.back() == '\r')
      input.pop_back();

    vector<string> tokens;
    string temp;

    stringstream ss(input);

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
          stold(tokens[3]),
          stold(tokens[4]),
          stold(tokens[5]));
    }
    else if (tokens[0] == "2")
    {
      k = new KaryawanKontrakTahunan(
          tokens[1],
          tokens[2],
          stold(tokens[3]),
          stold(tokens[4]));
    }
    else if (tokens[0] == "3")
    {
      k = new KaryawanHarianLepas(
          tokens[1],
          tokens[2],
          stold(tokens[4]),
          stold(tokens[3]),
          stold(tokens[5]));
    }
    if (k != nullptr)
    {
      cout << k->getId()
           << " : "
           << fixed
           << setprecision(0)
           << k->totalGaji()
           << '\n';

      delete k;
    }
  }

  return 0;
}