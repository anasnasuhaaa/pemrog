#include <iostream>
#include <iomanip>
using namespace std;
class Orang
{
private:
  string nama;
  int usia;
  double tinggi, berat;

public:

  Orang()
  {
    nama = "";
    usia = 0;
    tinggi = 0.0;
    berat = 0.0;
  }

  void setOrang(string nm, int us, double tg, double br)
  {
    nama = nm;
    usia = us;
    tinggi = tg;
    berat = br;
  }
  void show()
  {
    cout << nama << " | "
         << usia << " | "
         << fixed << setprecision(2) << tinggi << " | "
         << fixed << setprecision(2) << berat << endl;
  }
};

int main()
{
  Orang orang1;

  string name;
  getline(cin, name);

  int usia;
  cin >> usia;

  double tinggi;
  cin >> tinggi;

  double berat;
  cin >> berat;

  orang1.setOrang(name, usia, tinggi, berat);
  orang1.show();

  return 0;
}