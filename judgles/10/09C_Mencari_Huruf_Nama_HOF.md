# 09C — Mencari Huruf pada Nama (HOF)

## Deskripsi soal
Diberikan daftar **N nama** dan sebuah huruf **C**. Hitung berapa **nama** yang mengandung huruf `C` setidaknya sekali. Pencarian **tidak membedakan huruf besar-kecil**. Setiap baris nama dihitung paling banyak sekali, tetapi nama identik pada dua baris tetap dihitung dua kali jika memenuhi syarat.

### Masukan
- Baris pertama: `N` dan karakter `C`.
- `N` baris berikutnya: satu nama per baris, tanpa spasi.

### Batasan
- `1 ≤ N ≤ 10000`
- Panjang nama: 1–30 karakter.
- Nama dan `C` hanya memakai huruf `A–Z` atau `a–z`.

### Keluaran
Satu bilangan: jumlah nama yang mengandung huruf `C`.

### Contoh
**Input**
```text
7 a
Andi
Budi
Sari
Rina
Eka
Lulu
Hana
```
**Output**
```text
5
```
**Penjelasan:** `Andi`, `Sari`, `Rina`, `Eka`, `Hana` mengandung `a`/`A`.

## Solusi Scala — HOF
```scala
import scala.io.StdIn

object Soal3 {
  def main(args: Array[String]): Unit = {
    val Array(n, c) = StdIn.readLine().trim.split("\\s+")
    val nama = Array.fill(n.toInt)(StdIn.readLine())

    val result = nama.count(_.toLowerCase.contains(c.toLowerCase))
    println(result)
  }
}
```

## Cara kerja
1. `Array.fill(n.toInt)(StdIn.readLine())` membaca tepat `N` nama (satu baris per nama).
2. `.toLowerCase` menyamakan kapitalisasi nama dan huruf pencarian.
3. `.contains(...)` mengecek keberadaan huruf di sebuah nama.
4. `.count(...)` menghitung **jumlah nama** yang lolos kondisi, bukan berapa kali huruf muncul.

**Contoh khusus:** Nama `Amanda` dengan target `a` menambah hasil **1**, bukan 3. Jika `Amanda` muncul di dua baris berbeda, keduanya dihitung.

## Latihan mandiri
Jika `C = A` dan namanya `Amanda`, `Budi`, `Amanda`, `SASA`, berapakah output? Jelaskan alasan setiap nama dihitung.
