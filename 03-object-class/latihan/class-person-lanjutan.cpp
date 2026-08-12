#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
class Person
{
private:
  string nama;
  int usia;
  int tinggi;
  double berat;

public:
  // Constructor
  Person()
  {
    nama = "";
    usia = 0;
    tinggi = 0;
    berat = 0.0;
  }

  // Setter / Mutator
  void setPerson(string nm, int u, int t, double b)
  {
    nama = nm;
    usia = u;
    tinggi = t;
    berat = b;
  }

  // Getter / Accessor
  string getNama()
  {
    return nama;
  }
  int getUsia()
  {
    return usia;
  }
  int getTinggi()
  {
    return tinggi;
  }

  // protected:
  double getBerat()
  {
    return berat;
  }
  double getIMT()
  {
    return berat / ((tinggi / 100.0) * (tinggi / 100.0));
  }
  string getStatusGizi(double imt)
  {
    if (imt >= 28.0)
    {
      return "sangat gemuk";
    }
    else if (imt >= 25.0 && imt < 28.0)
    {
      return "gemuk";
    }
    else if (imt >= 18.5 && imt < 25.0)
    {
      return "normal";
    }
    else if (imt >= 17.0 && imt < 18.5)
    {
      return "kurus";
    }
    else
    {
      return "sangat kurus";
    }
  }
};

int main()
{
  Person p[100];
  int n;
  cin >> n;

  string nama;
  int usia;
  int tinggi;
  double berat;

  for (int i = 0; i < n; i++)
  {
    cin >> nama >> usia >> tinggi >> berat;
    p[i].setPerson(nama, usia, tinggi, berat);
  }

  double imt;
  for (int i = 0; i < n; i++)
  {
    imt = p[i].getIMT();

    cout << p[i].getNama() << " "
         << p[i].getUsia() << " "
         << p[i].getTinggi() << " "
         << fixed << setprecision(2) << p[i].getBerat() << " "
         << fixed << setprecision(2) << imt << " "
         << p[i].getStatusGizi(imt) << endl;
  }

  double avgHeight = 0.00;
  for (int i = 0; i < n; i++)
  {
    avgHeight += p[i].getTinggi();
  }
  avgHeight /= n;

  cout << fixed << setprecision(2) << avgHeight << endl;

  int count_overAvgHeight = 0;
  for (int i = 0; i < n; i++)
  {
    if (p[i].getTinggi() > avgHeight)
    {
      count_overAvgHeight++;
    }
  }
  cout << count_overAvgHeight << endl;

  int count_sk = 0, count_k = 0, count_n = 0, count_g = 0, count_sg = 0;
  for (int i = 0; i < n; i++)
  {
    double imt = p[i].getIMT();
    if (imt >= 28.0)
    {
      count_sg++;
    }
    else if (imt >= 25.0 && imt < 28.0)
    {
      count_g++;
    }
    else if (imt >= 18.5 && imt < 25.0)
    {
      count_n++;
    }
    else if (imt >= 17.0 && imt < 18.5)
    {
      count_k++;
    }
    else
    {
      count_sk++;
    }
  }

  cout << count_sk << " "
       << count_k << " "
       << count_n << " "
       << count_g << " "
       << count_sg << " "
       << endl;
  return 0;
}