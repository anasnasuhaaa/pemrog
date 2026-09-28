#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>
#include <stdexcept>
#include <limits>

using namespace std;

// ======================================================
// ABSTRACT CLASS: Karyawan
// ======================================================
class Karyawan {
protected:
    string id;
    string nama;

    // Digunakan oleh subclass untuk validasi nominal
    static void validasiNominal(double nilai, const string& namaAtribut) {
        if (nilai < 0) {
            throw invalid_argument(
                namaAtribut + " tidak boleh bernilai negatif."
            );
        }
    }

public:
    Karyawan(const string& id, const string& nama)
        : id(id), nama(nama) {}

    string getId() const {
        return id;
    }

    string getNama() const {
        return nama;
    }

    void setId(const string& idBaru) {
        if (idBaru.empty()) {
            throw invalid_argument("ID tidak boleh kosong.");
        }

        id = idBaru;
    }

    void setNama(const string& namaBaru) {
        if (namaBaru.empty()) {
            throw invalid_argument("Nama tidak boleh kosong.");
        }

        nama = namaBaru;
    }

    // Pure virtual function
    // Membuat Karyawan menjadi abstract class
    virtual double hitungGajiTotal() const = 0;

    // Destructor dibuat virtual karena class akan digunakan
    // melalui pointer ke superclass Karyawan
    virtual ~Karyawan() = default;
};


// ======================================================
// KARYAWAN TETAP
// ======================================================
class KaryawanTetap : public Karyawan {
private:
    double gajiPokok;
    double tunjanganJabatan;
    double bonusKinerja;

public:
    KaryawanTetap(
        const string& id,
        const string& nama,
        double gajiPokok,
        double tunjanganJabatan,
        double bonusKinerja
    ) : Karyawan(id, nama) {

        setGajiPokok(gajiPokok);
        setTunjanganJabatan(tunjanganJabatan);
        setBonusKinerja(bonusKinerja);
    }

    void setGajiPokok(double gajiPokokBaru) {
        validasiNominal(gajiPokokBaru, "Gaji pokok");
        gajiPokok = gajiPokokBaru;
    }

    void setTunjanganJabatan(double tunjanganBaru) {
        validasiNominal(tunjanganBaru, "Tunjangan jabatan");
        tunjanganJabatan = tunjanganBaru;
    }

    void setBonusKinerja(double bonusBaru) {
        validasiNominal(bonusBaru, "Bonus kinerja");
        bonusKinerja = bonusBaru;
    }

    double getGajiPokok() const {
        return gajiPokok;
    }

    double getTunjanganJabatan() const {
        return tunjanganJabatan;
    }

    double getBonusKinerja() const {
        return bonusKinerja;
    }

    // Method overriding
    double hitungGajiTotal() const override {
        return gajiPokok
             + tunjanganJabatan
             + bonusKinerja;
    }
};


// ======================================================
// KARYAWAN KONTRAK
// ======================================================
class KaryawanKontrak : public Karyawan {
private:
    double nilaiKontrakTahunan;
    double tunjanganPenyelesaianProyek;

public:
    KaryawanKontrak(
        const string& id,
        const string& nama,
        double nilaiKontrakTahunan,
        double tunjanganPenyelesaianProyek
    ) : Karyawan(id, nama) {

        setNilaiKontrakTahunan(nilaiKontrakTahunan);
        setTunjanganPenyelesaianProyek(
            tunjanganPenyelesaianProyek
        );
    }

    void setNilaiKontrakTahunan(double nilaiBaru) {
        validasiNominal(nilaiBaru, "Nilai kontrak tahunan");
        nilaiKontrakTahunan = nilaiBaru;
    }

    void setTunjanganPenyelesaianProyek(double tunjanganBaru) {
        validasiNominal(
            tunjanganBaru,
            "Tunjangan penyelesaian proyek"
        );

        tunjanganPenyelesaianProyek = tunjanganBaru;
    }

    double getNilaiKontrakTahunan() const {
        return nilaiKontrakTahunan;
    }

    double getTunjanganPenyelesaianProyek() const {
        return tunjanganPenyelesaianProyek;
    }

    // Method overriding
    double hitungGajiTotal() const override {
        return (nilaiKontrakTahunan / 12.0)
             + tunjanganPenyelesaianProyek;
    }
};


// ======================================================
// KARYAWAN HARIAN
// ======================================================
class KaryawanHarian : public Karyawan {
private:
    double upahHarian;
    int totalHariHadir;
    double insentifLembur;

public:
    KaryawanHarian(
        const string& id,
        const string& nama,
        double upahHarian,
        int totalHariHadir,
        double insentifLembur
    ) : Karyawan(id, nama) {

        setUpahHarian(upahHarian);
        setTotalHariHadir(totalHariHadir);
        setInsentifLembur(insentifLembur);
    }

