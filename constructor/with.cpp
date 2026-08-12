#include <iostream>
#include <string>
using namespace std;

class Animal
{

private:
  string name;
  int age;

public:
  Animal()
  {
    name = "Anjing";
    age = 2;
  }

  string getName()
  {
    return name;
  }
  int getAge()
  {
    return age;
  }
};

int main()
{
  Animal animal;

  cout << animal.getName() << endl;
  cout << animal.getAge() << endl;

  return 0;
}