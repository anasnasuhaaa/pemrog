#include <bits/stdc++.h>
using namespace std;

class PersegiPanjang
{
private:
    double panjang;
    double lebar;

public:
    PersegiPanjang(double p, double l) : panjang(p), lebar(l) {};
    double luas()
    {
        return panjang * lebar;
    }
    double keliling()
    {
        return 2 * (panjang + lebar);
    }
};

int main()
{
    int n;
    cin >> n;

    vector<double> tampung_luas;
    vector<double> tampung_keliling;

    double p, l;

    for (int i = 0; i < n; i++)
    {
        cin >> p >> l;
        PersegiPanjang P(p, l);

        tampung_luas.push_back(P.luas());
        tampung_keliling.push_back(P.keliling());
    }

    for (int i = 0; i < n; i++)
    {
        cout << fixed << setprecision(2) << 
        tampung_luas[i] << " " << 
        tampung_keliling[i] << endl;
    }

    return 0;
}