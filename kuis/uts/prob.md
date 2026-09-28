# 06KUIS - Luas Permukaan Bidang

**Time Limit:** 2 s  
**Memory Limit:** 256 MB

## Deskripsi

Diketahui 4 bentuk bidang, yaitu Lingkaran, Segitiga, Segiempat, dan Silinder.

Setiap bentuk memiliki atribut sebagai berikut:
- **Lingkaran:** radius atau jari-jari (`double`).
- **Segitiga:** alas (`double`) dan tinggi (`double`).
- **Segiempat:** panjang (`double`) dan lebar (`double`).
- **Silinder:** jari-jari (`double`) dan tinggi (`double`).

Semua bentuk bidang dapat dihitung luas permukaannya menggunakan fungsi `hitungLuas()`. Setiap bidang memiliki identitas berupa ID dengan tipe data `string`.

**Rumus luas permukaan silinder:**

`L = 2 × π × r × (r + t)`

Keterangan:
- `r` = jari-jari silinder.
- `t` = tinggi silinder.
- `π` = 3.14.

Untuk mengolah data keempat bentuk tersebut, digunakan struktur pewarisan berikut:

```text
              Bidang
                 |
     +-----------+-----------+
     |           |           |
 Lingkaran    Segitiga    Segiempat
     |
  Silinder
```

Susunlah program berbasis Object-Oriented Programming (OOP) untuk mengolah beberapa objek dan menampilkan total luas permukaan objek pada selang tertentu.

Penomoran posisi objek dimulai dari 1.

## Batasan

- `1 ≤ N ≤ 1000`.
- Gunakan nilai `π = 3.14` untuk perhitungan luas.
- Program wajib mengimplementasikan konsep:
  - Enkapsulasi (*Encapsulation*).
  - Pewarisan (*Inheritance*).
  - Polimorfisme (*Polymorphism*).
- Gunakan struktur data `vector` untuk menyimpan seluruh objek.

## Format Input

1. Baris pertama berisi bilangan bulat `N`, yaitu banyaknya objek.
2. Sebanyak `N` baris berikutnya berisi ID, jenis bidang, dan nilai atribut masing-masing objek.
3. Baris selanjutnya berisi dua bilangan bulat `a` dan `b`, yang menunjukkan posisi awal dan akhir objek yang akan dihitung total luas permukaannya.
4. Query dapat diberikan lebih dari satu kali.
5. Input `-9` menandakan akhir query.

## Format Output

Untuk setiap query, tampilkan total luas permukaan objek dari posisi `a` sampai dengan `b` (inklusif).

Hasil ditampilkan menggunakan **2 digit di belakang tanda desimal** dengan format:

`a-b : total_luas`

## Sample Input

```text
5
X321 Segitiga 3.5 8
L276 Lingkaran 5
S902 Silinder 8.5 7
P312 Segiempat 3 8
L234 Lingkaran 6
1 5
2 4
-9
```

## Sample Output

```text
1-5 : 1056.93
2-4 : 929.89
```

## Penjelasan Sample

- Query `1 5` menghitung total luas permukaan seluruh objek dari posisi ke-1 sampai dengan ke-5, menghasilkan `1056.93`.
- Query `2 4` menghitung total luas permukaan objek dari posisi ke-2 sampai dengan ke-4, menghasilkan `929.89`.