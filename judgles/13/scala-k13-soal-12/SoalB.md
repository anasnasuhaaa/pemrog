# 12B. Penyimpanan Data Pengguna

**Mata kuliah:** KOM2205 Pemrograman — K13 (Data Structure & Container)

| Ketentuan | Nilai |
|---|---|
| Time limit | 2 s |
| Memory limit | 256 MB |
| Bahasa | Scala |

## Deskripsi

Sistem menyimpan daftar ID pengguna aktif. Awalnya terdapat `n` ID aktif, kemudian `q` perintah diproses berurutan:

- `MASUK x`: tambahkan ID `x` jika belum aktif.
- `KELUAR x`: keluarkan ID `x` jika aktif.
- `CEK x`: cetak `AKTIF` jika `x` aktif, atau `TIDAK` jika tidak aktif.

Setiap ID hanya boleh muncul sekali dalam koleksi pengguna aktif, sehingga container **Set** tepat digunakan.

## Batasan

- `1 <= n, q <= 10000`
- `1 <= ID <= 1000000000`

## Format masukan

`n q`, kemudian `n` ID awal, diikuti `q` perintah, masing-masing berbentuk `MASUK x`, `KELUAR x`, atau `CEK x`.

## Format keluaran

Untuk **setiap** perintah `CEK`, keluarkan tepat satu baris `AKTIF` atau `TIDAK`. Perintah lainnya tidak menghasilkan output.

## Contoh masukan

```text
5 8
10 20 30 40 50
CEK 20
CEK 25
MASUK 25
CEK 25
KELUAR 20
CEK 20
MASUK 30
CEK 30
```

## Contoh keluaran (diturunkan dari perintah)

```text
AKTIF
TIDAK
AKTIF
TIDAK
AKTIF
```

## Konsep dan algoritme

1. Masukkan ID awal ke `mutable.Set[Long]`.
2. Baca setiap perintah dengan `match`.
3. `MASUK` memakai `+=`; `KELUAR` memakai `-=`; `CEK` memakai `.contains`.
4. Gabungkan hasil pengecekan dalam `StringBuilder` agar output efisien.

Mutable Set dipilih karena kondisi pengguna aktif memang **berubah** setelah setiap perintah. Penambahan ID yang sudah ada dan penghapusan ID yang tidak ada aman (tidak menimbulkan duplikat/error).

## Solver

File: [`12B.scala`](12B.scala)

```scala
import scala.collection.mutable
import scala.io.Source

object Main {
  def main(args: Array[String]): Unit = {
    val input = Source.stdin.mkString.trim.split("\\s+").iterator
    val n = input.next().toInt
    val q = input.next().toInt

    val aktif = mutable.Set.empty[Long]
    (1 to n).foreach(_ => aktif += input.next().toLong)

    val output = new StringBuilder
    (1 to q).foreach { _ =>
      val perintah = input.next()
      val id = input.next().toLong

      perintah match {
        case "MASUK"  => aktif += id
        case "KELUAR" => aktif -= id
        case "CEK"    =>
          output.append(if (aktif.contains(id)) "AKTIF" else "TIDAK")
          output.append('\n')
      }
    }

    print(output.toString)
  }
}
```

## Kompleksitas

- Setiap operasi Set rata-rata `O(1)`.
- Total waktu rata-rata `O(n + q)`.
- Memori `O(n + q)` termasuk penyimpanan token input dan buffer keluaran.

## Catatan penting

- Tidak perlu sorting karena hanya `CEK` yang mencetak output.
- `Long` digunakan untuk menyimpan ID, meskipun nilai maksimum ID juga masih muat dalam `Int`.
