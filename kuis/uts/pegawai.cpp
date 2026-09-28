#include <bits/stdc++.h>
using namespace std;

class Pegawai
{
protected:
    string id;
    int usia, tipe, income;

public:
    Pegawai() : id(""), usia(0), tipe(1), income(0) {}

    string getID() const
    {
        return id;
    }

    void show() const
    {
        cout << id << " " << tipe << " " << income << endl;
    }
};

class PegawaiTetap : public Pegawai
{
private:
    int gaji_pokok, uang_lembur;

public:
    PegawaiTetap() : Pegawai(), gaji_pokok(0), uang_lembur(0) {}

    void setPegawaiTetap(string id_pegawai, int usia_pegawai, int gaji)
    {
        id = id_pegawai;
        usia = usia_pegawai;
        tipe = 1;
        gaji_pokok = gaji;
        income = gaji_pokok;
    }

    void setUangLembur(int ulembur)
    {
        uang_lembur = ulembur;
        income += uang_lembur;
    }
};

class PegawaiHarian : public Pegawai
{
private:
    int upah;

public:
    PegawaiHarian() : Pegawai(), upah(0) {}

    void setPegawaiHarian(string id_pegawai, int usia_pegawai)
    {
        id = id_pegawai;
        usia = usia_pegawai;
        tipe = 2;
    }

    void setUpah(int u)
    {
        upah = u;
        income = upah;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<PegawaiTetap> pt;
    vector<PegawaiHarian> ph;

    // Input data pegawai
    for (int i = 0; i < n; i++)
    {
        string id;
        int usia, tipe, gaji;

        cin >> id >> usia >> tipe;

        if (tipe == 1)
        {
            cin >> gaji;

            pt.emplace_back();
            pt.back().setPegawaiTetap(id, usia, gaji);
        }
        else if (tipe == 2)
        {
            ph.emplace_back();
            ph.back().setPegawaiHarian(id, usia);
        }
    }

    // Input tambahan penghasilan
    string id;
    int upah;

    while (cin >> id && id != "END")
    {
        cin >> upah;

        for (auto &p : pt)
        {
            if (p.getID() == id)
            {
                p.setUangLembur(upah);
                break;
            }
        }

        for (auto &p : ph)
        {
            if (p.getID() == id)
            {
                p.setUpah(upah);
                break;
            }
        }
    }

    // Output pegawai tetap
    for (const auto &p : pt)
    {
        p.show();
    }

    // Output pegawai harian
    for (const auto &p : ph)
    {
        p.show();
    }

    return 0;
}