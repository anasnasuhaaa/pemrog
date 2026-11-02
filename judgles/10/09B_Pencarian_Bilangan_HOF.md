# 09B — Pencarian Bilangan (HOF)

## Deskripsi soal
Diberikan deret **N bilangan bulat** dan bilangan `K`. Tentukan apakah `K` ada dalam deret.

### Masukan
- Dua bilangan pertama: `N` dan `K`.
- Berikutnya: `N` bilangan bulat `A1, A2, ..., AN`.

### Batasan
- `1 ≤ N ≤ 100000`
- `−10⁹ ≤ K, Ai ≤ 10⁹`

### Keluaran
Cetak `1` jika `K` ditemukan, atau `0` jika tidak.

### Contoh 1
**Input**
```text
7 10
3 5 10 2 10 -1 0
```
**Output**
```text
1
```

### Contoh 2
**Input**
```text
5 8
1 3 5 7 9
```
**Output**
```text
0
```

## Solusi Scala — HOF
```scala
import scala.io.StdIn

object Soal2 {
  def main(args: Array[String]): Unit = {
    val tokens = Iterator.continually(StdIn.readLine())
      .takeWhile(_ != null)
      .flatMap(_.trim.split("\\s+"))
      .filter(_.nonEmpty)

    val n = tokens.next().toInt
    val k = tokens.next().toInt
    val angka = tokens.take(n).map(_.toInt).toArray

    val result = angka.exists(_ == k)
    if (result) println(1) else println(0)
  }
}
```

## Cara kerja
- `exists(_ == k)` memeriksa apakah **minimal satu** elemen sama dengan `k`.
- Hasil `.exists(...)` adalah `Boolean` (`true` atau `false`).
- `if` mengubah hasil menjadi keluaran `1` atau `0`.

**Kesalahan umum:** Nama metodenya `.exists`, **bukan** `.exist`. `StdIn.readInt()` juga tidak dapat membaca baris berisi `7 10` sekaligus; karena itu, solusi membaca input sebagai token.

## Latihan mandiri
Apa output untuk `N = 4`, `K = -2`, dan deret `1 -2 -2 3`? Apakah jumlah kemunculan `K` mengubah hasil?
