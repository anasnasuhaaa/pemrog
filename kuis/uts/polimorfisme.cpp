#include <bits/stdc++.h>

class Bangun
{
public:
  virtual double hitungLuas() = 0;
  virtual ~Bangun() = default;
};

class Persegi : public Bangun
{
  double sisi;

public:
  Persegi(double s) { sisi = s; }
  double hitungLuas()
  {
    return sisi * sisi;
  }
};

class Lingkaran : public Bangun
{
  double r;
  const float phi = 3.14;

public:
  Lingkaran(double jari) { r = jari; }
  double hitungLuas()
  {
    return phi * pow(r, 2);
  }
};

int main()
{
  return 0;
}