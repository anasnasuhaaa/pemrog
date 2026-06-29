#include <iostream>
#include <iomanip>

int main()
{
  int n;
  int k;
  std::cin >> n;
  std::cin >> k;

  int arr[n];
  for (int i = 0; i < n; i++)
  {
    std::cin >> arr[i];
  }

  float avg = 0.00;
  int count = 0;
  for (int i = 1; i <= n; i++)
  {
    if (i % 2 == 0)
    {
      avg += arr[i - 1];
      count++;
    }
  }

  avg /= count;
  std::cout << std::fixed << std::setprecision(2);
  std::cout << avg << std::endl;
  return 0;
}