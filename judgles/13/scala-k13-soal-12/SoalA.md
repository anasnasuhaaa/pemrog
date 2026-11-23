# 12A. Kelulusan Mahasiswa

**Mata kuliah:** KOM2205 Pemrograman — K13 (Data Structure & Container)

| Ketentuan | Nilai |
|---|---|
| Time limit | 2 s |
| Memory limit | 256 MB |
| Bahasa | Scala |

## Deskripsi

Diberikan data nilai `n` orang mahasiswa. Setiap mahasiswa memiliki **nama unik** dan sebuah nilai akhir. Simpan data dalam `Map[String, Int]`, kemudian gunakan **`filter` pada Map** untuk memilih mahasiswa dengan nilai **lebih besar atau sama dengan batas kelulusan**.

## Batasan

- `1 <= n <= 1000`
- Wajib menggunakan container `Map`.
- Wajib menggunakan operasi `filter` pada `Map`.

## Format masukan

Token pertama: `n batas`. Berikutnya terdapat `n` pasangan `nama nilai`. Pemisah token bisa spasi atau baris baru.

## Format keluaran

- Baris pertama: jumlah mahasiswa yang lulus.
- Baris berikutnya: `nama nilai`, satu mahasiswa per baris, **diurutkan berdasarkan nama secara alfabetis**.

## Contoh masukan

```text
7 75
Andi 80
Budi 60
Citra 90
Dewi 75
Eka 70
Fajar 85
Gina 55
```

## Contoh keluaran

```text
4
Andi 80
Citra 90
Dewi 75
Fajar 85
```

## Konsep dan algoritme

1. Baca `n`, `batas`, lalu `n` pasangan `(nama, nilai)`.
2. Ubah semua pasangan menjadi `Map[String, Int]`.
3. **Wajib** panggil `data.filter { case (_, nilai) => nilai >= batas }`.
4. Konversi hasil Map menjadi List agar mudah diurutkan melalui `.sortBy(_._1)`; `_._1` menunjuk nama/key.
5. Cetak ukuran hasil dan pasangan nama-nilai satu per baris.

`filter` menghasilkan Map baru tanpa mengubah Map asal (immutable). Map sendiri tidak menjamin urutan, sehingga **sorting tetap diperlukan**.

## Solver

File: [`12A.scala`](12A.scala)

```scala
import scala.io.Source

object Main {
  def mahasiswaLulus(data: Map[String, Int], batas: Int): List[(String, Int)] = {
    data.filter { case (_, nilai) => nilai >= batas }
      .toList
      .sortBy(_._1)
  }

  def main(args: Array[String]): Unit = {
    val input = Source.stdin.mkString.trim.split("\\s+").iterator
    val n = input.next().toInt
    val batas = input.next().toInt

    val mahasiswa: Map[String, Int] = (1 to n).map { _ =>
      val nama = input.next()
      val nilai = input.next().toInt
      nama -> nilai
    }.toMap

    val lulus = mahasiswaLulus(mahasiswa, batas)
    println(lulus.size)
    lulus.foreach { case (nama, nilai) => println(s"$nama $nilai") }
  }
}
```

## Kompleksitas

- Pembentukan Map dan filter: rata-rata `O(n)`.
- Pengurutan `k` mahasiswa lulus: `O(k log k)`.
- Memori: `O(n)`.

## Catatan penting

- Batas bersifat **inklusif** (`>=`), sehingga nilai tepat sama dengan batas **lulus**.
- Nama dianggap satu token sesuai contoh masukan.
