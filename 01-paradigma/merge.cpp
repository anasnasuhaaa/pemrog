#include <iostream>
#include <vector>

int main()
{
  std::vector<int> arr1;
  std::vector<int> arr2;

  int num;
  while (std::cin >> num && num != -9)
  {
    arr1.push_back(num);
  }
  while (std::cin >> num && num != -9)
  {
    arr2.push_back(num);
  }

  int x = 0, y = 0;
  while (x < arr1.size() && y < arr2.size())
  {
    if (arr1[x] < arr2[y])
    {
      std::cout << arr1[x] << " ";
      x++;
    }
    else
    {
      std::cout << arr2[y] << " ";
      y++;
    }
  }

  while (x < arr1.size())
  {
    std::cout << arr1[x] << " ";
    x++;
  }

  while (y < arr2.size())
  {
    std::cout << arr2[y] << " ";
    y++;
  }

  return 0;
}