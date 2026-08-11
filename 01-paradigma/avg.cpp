#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int n, k;
  cin >> n;
  cin >> k;

  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  float avg = 0.00;
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    if ((i + 1) % k == 0)
    {
      avg += arr[i];
      count++;
    }
  }

  avg /= count;
  cout << fixed << setprecision(2);
  cout << avg << endl;

  return 0;
}