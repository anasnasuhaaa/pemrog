#include <iostream>

int main()
{
  int *dynArr = new int[1];

  for (int i = 0; i < 4; i++)
  {
    dynArr[i] = i * 10;
  }
  int arr[3] = {1, 2, 3};
  std::cout << sizeof(arr) << std::endl;
  std::cout << sizeof(dynArr);
  // for (int i = 0; i < 5; i++)
  // {
  //   std::cout << dynArr[i] << " ";
  // }

  delete[] dynArr;
  return 0;
}