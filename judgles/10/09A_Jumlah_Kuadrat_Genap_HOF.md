# 09A — Jumlah Kuadrat Bilangan Genap (HOF)

## Deskripsi soal
Diberikan deret berisi **N bilangan bulat**. Hitung jumlah **kuadrat** dari semua bilangan **genap** dalam deret.

### Masukan
- Bilangan pertama: `N`.
- Berikutnya: `N` bilangan bulat `A1, A2, ..., AN`, dipisahkan whitespace.

### Batasan
- `1 ≤ N ≤ 100000`
- `−10000 ≤ Ai ≤ 10000`

### Keluaran
Satu bilangan: jumlah kuadrat seluruh bilangan genap.

### Contoh
**Input**
```text
7
-4 -3 0 2 5 6 7
```
**Output**
```text
56
```
**Penjelasan:** Bilangan genap `-4, 0, 2, 6`; hasil `16 + 0 + 4 + 36 = 56`.

## Solusi Scala — HOF
```scala
import scala.io.StdIn

object Soal1 {
  def main(args: Array[String]): Unit = {
    val tokens = Iterator.continually(StdIn.readLine())
      .takeWhile(_ != null)
      .flatMap(_.trim.split("\\s+"))
      .filter(_.nonEmpty)

    val n = tokens.next().toInt
    val angka = tokens.take(n).map(_.toLong).toArray

    val result = angka.filter(_ % 2 == 0).map(x => x * x).sum
    println(result)
  }
}
```

## Cara kerja
1. `filter(_ % 2 == 0)` menyisakan angka genap.
2. `map(x => x * x)` mengkuadratkan setiap angka terpilih.
3. `sum` menjumlahkan hasil kuadrat. **Gunakan `.sum`, bukan `.sum()`**.

**Mengapa `Long`?** Hasil maksimum dapat mencapai `100000 × 10000² = 10000000000000`, lebih besar daripada batas `Int`.

**Catatan input:** Pembaca token di atas menangani bilangan yang dipisahkan spasi maupun baris baru, sehingga lebih aman untuk online judge. Tidak mencampur Tab dan spasi pada indentasi.

## Latihan mandiri
Input `5` dan `1 3 5 7 9` seharusnya menghasilkan `0`. Coba jelaskan mengapa `.sum` tetap aman ketika tidak ada bilangan genap.
