#include <bits/stdc++.h>
using namespace std;

class Bidang
{
public:
  virtual double hitungLuas() const = 0;
  virtual ~Bidang() = default;
};

class Lingkaran : public Bidang
{
protected:
  const double pi = 3.14;
  double radius;

public:
  Lingkaran(double r) : radius(r) {}
  double hitungLuas() const override
  {
    return pi * radius * radius;
  }
};

class Segitiga : public Bidang
{
private:
  double alas;
  double tinggi;

public:
  Segitiga(double a, double t) : alas(a), tinggi(t) {}
  double hitungLuas() const override
  {
    return alas * 0.5 * tinggi;
  }
};

class Segiempat : public Bidang
{
private:
  double panjang;
  double lebar;

public:
  Segiempat(double p, double l) : panjang(p), lebar(l) {}
  double hitungLuas() const override
  {
    return panjang * lebar;
  }
};

class Silinder : public Lingkaran
{
private:
  double tinggi;

public:
  Silinder(double r, double t) : Lingkaran(r), tinggi(t) {}
  double hitungLuas() const override
  {
    return 2 * pi * radius * (radius + tinggi);
  }
};

int main()
{
  int n;
  double r;
  double p, l;
  double a, t;

  int bawah, atas;
  vector<double> total;

  string id;
  string bangunan;

  double luas = 0;
  cin >> n;

  while (n--)
  {
    cin >> id >> bangunan;
    if (bangunan == "Lingkaran")
    {
      cin >> r;
      Lingkaran object(r);
      luas += object.hitungLuas();
    }
    else if (bangunan == "Segitiga")
    {
      cin >> a >> t;
      Segitiga object(a, t);
      luas += object.hitungLuas();
    }
    else if (bangunan == "Silinder")
    {
      cin >> r >> t;
      Silinder object(r, t);
      luas += object.hitungLuas();
    }
    else if (bangunan == "Segiempat")
    {
      cin >> p >> l;
      Segiempat object(p, l);
      luas += object.hitungLuas();
    }

    total.push_back(luas);
  }

  cin >> bawah;
  while (bawah != -9)
  {
    cin >> atas;
    cout << bawah << "-" << atas << " : " << fixed << setprecision(2) << total[atas - 1] - total[bawah - 2] << endl;
    cin >> bawah;
  }

  return 0;
}