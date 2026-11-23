# 12C. Frekuensi Kata

**Mata kuliah:** KOM2205 Pemrograman — K13 (Data Structure & Container)

| Ketentuan | Nilai |
|---|---|
| Time limit | 2 s |
| Memory limit | 256 MB |
| Bahasa | Scala |

## Deskripsi

Diberikan `n` baris teks. Sebuah **kata** adalah rangkaian huruf alfabet `A-Z` atau `a-z`. Spasi dan semua tanda baca dianggap sebagai pemisah. Hitung frekuensi setiap kata **tanpa membedakan kapitalisasi**, lalu cetak kata beserta jumlahnya **berurutan alfabetis**.

## Batasan

- `1 <= n <= 100`.
- Panjang tiap baris paling banyak 100 karakter.
- Teks tidak mengandung angka.
- Gaya pemrograman: **OOP dan fungsional**.
- **Dilarang:** `var`, `while`, `for` imperatif, dan mutasi data kecuali untuk membaca input.
- **Wajib:** fungsi murni (*pure function*), HOF, struktur data/container, `class`, `object`, dan **Java Collection**.

## Format masukan

Baris pertama memuat `n`. Setelah itu **tepat `n` baris teks**, termasuk baris dengan spasi dan punctuation. Baca seluruh baris, bukan hanya token per kata.

## Format keluaran

Satu baris untuk setiap kata unik:

```text
kata frekuensi
```

Diurutkan naik berdasarkan kata.

## Contoh masukan

```text
4
Scala is fun, and Scala is powerful.
Functional programming is fun!
Map and Set are useful containers.
Scala, map, set, and list.
```

## Contoh keluaran

```text
and 3
are 1
containers 1
fun 2
functional 1
is 3
list 1
map 2
powerful 1
programming 1
scala 3
set 2
useful 1
```

## Konsep dan algoritme

1. Gunakan **Java Collection** `java.util.ArrayList[String]` untuk mengumpulkan `n` baris dari `BufferedReader`. Mutasi `add` hanya terjadi saat membaca input, sesuai pengecualian soal.
2. Konversi Java Collection ke `List[String]` Scala menggunakan `scala.jdk.CollectionConverters.*` dan `.asScala.toList`.
3. Dalam kelas `WordCounter`, buat `wordFreq` sebagai **fungsi murni**: parameter berupa `List[String]`; hasil berupa immutable `Map[String, Int]`; tidak mengubah state maupun mencetak.
4. Gunakan `flatMap` untuk mengubah kumpulan kalimat menjadi satu daftar kata; `toLowerCase(Locale.ROOT)` menyamakan kapitalisasi; `split("[^a-z]+")` memisahkan semua nonhuruf; `filter(_.nonEmpty)` menghapus elemen kosong.
5. Kelompokkan kata dengan `groupBy(identity)`, lalu ubah daftar kemunculan menjadi frekuensi melalui `map { case (kata, kemunculan) => kata -> kemunculan.size }`.
6. Di dalam `object Main`, urutkan pasangan berdasarkan kata (`.toList.sortBy(_._1)`), lalu cetak hasil.

**Penting:** Jangan gunakan `toSet` sebelum menghitung frekuensi, sebab duplikasi yang akan dihitung justru hilang.

## Solver

File: [`12C.scala`](12C.scala)

```scala
import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.ArrayList
import java.util.Locale
import scala.jdk.CollectionConverters.*

class WordCounter {
  // Fungsi murni: tidak mengubah data masukan dan tidak memiliki efek samping.
  def wordFreq(kalimat: List[String]): Map[String, Int] = {
    kalimat
      .flatMap(_.toLowerCase(Locale.ROOT).split("[^a-z]+"))
      .filter(_.nonEmpty)
      .groupBy(identity)
      .map { case (kata, kemunculan) => kata -> kemunculan.size }
  }
}

object Main {
  def main(args: Array[String]): Unit = {
    val reader = new BufferedReader(new InputStreamReader(System.in))
    val n = reader.readLine().trim.toInt

    // Java Collection dipakai untuk menampung input; mutasi hanya saat membaca.
    val inputLines = new ArrayList[String]()
    (1 to n).foreach(_ => inputLines.add(reader.readLine()))

    val counter = new WordCounter
    val frekuensi = counter.wordFreq(inputLines.asScala.toList)
    frekuensi.toList.sortBy(_._1).foreach { case (kata, jumlah) =>
      println(s"$kata $jumlah")
    }
  }
}
```

## Kompleksitas

Misalkan `L` total panjang teks dan `k` banyak kata unik:

- Tokenisasi dan pengelompokan: rata-rata `O(L)` (dengan memperhitungkan ukuran kata).
- Pengurutan kata unik: `O(k log k)` perbandingan kata.
- Memori: `O(L)` untuk baris masukan dan hasil tokenisasi/pengelompokan.

## Catatan penting

- `class WordCounter` menunjukkan OOP; `object Main` menyediakan titik masuk program.
- `flatMap`, `filter`, `groupBy`, `map`, `sortBy`, `foreach` merupakan operasi HOF/collection.
- `java.util.ArrayList` memenuhi syarat penggunaan Java Collection.
- Solver menargetkan Scala 3, sesuai import `scala.jdk.CollectionConverters.*`.
