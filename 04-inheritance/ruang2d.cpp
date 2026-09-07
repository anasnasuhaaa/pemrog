#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

// BASE CLASS
class Ruang2d
{
protected:
  int x1, y1;
public:
  Ruang2d() : x1(0), y1(0) {};
};

// INHERITANCE SEGI EMPAT
class SegiEmpat : public Ruang2d
{
private:
  int x2, y2;

public:
  SegiEmpat() : Ruang2d(), x2(0), y2(0) {};
  void setSegiEmpat(int x_1, int y_1, int x_2, int y_2)
  {
    x1 = x_1;
    y1 = y_1;
    x2 = x_2;
    y2 = y_2;
  }
  double luas()
  {
    int result = (x2 - x1) * (y2 - y1);
    return abs(result);
  }
};

// INHERITANCE SEGI LINGKARAN
class Linkarang : public Ruang2d
{
private:
  int radius;

public:
  void setLingkaran(int x_1, int y_1, int r)
  {
    x1 = x_1;
    y1 = y_1;
    radius = r;
  }
  double luas()
  {
    return 3.14 * radius * radius;
  }
};

int main()
{
  string input;
  double count_segi_empat = 0.0;
  double count_linkaran = 0.0;

  int x_1, x_2, y_1, y_2, r;

  while (cin >> input && input != "X")
  {
    if (input == "S" || input == "s")
    {
      cin >> x_1 >> x_2 >> y_1 >> y_2;
      SegiEmpat segi;
      segi.setSegiEmpat(x_1, x_2, y_1, y_2);
      count_segi_empat += segi.luas();
    }
    else if (input == "L" || input == "l")
    {
      cin >> x_1 >> x_2 >> r;
      Linkarang lin;
      lin.setLingkaran(x_1, x_2, r);
      count_linkaran += lin.luas();
    }
  };

  cout << "Segiempat: " << fixed << setprecision(2) << count_segi_empat << endl
       << "Linkaran: " << fixed << setprecision(2) << count_linkaran << endl;

  return 0;
}