#include <iostream>
#include <map>
#include <string>
using namespace std;

class Koleksi
{
public:
    string id;
    char jenis;
    int jumlah;
    int dipinjam = 0;

    Koleksi(string id, char jenis, int jumlah)
    {
        this->id = id;
        this->jenis = jenis;
        this->jumlah = jumlah;
    }
};

class Perpustakaan
{
private:
    map<string, Koleksi> koleksi;

public:
    void tambahKoleksi(string id, char j, int jum)
    {
        koleksi.emplace(id, Koleksi(id, j, jum));
    }

    void pinjamKoleksi(string id)
    {#include <iostream>
#include <map>
#include <string>
using namespace std;

class Koleksi
{
public:
    string id;
    char jenis;
    int jumlah;
    int dipinjam = 0;

    Koleksi(string id, char jenis, int jumlah)
    {
        this->id = id;
        this->jenis = jenis;
        this->jumlah = jumlah;
    }
};

class Perpustakaan
{
private:
    map<string, Koleksi> koleksi;

public:
    void tambahKoleksi(string id, char j, int jum)
    {
        koleksi.emplace(id, Koleksi(id, j, jum));
    }

    void pinjamKoleksi(string id)
    {
        if (koleksi.count(id) && koleksi.at(id).jumlah > 0)
        {
            koleksi.at(id).jumlah--;
            koleksi.at(id).dipinjam++;
            cout << "PEMINJAMAN " << id << " BERHASIL" << endl;
        }
        else
        {
            cout << "PEMINJAMAN " << id << " GAGAL" << endl;
        }
    }

    void kembaliKoleksi(string id)
    {
        if (koleksi.count(id) && koleksi.at(id).dipinjam > 0)
        {
            koleksi.at(id).jumlah++;
            koleksi.at(id).dipinjam--;
            cout << "PENGEMBALIAN " << id << endl;
        }
    }

    void listKoleksi()
    {
        int buku = 0, majalah = 0, karya_ilmiah = 0, jum_koleksi = 0, total = 0;
        for (auto &item : koleksi)
        {
            Koleksi &k = item.second;

            if (k.jenis == 'B')
                buku++;

            else if (k.jenis == 'M')
                majalah++;

            else if (k.jenis == 'K')
                karya_ilmiah++;

            jum_koleksi++;
            total += k.jumlah;
        }

        cout << "BANYAK KOLEKSI = " << jum_koleksi << " JUDUL "
             << "(BUKU = " << buku << ", MAJALAH = " << majalah
             << ", KARYA ILMIAH = " << karya_ilmiah << ", TOTAL = " << total << ")"
             << endl;
    }

    void tampilTambah(string id)
    {
        cout << "PENAMBAHAN KOLEKSI " << koleksi.at(id).id << " JUMLAH = " << koleksi.at(id).jumlah << endl;
    }
};

int main()
{
    int m, n;
    cin >> m >> n;

    Perpustakaan perpustakaan;
    for (int i = 0; i < m; i++)
    {
        string id;
        char jenis;
        int jumlah;

        cin >> id >> jenis >> jumlah;
        perpustakaan.tambahKoleksi(id, jenis, jumlah);
    }

    for (int i = 0; i < n; i++)
    {
        string mode;
        string id;
        cin >> mode;

        if (mode == "TAMBAH")
        {
            char jenis;
            int jumlah;

            cin >> id >> jenis >> jumlah;
            perpustakaan.tambahKoleksi(id, jenis, jumlah);
            perpustakaan.tampilTambah(id);
        }
        else if (mode == "KOLEKSI")
        {
            perpustakaan.listKoleksi();
        }
        else if (mode == "PINJAM")
        {
            cin >> id;
            perpustakaan.pinjamKoleksi(id);
        }
        else if (mode == "KEMBALI")
        {
            cin >> id;
            perpustakaan.kembaliKoleksi(id);
        }
    }

    return 0;
}
        if (koleksi.count(id) && koleksi.at(id).jumlah > 0)
        {
            koleksi.at(id).jumlah--;
            koleksi.at(id).dipinjam++;
            cout << "PEMINJAMAN " << id << " BERHASIL" << endl;
        }
        else
        {
            cout << "PEMINJAMAN " << id << " GAGAL" << endl;
        }
    }

    void kembaliKoleksi(string id)
    {
        if (koleksi.count(id) && koleksi.at(id).dipinjam > 0)
        {
            koleksi.at(id).jumlah++;
            koleksi.at(id).dipinjam--;
            cout << "PENGEMBALIAN " << id << endl;
        }
    }

    void listKoleksi()
    {
        int buku = 0, majalah = 0, karya_ilmiah = 0, jum_koleksi = 0, total = 0;
        for (auto &item : koleksi)
        {
            Koleksi &k = item.second;

            if (k.jenis == 'B')
                buku++;

            else if (k.jenis == 'M')
                majalah++;

            else if (k.jenis == 'K')
                karya_ilmiah++;

            jum_koleksi++;
            total += k.jumlah;
        }

        cout << "BANYAK KOLEKSI = " << jum_koleksi << " JUDUL "
             << "(BUKU = " << buku << ", MAJALAH = " << majalah
             << ", KARYA ILMIAH = " << karya_ilmiah << ", TOTAL = " << total << ")"
             << endl;
    }

    void tampilTambah(string id)
    {
        cout << "PENAMBAHAN KOLEKSI " << koleksi.at(id).id << " JUMLAH = " << koleksi.at(id).jumlah << endl;
    }
};

int main()
{
    int m, n;
    cin >> m >> n;

    Perpustakaan perpustakaan;
    for (int i = 0; i < m; i++)
    {
        string id;
        char jenis;
        int jumlah;

        cin >> id >> jenis >> jumlah;
        perpustakaan.tambahKoleksi(id, jenis, jumlah);
    }

    for (int i = 0; i < n; i++)
    {
        string mode;
        string id;
        cin >> mode;

        if (mode == "TAMBAH")
        {
            char jenis;
            int jumlah;

            cin >> id >> jenis >> jumlah;
            perpustakaan.tambahKoleksi(id, jenis, jumlah);
            perpustakaan.tampilTambah(id);
        }
        else if (mode == "KOLEKSI")
        {
            perpustakaan.listKoleksi();
        }
        else if (mode == "PINJAM")
        {
            cin >> id;
            perpustakaan.pinjamKoleksi(id);
        }
        else if (mode == "KEMBALI")
        {
            cin >> id;
            perpustakaan.kembaliKoleksi(id);
        }
    }

    return 0;
}