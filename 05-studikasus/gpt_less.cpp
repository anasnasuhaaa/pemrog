#include <iostream>
#include <vector>
using namespace std;

// Abstract class
class Karyawan {
protected:
    string id;
    string nama;

public:
    Karyawan(string id, string nama) {
        this->id = id;
        this->nama = nama;
    }

    virtual double hitungGajiTotal() = 0;

    void tampilkanData() {
        cout << "ID   : " << id << endl;
        cout << "Nama : " << nama << endl;
    }

    virtual ~Karyawan() {}
};

// ================= Karyawan Tetap =================
class KaryawanTetap : public Karyawan {
private:
    double gajiPokok;
    double tunjanganJabatan;
    double bonusKinerja;

public:
    KaryawanTetap(string id, string nama,
                  double gajiPokok,
                  double tunjanganJabatan,
                  double bonusKinerja)
        : Karyawan(id, nama) {
        this->gajiPokok = gajiPokok;
        this->tunjanganJabatan = tunjanganJabatan;
        this->bonusKinerja = bonusKinerja;
    }

    double hitungGajiTotal() override {
        return gajiPokok + tunjanganJabatan + bonusKinerja;
    }
};

// ================= Karyawan Kontrak =================
class KaryawanKontrak : public Karyawan {
private:
    double nilaiKontrakTahunan;
    double tunjanganProyek;

public:
    KaryawanKontrak(string id, string nama,
                    double nilaiKontrakTahunan,
                    double tunjanganProyek)
        : Karyawan(id, nama) {
        this->nilaiKontrakTahunan = nilaiKontrakTahunan;
        this->tunjanganProyek = tunjanganProyek;
    }

    double hitungGajiTotal() override {
        return (nilaiKontrakTahunan / 12) + tunjanganProyek;
    }
};

// ================= Karyawan Harian =================
class KaryawanHarian : public Karyawan {
private:
    double upahHarian;
    int hariHadir;
    double insentifLembur;

public:
    KaryawanHarian(string id, string nama,
                   double upahHarian,
                   int hariHadir,
                   double insentifLembur)
        : Karyawan(id, nama) {
        this->upahHarian = upahHarian;
        this->hariHadir = hariHadir;
        this->insentifLembur = insentifLembur;
    }

    double hitungGajiTotal() override {
        return (upahHarian * hariHadir) + insentifLembur;
    }
};

int main() {
    KaryawanTetap tetap(
        "K001", "Andi",
        5000000, 1000000, 500000
    );

    KaryawanKontrak kontrak(
        "K002", "Budi",
        60000000, 1000000
    );

    KaryawanHarian harian(
        "K003", "Caca",
        200000, 20, 500000
    );

    vector<Karyawan*> daftarKaryawan = {
        &tetap,
        &kontrak,
        &harian
    };

    double totalSemuaGaji = 0;

    for (Karyawan* karyawan : daftarKaryawan) {
        karyawan->tampilkanData();

        double gaji = karyawan->hitungGajiTotal();

        cout << "Gaji : Rp " << gaji << endl;
        cout << endl;

        totalSemuaGaji += gaji;
    }

    cout << "Total seluruh gaji: Rp "
         << totalSemuaGaji << endl;

    return 0;
}