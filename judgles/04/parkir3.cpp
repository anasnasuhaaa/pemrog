#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Kendaraan {
protected:
    string nomorPlat;
    string jenisKendaraan;
    int jamMasuk;
    int jamKeluar;

public:
    Kendaraan(const string& plat, const string& jenis, int masuk, int keluar)
        : nomorPlat(plat), jenisKendaraan(jenis),
          jamMasuk(masuk), jamKeluar(keluar) {}

    virtual ~Kendaraan() = default;

    int hitungDurasi() {
        return jamKeluar - jamMasuk;
    }

    virtual double hitungTarif() {
        return 0.0;
    }

    virtual void tampilkanInfo() {
        cout << "Nomor Plat      : " << nomorPlat << '\n'
             << "Jenis Kendaraan : " << jenisKendaraan << '\n'
             << "Durasi Parkir   : " << hitungDurasi() << " Jam ("
             << setfill('0') << setw(2) << jamMasuk << ":00 - "
             << setw(2) << jamKeluar << ":00)"
             << setfill(' ') << '\n';
    }
};

class Mobil : public Kendaraan {
private:
    int kapasitasPenumpang;

public:
    Mobil(const string& plat, const string& jenis, int kapasitas,
          int masuk, int keluar)
        : Kendaraan(plat, jenis, masuk, keluar),
          kapasitasPenumpang(kapasitas) {}

    double hitungTarif() override {
        const int durasi = hitungDurasi();
        if (durasi <= 1) {
            return 5000.0;
        }
        return 5000.0 + (durasi - 1) * 3000.0;
    }

    void tampilkanInfo() override {
        cout << "Kendaraan       : Mobil\n";
        Kendaraan::tampilkanInfo();
        cout << "Kapasitas       : " << kapasitasPenumpang << " Penumpang\n"
             << "Total Tarif     : Rp "
             << fixed << setprecision(0) << hitungTarif() << '\n';
    }
};

class Motor : public Kendaraan {
private:
    string jenisMotor;

public:
    Motor(const string& plat, const string& jenis, const string& tipe,
          int masuk, int keluar)
        : Kendaraan(plat, jenis, masuk, keluar), jenisMotor(tipe) {}

    double hitungTarif() override {
        const int durasi = hitungDurasi();
        if (durasi <= 1) {
            return 2000.0;
        }
        return 2000.0 + (durasi - 1) * 1000.0;
    }

    void tampilkanInfo() override {
        cout << "Kendaraan       : Motor\n";
        Kendaraan::tampilkanInfo();
        cout << "Tipe Motor      : " << jenisMotor << '\n'
             << "Total Tarif     : Rp "
             << fixed << setprecision(0) << hitungTarif() << '\n';
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    vector<Kendaraan*> kendaraan;

    for (int i = 0; i < n; ++i) {
        string kategori, plat, jenis;
        cin >> kategori >> plat >> jenis;

        if (kategori == "Mobil") {
            int kapasitas, masuk, keluar;
            cin >> kapasitas >> masuk >> keluar;
            kendaraan.push_back(new Mobil(plat, jenis, kapasitas, masuk, keluar));
        } else if (kategori == "Motor") {
            string tipe;
            int masuk, keluar;
            cin >> tipe >> masuk >> keluar;
            kendaraan.push_back(new Motor(plat, jenis, tipe, masuk, keluar));
        }
    }

    for (size_t i = 0; i < kendaraan.size(); ++i) {
        if (i > 0) {
            cout << '\n';
        }
        cout << "--- DATA PARKIR KENDARAAN " << i + 1 << " ---\n";
        kendaraan[i]->tampilkanInfo();
    }

    for (Kendaraan* objek : kendaraan) {
        delete objek;
    }

    return 0;
}
