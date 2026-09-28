#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

class Bangun
{
public:
  virtual double hitungLuas() = 0;
  virtual ~Bangun() = default;
};

class Persegi : public Bangun
{
private:
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
private:
  double jari_jari;
  const double phi = 3.1425;

public:
  Lingkaran(double j) { jari_jari = j; }
  double hitungLuas()
  {
    return phi * pow(jari_jari, 2);
  }
};

class Bangun3D : public Bangun
{
public:
  virtual double hitungVolume() = 0;
};

class Kubus : public Bangun3D
{
private:
  double sisi;

public:
  Kubus(double s) { sisi = s; }
  double hitungVolume()
  {
    return pow(sisi, 3);
  }
  double hitungLuas()
  {
    return pow(sisi, 2) * 6;
  }
};

class Bola : public Bangun3D
{
private:
  double jari_jari;
  const double phi = 3.1425;

public:
  Bola(double j) { jari_jari = j; }
  double hitungVolume()
  {
    return (4.0 / 3.0) * phi * pow(jari_jari, 3);
  }
  double hitungLuas()
  {
    return 4 * phi * pow(jari_jari, 2);
  }
};

int main()
{
  int n;
  cin >> n;

  double totalLuas = 0;
  double totalVolume = 0;

  for (int i = 0; i < n; i++)
  {
    char input;
    double num;

    cin >> input >> num;

    Bangun *b = nullptr;

    if (input == 'L')
    {
      b = new Lingkaran(num);
    }
    else if (input == 'P')
    {
      b = new Persegi(num);
    }
    else if (input == 'K')
    {
      b = new Kubus(num);
    }
    else if (input == 'B')
    {
      b = new Bola(num);
    }

    totalLuas += b->hitungLuas();
    
    Bangun3D *b3d = dynamic_cast<Bangun3D *>(b);

    if (b3d != nullptr)
    {
      totalVolume += b3d->hitungVolume();
    }

    delete b;
  }

  cout << fixed << setprecision(2);
  cout << totalLuas << endl;
  cout << totalVolume << endl;

  return 0;
}