#include <iostream>

int main()
{

  class MyClass
  {
  private:
    int a;
    int b;

  public:
    void setA(int p)
    {
      a = p;
    }
    void setB(int p)
    {
      b = p;
    }
  };

  return 0;
}