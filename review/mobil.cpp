#include <bits/stdc++.h>
using namespace std;
class Kendaraan
{
public:
  virtual void info() = 0;
  virtual ~Kendaraan() = default;
};

class Mobil : public Kendaraan
{
public:
  void info()
  {
    cout << "Mobil berjalan dengan 4 roda" << endl;
  }
};

class Motor : public Kendaraan
{
public:
  void info()
  {
    cout << "Motor berjalan dengan 2 roda" << endl;
  }
};

int main()
{
  Kendaraan *k1 = new Mobil();
  Kendaraan *k2 = new Motor();

  k1->info();
  k2->info();

  delete k1;
  delete k2;
  
  return 0;
}