#include <iostream>
using namespace std;

class Counter
{
private:
  int count;

public:
  Counter()
  {
    count = 0;
  }

  void set(int p)
  {
    if (p >= 0)
    {
      count = p;
    }
  }
  void inc()
  {
    count++;
  }
  void dec()
  {
    if (count > 0)
    {
      count--;
    };
  }
  void print()
  {
    cout << count << endl;
  }
};

int main()
{
  Counter counter;
  int num;

  while (cin >> num && num != -9)
  {
    if (num == 0)
    {
      int numSet;
      cin >> numSet;
      counter.set(numSet);
    }
    else if (num == 1)
    {
      counter.inc();
    }
    else if (num == -1)
    {
      counter.dec();
    }
    else if (num == 9)
    {
      counter.print();
    }
  }

  return 0;
}