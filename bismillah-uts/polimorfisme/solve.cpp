#include <iostream>
#include <iomanip>
using namespace std;

class Bangun
{
public:
    virtual double hitungLuas() = 0;
};

class Bangun3d : public Bangun
{
public:
    virtual double hitungVolume() = 0;
};

class Persegi : public Bangun
{
private:
    double panjang;

public:
    Persegi(double p) : panjang(p) {};
    double hitungLuas() override
    {
        return panjang * panjang;
    }
};

class Lingkaran : public Bangun
{
private:
    double radius;

public:
    Lingkaran(double r) : radius(r) {};
    const double phi = 3.1425;
    double hitungLuas() override
    {
        return phi * radius * radius;
    }
};

class Kubus : Bangun3d
{
private:
    double panjang;

public:
    Kubus(double p) : panjang(p) {};
    double hitungLuas() override
    {
        return 6 * panjang * panjang;
    }
    double hitungVolume() override
    {
        return panjang * panjang * panjang;
    }
};

class Bola : public Bangun3d
{
private:
    double radius;

public:
    Bola(double r) : radius(r) {};
    const double phi = 3.1425;
    double hitungLuas() override
    {
        return 4 * phi * radius * radius;
    }
    double hitungVolume() override
    {
        return (4.0 / 3.0) * phi * radius * radius * radius;
    }
};

int main()
{
    int n;
    cin >> n;
    double total_luas;
    double total_volume;

    char tipe;
    double input;
    for (int i = 0; i < n; i++)
    {
        cin >> tipe >> input;
        if (tipe == 'L')
        {
            Lingkaran obj(input);
            total_luas += obj.hitungLuas();
        }
        else if (tipe == 'P')
        {
            Persegi obj(input);
            total_luas += obj.hitungLuas();
        }
        else if (tipe == 'K')
        {
            Kubus obj(input);
            total_luas += obj.hitungLuas();
            total_volume += obj.hitungVolume();
        }
        else if (tipe == 'B')
        {
            Bola obj(input);
            total_luas += obj.hitungLuas();
            total_volume += obj.hitungVolume();
        }
    }

    cout << fixed << setprecision(2);
    cout << total_luas << endl
         << total_volume << endl;
    return 0;
}