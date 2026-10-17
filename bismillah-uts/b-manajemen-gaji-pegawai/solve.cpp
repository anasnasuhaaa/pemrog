#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Pegawai
{
protected:
    string identitas_pegawai;

public:
    Pegawai(string i) : identitas_pegawai(i) {};
    virtual int gaji_bulanan() = 0;
    virtual ~Pegawai() = default;
    string getIdentitasPegawai()
    {
        return identitas_pegawai;
    }
};

class PegawaiTetap : public Pegawai
{
private:
    int gaji_pokok;
    int tunjangan;

public:
    PegawaiTetap(string id, int gp, int tj) : Pegawai(id), gaji_pokok(gp), tunjangan(tj) {};
    int gaji_bulanan() override
    {
        return gaji_pokok + tunjangan;
    }
};

class PegawaiHarian : public Pegawai
{
private:
    int jam_kerja;

public:
    PegawaiHarian(string id, int jk) : Pegawai(id), jam_kerja(jk) {};
    int gaji_bulanan() override
    {
        if (jam_kerja <= 200)
        {
            return jam_kerja * 1000;
        }
        else if (jam_kerja <= 250)
        {
            return (1000 * 200) + (1500 * (jam_kerja - 200));
        }
        else
        {
            return 200 * 1000 + 50 * 1500;
        }
    }
};

int main()
{
    int n;
    cin >> n;

    int tipe;
    int gaji_pokok, tunjangan, jam_kerja;
    string id;

    Pegawai *p[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> tipe;
        if (tipe == 1)
        {
            cin >> id >> gaji_pokok >> tunjangan;
            p[i] = new PegawaiTetap(id, gaji_pokok, tunjangan);
        }
        else if (tipe == 0)
        {
            cin >> id >> jam_kerja >> tunjangan;
            p[i] = new PegawaiHarian(id, jam_kerja);
        }
    }

    double avg_gaji = 0.0;
    int max_gaji = -1;
    string id_max_gaji;

    for (int i = 0; i < n; i++)
    {
        int gaji = p[i]->gaji_bulanan();
        avg_gaji += gaji;

        if (gaji > max_gaji)
        {
            max_gaji = gaji;
            id_max_gaji = p[i]->getIdentitasPegawai();
        }
    }

    avg_gaji /= n;
    cout << fixed << setprecision(2);
    cout << "Rata-rata: " << avg_gaji << endl
         << "Gaji Tertinggi: " << max_gaji << endl
         << id_max_gaji << endl;

    for (int i = 0; i < n; i++)
        delete p[i];

    return 0;
}