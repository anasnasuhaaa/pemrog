#include <iostream>
#include <string>
#include <map>
using namespace std;

class Barang
{
public:
  string kode; // kode barang
  string nama; // nama barang
  int harga;   // harga satuan barang (rupiah)
};

class DaftarKode
{
private:
  map<string, Barang> dt; // daftar kode barang
  int size;               // ukuran daftar kode barang yang ada
public:
  DaftarKode()
  {
    dt.clear();
    size = 0;
  }
  void init();                 // membaca daftar kode barang dari stdin
  string getNama(string kode); // mendapatkan nama barang dari kode
  int getHarga(string kode);   // mendapatkan harga barang dari kode
};

class Penjualan
{
private:
  DaftarKode daftar;   // daftar kode barang yang ada
  map<string, int> st; // data penjualan
  int size;            // ukuran data penjualan
public:
  Penjualan()
  {
    daftar.init();
    size = 0;
  }
  void add(string kode, int jumlah); // menambah data penjualan
};