#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int_fast64_t number;
  double rata = 0.00;

  for (int i = 0; i < 4; i++)
  {
    cin >> number;
    rata += number;
  }
  rata /= 4;

  cout << fixed << setprecision(2) << rata << endl;
  return 0;
}