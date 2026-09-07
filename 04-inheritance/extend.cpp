#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Person
{

protected:
  string name;
  int age;

public:
  Person() : name(""), age(0) {}
  void setPerson(string nm, int ag)
  {
    name = nm;
    age = ag;
  }
  void getName()
  {
    cout << "Nama kamu adalah: " << name << endl;
  }
};

class Mahasiswa : public Person
{
private:
  float ipk;

public:
  Mahasiswa() : Person(), ipk(0.0f) {}

  void setIpk(float p)
  {
    ipk = p;
  }
  void getData()
  {
    cout << "Nama: " << name << endl
         << "Age: " << age << endl
         << "IPK: " << fixed << setprecision(2) << ipk << endl;
  }
};

int main()
{
  Mahasiswa m1;
  m1.setPerson("anas", 20);
  m1.setIpk(4.00);
  m1.getData();
  return 0;
}