    void setUpahHarian(double upahBaru) {
        validasiNominal(upahBaru, "Upah harian");
        upahHarian = upahBaru;
    }

    void setTotalHariHadir(int hariBaru) {
        if (hariBaru < 0) {
            throw invalid_argument(
                "Total hari hadir tidak boleh negatif."
            );
        }

        totalHariHadir = hariBaru;
    }

    void setInsentifLembur(double insentifBaru) {
        validasiNominal(
            insentifBaru,
            "Insentif lembur"
        );

        insentifLembur = insentifBaru;
    }

    double getUpahHarian() const {
        return upahHarian;
    }

    int getTotalHariHadir() const {
        return totalHariHadir;
    }

    double getInsentifLembur() const {
        return insentifLembur;
    }

    // Method overriding
    double hitungGajiTotal() const override {
        return (upahHarian * totalHariHadir)
             + insentifLembur;
    }
};


// ======================================================
// DRIVER
// ======================================================
int main() {

    vector<unique_ptr<Karyawan>> daftarKaryawan;

    int n;

    cout << "========================================\n";
    cout << "     SISTEM MANAJEMEN SDM PT ABC TECH\n";
    cout << "========================================\n";

    cout << "Masukkan jumlah karyawan: ";
    cin >> n;

    for (int i = 0; i < n; ) {

        cout << "\n----------------------------------------\n";
        cout << "Data Karyawan ke-" << i + 1 << '\n';
        cout << "----------------------------------------\n";

        cout << "1. Karyawan Tetap\n";
        cout << "2. Karyawan Kontrak\n";
        cout << "3. Karyawan Harian\n";
        cout << "Pilih tipe karyawan: ";

        int pilihan;
        cin >> pilihan;

        string id;
        string nama;

        cout << "ID   : ";
        cin >> id;

        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n'
        );

        cout << "Nama : ";
        getline(cin, nama);

        try {

            // ==========================================
            // KARYAWAN TETAP
            // ==========================================
            if (pilihan == 1) {

                double gajiPokok;
                double tunjanganJabatan;
                double bonusKinerja;

                cout << "Gaji pokok             : ";
                cin >> gajiPokok;

                cout << "Tunjangan jabatan      : ";
                cin >> tunjanganJabatan;

                cout << "Bonus kinerja bulanan  : ";
                cin >> bonusKinerja;

                daftarKaryawan.push_back(
                    make_unique<KaryawanTetap>(
                        id,
                        nama,
                        gajiPokok,
                        tunjanganJabatan,
                        bonusKinerja
                    )
                );
            }

            // ==========================================
            // KARYAWAN KONTRAK
            // ==========================================
            else if (pilihan == 2) {

                double nilaiKontrakTahunan;
                double tunjanganProyek;

                cout << "Nilai kontrak tahunan              : ";
                cin >> nilaiKontrakTahunan;

                cout << "Tunjangan penyelesaian proyek      : ";
                cin >> tunjanganProyek;

                daftarKaryawan.push_back(
                    make_unique<KaryawanKontrak>(
                        id,
                        nama,
                        nilaiKontrakTahunan,
                        tunjanganProyek
                    )
                );
            }

            // ==========================================
            // KARYAWAN HARIAN
            // ==========================================
            else if (pilihan == 3) {

                double upahHarian;
                int totalHariHadir;
                double insentifLembur;

                cout << "Upah harian          : ";
                cin >> upahHarian;

                cout << "Total hari hadir     : ";
                cin >> totalHariHadir;

                cout << "Insentif lembur      : ";
                cin >> insentifLembur;

                daftarKaryawan.push_back(
                    make_unique<KaryawanHarian>(
                        id,
                        nama,
                        upahHarian,
                        totalHariHadir,
                        insentifLembur
                    )
                );
            }

            else {
                cout << "Tipe karyawan tidak valid.\n";
                continue;
            }

            i++;
        }

        catch (const invalid_argument& e) {
            cout << "\nERROR: " << e.what() << '\n';
            cout << "Silakan masukkan ulang data karyawan.\n";
        }
    }


    // ==================================================
    // POLYMORPHISM
    // ==================================================

    double totalGajiKeseluruhan = 0;

    cout << "\n\n========================================\n";
    cout << "            DAFTAR GAJI KARYAWAN\n";
    cout << "========================================\n";

    cout << fixed << setprecision(2);

    for (const auto& karyawan : daftarKaryawan) {

        double gaji = karyawan->hitungGajiTotal();

        cout << "\nID         : "
             << karyawan->getId();

        cout << "\nNama       : "
             << karyawan->getNama();

        cout << "\nTotal Gaji : Rp "
             << gaji << '\n';

        totalGajiKeseluruhan += gaji;
    }


    cout << "\n========================================\n";
    cout << "TOTAL GAJI KESELURUHAN : Rp "
         << totalGajiKeseluruhan << '\n';

    cout << "========================================\n";

    return 0;
}