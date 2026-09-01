#include <iostream>
using namespace std;

class MinumanKemasan
{
  
private:
  string namaProduk;
  int kapasitas;
  int isiSekarang;

public:
  MinumanKemasan()
  {
    namaProduk = "";
    kapasitas = 0;
    isiSekarang = kapasitas;
  }

  void setMinumanKemasan(string np, int kap)
  {
    namaProduk = np;
    kapasitas = kap;
    isiSekarang = kap;
  }

  void minum(int jum)
  {
    isiSekarang = isiSekarang - jum;
    if (isiSekarang < 0)
    {
      isiSekarang = 0;
    }
  }

  void isiUlang(int jum)
  {
    isiSekarang = isiSekarang + jum;
    if (isiSekarang > kapasitas)
    {
      isiSekarang = kapasitas;
    }
  }

  void show()
  {
    cout << "Nama Produk : " << namaProduk << endl
         << "Kapasitas   : " << kapasitas << " ml" << endl
         << "Isi Sekarang: " << isiSekarang << " ml"
         << endl;
  }
};

int main()
{
  MinumanKemasan minuman;

  string namaProduk;
  int kapasitas;

  string bhv;
  int jum;

  cin >> namaProduk;
  cin >> kapasitas;

  minuman.setMinumanKemasan(namaProduk, kapasitas);

  while (cin >> bhv && bhv != "show")
  {
    cin >> jum;

    if (bhv == "minum")
    {
      minuman.minum(jum);
    }
    else if (bhv == "isi")
    {
      minuman.isiUlang(jum);
    }
  }
  minuman.show();

  return 0;
}