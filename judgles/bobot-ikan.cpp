#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    double m;
    cin >> n >> m;
    
    vector<double> ikan(n);

    for (int i = 0; i < n; i++)
    {
        cin >> ikan[i];
    }
    sort(ikan.begin(), ikan.end(), greater<double>());

    double total = 0;
    int jumlah = 0;
// [30, 20, 10]
    for (double bobot : ikan)
    {
        total += bobot;
        jumlah++;
        if (total >= m)
        {
            cout << jumlah << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}