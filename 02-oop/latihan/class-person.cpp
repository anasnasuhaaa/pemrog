#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Person
{
private:
  string name;
  int age;
  int height;
  double weight;

public:
  // Constructor
  Person()
  {
    name = "";
    age = 0;
    height = 0;
    weight = 0.0;
  }

  // Setter
  void set(string pName, int pAge, int pHeight, float pWeight)
  {
    name = pName;
    age = pAge;
    height = pHeight;
    weight = pWeight;
  }

  // Getter
  string getName()
  {
    return name;
  }
  int getAge()
  {
    return age;
  }
  int getHeight()
  {
    return height;
  }
  double getWeight()
  {
    return weight;
  }
};

int main()
{
  Person p[100];
  int n;
  cin >> n;

  string name;
  int age;
  int height;
  double weight;

  for (int i = 0; i < n; i++)
  {
    cin >> name >> age >> height >> weight;
    p[i].set(name, age, height, weight);
  }

  for (int i = 0; i < n; i++)
  {
    cout << p[i].getName() << " " << p[i].getAge() << endl;
  }

  double avgHeight = 0.00;
  for (int i = 0; i < n; i++)
  {
    avgHeight += p[i].getHeight();
  }
  avgHeight /= n;

  cout << fixed << setprecision(2) << avgHeight << endl;

  int count_overAvgHeight = 0;
  for (int i = 0; i < n; i++)
  {
    if (p[i].getHeight() > avgHeight)
    {
      count_overAvgHeight++;
    }
  }
  cout << count_overAvgHeight << endl;

  return 0;
}