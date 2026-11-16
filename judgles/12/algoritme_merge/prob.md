
# 11B. Algoritme Merge

| Time Limit | Memory Limit |
|------------|--------------|
| 2 s        | 256 MB       |

## Deskripsi

Diketahui dua kelompok data bilangan bulat. Buat program fungsional untuk menggabungkan kedua kelompok data tersebut sehingga menjadi satu kelompok data yang terurut menaik (*ascending*) menggunakan algoritme merge.

Kedua kelompok data harus diurutkan terlebih dahulu. Namun, pada saat proses penggabungan, **tidak diperbolehkan menggunakan fungsi sort**.

## Constraints

- **Style:** Pemrograman fungsional.
- **Dilarang:** `var`, `while`, `for` imperatif, dan mutasi data kecuali pada proses membaca input data.
- **Wajib:** Fungsi murni (*pure function*), Higher-Order Function (HOF), struktur data dan container, serta fungsi rekursif.

## Format Input

Input data diberikan dengan format:

```text
A1 A2 … AM B1 B2 … BN
```

## Format Output

Sebaris data yang sudah terurut dari kecil ke besar, dengan masing-masing nilai dipisahkan oleh satu spasi.

## Sample Input

```text
50 20 40 30 10 45 17 15
```

## Sample Output

```text
10 15 17 20 30 40 45 50
```
