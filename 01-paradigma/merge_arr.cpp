#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> arr1;
  vector<int> arr2;
  int num;

  while (cin >> num && num != -9)
  {
    arr1.push_back(num);
  }
  while (cin >> num && num != -9)
  {
    arr2.push_back(num);
  }

  int x = 0, y = 0;
  while (x < arr1.size() && y < arr2.size())
  {
    if (arr1[x] < arr2[y])
    {
      cout << arr1[x] << " ";
      x++;
    }
    else
    {
      cout << arr2[y] << " ";
      y++;
    }
  }

  while (x < arr1.size())
  {
    cout << arr1[x] << " ";
    x++;
  }
  while (y < arr2.size())
  {
    cout << arr2[y] << " ";
    y++;
  }

  return 0;
}