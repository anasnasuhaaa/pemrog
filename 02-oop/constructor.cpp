#include <iostream>
using namespace std;
// Constructor adalah fungsi yang otomatis diakses pada saat instansiasi.

// Nama fungsi constructor sama dengan nama class.
// Sering menggunakan konsep function overloading.

class myClass
{
private:
  int a, b;

public:
  myClass() { a = b = 0; } // Default Constructor
  myClass(int p1, int p2)
  {
    a = p1;
    b = p2;
  }

  void set(int p1, int p2)
  {
    a = p1;
    b = p2;
  }
  void setA(int p)
  {
    a = p;
  }
  void setB(int p)
  {
    b = p;
  }
  int sum()
  {
    return a + b;
  }
  int min()
  {
    return a - b;
  }
};

int main()
{
  myClass myObj;
  // myObj.set(10, 10);

  cout << myObj.sum() << endl;
  cout << myObj.min() << endl;

  // myObj.setA(50);
  // myObj.setB(40);

  cout << myObj.sum() << endl;
  cout << myObj.min() << endl;

  return 0;
}