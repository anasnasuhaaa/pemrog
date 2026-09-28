#include <bits/stdc++.h>
using namespace std;

class BangunDatar
{
public:
  virtual double luas() = 0;
  virtual ~BangunDatar() = default;
};

class Persegi : public BangunDatar
{
private:
  double sisi;

public:
  Persegi(double s) : sisi(s) {};
  double luas()
  {
    return sisi * sisi;
  }
};

class Lingkaran : public BangunDatar
{
private:
  double jarijari;
  const double phi = 3.14;

public:
  Lingkaran(double j) : jarijari(j) {};
  double luas()
  {
    return phi * pow(jarijari, 2);
  }
};

int main()
{
  string mode;
  cin >> mode;

  BangunDatar *b;

  if (mode == "P")
  {
    double s;
    cout << "Masukkan sisi: ";
    cin >> s;

    b = new Persegi(s);
    cout << "Luas Persegi: " << b->luas() << endl;
  }
  else if (mode == "L")
  {
    double j;
    cout << "Masukkan Jari-jari: ";
    cin >> j;

    b = new Lingkaran(j);

    cout << "Luas Lingkaran: " << b->luas() << endl;
  }

  delete b;
  return 0;
}