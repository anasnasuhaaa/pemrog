#include <iostream>

int main()
{
  int x;
  std::cout << "Enter the number: ";
  std::cin >> x;

  int array[x];

  for (int i = 0; i < x; i++)
  {
    array[i] = i + 1;
  }

  for (int i = 0; i < x; i++)
  {
    std::cout << array[i] << " ";
  }

  return 0;
}