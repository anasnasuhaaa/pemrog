#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
  vector<int> populasi;
  vector<int> sample;

  int max;
  cin >> max;

  int x;
  while (cin >> x && x != -1)
  {
    populasi.push_back(x);
  }

  for (auto data : populasi)
  {
    if (data >= max)
    {
      sample.push_back(data);
    }
  }

  double avg = 0.00;
  for (auto data : sample)
  {
    avg += data;
  }

  if (!sample.empty())
  {
    avg /= sample.size();
  }

  double ragam = 0.00;
  for (auto data : sample)
  {
    ragam += (data - avg) * (data - avg);
  }

  if (!sample.empty())
  {
    ragam /= (sample.size() - 1);
  }

  cout << fixed << setprecision(2) << avg << " " << ragam << endl;

  return 0;
}
