#include <iostream>
#include <algorithm>
using namespace std;

class Persegi
{
private:
  int p, l;

public:
  Persegi() : p(0), l(0) {};
  void setPersegi(int panjang, int lebar)
  {
    p = panjang;
    l = lebar;
  }
  int luas()
  {
    return p * l;
  }
};

int main()
{
  int n, k, panjang, lebar;
  cin >> n >> k;

  int data_luas[n];
  Persegi p[n];

  for (int i = 0; i < n; i++)
  {
    cin >> panjang >> lebar;
    p[i].setPersegi(panjang, lebar);
    data_luas[i] = p[i].luas();
  }
  sort(data_luas, data_luas + n);
  for (int i = 0; i < k; i++)
  {
    cout << data_luas[i] << endl;
  }

  return 0;
}