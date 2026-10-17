# B. Manajemen Gaji Pegawai

**Time Limit:** 1 s  
**Memory Limit:** 256 MB

## Deskripsi

Sebuah perusahaan memiliki dua jenis pegawai (pegawai tetap dan pegawai harian) dengan sistem perhitungan gaji yang berbeda. Untuk efisiensi memori dan fleksibilitas data, perusahaan menggunakan konsep OOP dan polymorphism.

Oleh karena itu, pengembang sistem merancang 3 class yaitu `Pegawai`, `PegawaiTetap`, dan `PegawaiHarian` sebagai berikut:

1. Class **Pegawai** memiliki atribut nomor identitas pegawai.

2. Class **PegawaiTetap** merupakan turunan dari `Pegawai` dengan karakteristik memiliki gaji pokok dan tunjangan. Gaji bulanan dihitung dari penjumlahan gaji pokok dan tunjangan.

3. Class **PegawaiHarian** merupakan turunan dari `Pegawai` dengan karakteristik memiliki jam kerja selama sebulan. Gaji bulanan dihitung dari perkalian antara jam kerja sebulan dengan honor per jam perusahaan (diasumsikan sebesar 1000 rupiah per jam). Namun, ada pembatasan jam kerja. Jika lebih dari 200 jam sebulan, maka kelebihannya dihitung sebagai lembur. Diasumsikan uang lembur per jam adalah 1500 rupiah, namun tidak boleh melebihi 50 jam dalam sebulan.

Implementasikan semua class tersebut untuk membaca `N` data pegawai pada bulan tertentu dan menampilkan berapa total gaji seluruh pegawai, gaji tertinggi, dan identitas pegawai pemilik gaji tertinggi.

Jika terdapat lebih dari satu pemilik gaji tertinggi, maka yang ditampilkan adalah ID pegawai yang pertama kali ditemukan sesuai urutan input data.

## Constraints

- `1 ≤ N ≤ 1000`
- Semua nilai atribut yang ada di dalam class bertipe `int`.
- Wajib mengimplementasikan konsep OOP (**encapsulation, inheritance, polymorphism, array of object**).
- Bahasa pemrograman: **C++ atau Java**.
- Tidak diperbolehkan menggunakan STL (C++) atau JCF (Java).

## Input

- Baris pertama adalah nilai `N` yang menunjukkan banyaknya pegawai perusahaan.
- Sebanyak `N` baris berikutnya adalah data pegawai yang terdiri atas:
  - Jenis pegawai (`1`: pegawai tetap, `0`: pegawai harian).
  - Identitas pegawai (`string`).
  - Untuk pegawai tetap, diikuti nilai gaji pokok dan tunjangan.
  - Untuk pegawai harian, diikuti total jam kerja sebulan (diikuti dengan `0` untuk menunjukkan tidak ada tunjangan).

Format input:

```text
N
jenis_1 id_1 nilai_1 nilai_2
jenis_2 id_2 nilai_1 nilai_2
...
jenis_N id_N nilai_1 nilai_2
```

## Output

Output terdiri atas 3 baris dengan format:

```text
Rata-rata: [rata-rata gaji seluruh pegawai, dalam 2 digit di belakang tanda desimal]
Gaji Tertinggi: [nilai gaji tertinggi]
[id pegawai yang memiliki gaji tertinggi]
```

## Sample Input

```text
5
1 00219 10000 5000
0 02876 250 0
0 02123 180 0
1 09402 10000 8000
1 08111 15000 1000
```

## Sample Output

```text
Rata-rata: 100800.00
Gaji Tertinggi: 275000
02876
```

## Catatan

- Gunakan 3 class sesuai ketentuan soal.
- Terapkan konsep encapsulation, inheritance, polymorphism, dan array of object.
- Nomor identitas pegawai harus dipertahankan sesuai input, termasuk angka nol di depan.
- Perhatikan perbedaan perhitungan gaji pegawai tetap dan pegawai harian.
- Jam lembur pegawai harian dibatasi maksimal 50 jam per bulan.
- Jika terdapat beberapa pegawai dengan gaji tertinggi yang sama, tampilkan ID pegawai yang muncul paling awal.
- Pastikan rata-rata gaji ditampilkan dengan tepat 2 digit di belakang tanda desimal.
- Jangan menggunakan STL pada C++ atau JCF pada Java.
