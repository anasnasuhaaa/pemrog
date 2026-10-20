#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Persegi
{
private:
    int panjang;
    int lebar;
public:
    Persegi(int p, int l) : panjang(p), lebar(l) {};
    int hitungLuas()
    {
        return panjang * lebar;
    }
};

int main()
{
    int s, n;
    cin >> s >> n;

    vector<int> tampung_luas;
    int panjang, lebar;

    for (int i = 0; i < s; i++)
    {
        cin >> panjang >> lebar;
        Persegi P(panjang, lebar);
        tampung_luas.push_back(P.hitungLuas());
    }

    sort(tampung_luas.begin(), tampung_luas.end());
    for (int i = 0; i < n; i++)
    {
        cout << tampung_luas[i] << endl;
    }

    return 0;
}