# A. Persegi Panjang

**Time Limit:** 300 ms  
**Memory Limit:** 256 MB

## Deskripsi

Buat class `PersegiPanjang` menggunakan bahasa pemrograman **C++ atau Java** untuk mengimplementasikan objek persegi panjang yang diketahui panjang (`double`) dan lebar (`double`).

Objek ini memiliki kemampuan untuk menghitung:

1. **Luas** menggunakan fungsi `luas()`.
2. **Keliling** menggunakan fungsi `keliling()`.

Gunakan class tersebut untuk mengolah input data berupa `N` persegi panjang yang masing-masing diketahui nilai panjang (`pᵢ`) dan lebar (`lᵢ`).

Tampilkan luas dan keliling setiap persegi panjang yang ada.

## Constraints

- Program harus mengimplementasikan paradigma **Pemrograman Berorientasi Objek (OOP)**, terutama konsep **abstraksi dan enkapsulasi**.
- Atribut dari class **bukan `public`**.

## Input

Input data diberikan dengan format:

```text
N
p1 l1
p2 l2
...
pN lN
```

**Keterangan:**
- `N`: Banyaknya persegi panjang.
- `pᵢ`: Panjang persegi panjang ke-i.
- `lᵢ`: Lebar persegi panjang ke-i.

## Output

Sebanyak `N` baris yang masing-masing berisi **luas dan keliling** persegi panjang.

Setiap nilai ditampilkan dengan **2 digit di belakang tanda desimal**, dipisahkan oleh satu spasi.

## Sample Input

```text
3
10 2.5
5 4
1.5 5
```

## Sample Output

```text
25.00 25.00
20.00 18.00
7.50 13.00
```

## Catatan

- Gunakan class `PersegiPanjang` sesuai ketentuan soal.
- Pastikan atribut class tidak memiliki akses `public`.
- Implementasikan fungsi `luas()` dan `keliling()`.
- Perhatikan format output agar selalu menampilkan tepat 2 angka di belakang desimal.