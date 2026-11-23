error id: file://<WORKSPACE>/SoalC.scala:scala/Unit#
file://<WORKSPACE>/SoalC.scala
empty definition using pc, found symbol in pc: scala/Unit#
empty definition using semanticdb
empty definition using fallback
non-local guesses:
	 -Unit#
	 -scala/Predef.Unit#
offset: 335
uri: file://<WORKSPACE>/SoalC.scala
text:
```scala
import scala.io.StdIn.readLine

class WordCounter {
  def wordFreq(kalimat: List[String]): Map[String, Int] = {
    kalimat
      .flatMap(_.toLowerCase.split("[^a-z]+"))
      .filter(_.nonEmpty)
      .groupBy(identity)
      .map { case (kata, jumlah) => kata -> jumlah.size }
  }
}

object S {
  def main(args: Array[String]): Unit@@ = {
    val n = readLine().toInt

    val kalimat = (1 to n).map(_ => readLine()).toList

    val counter = new WordCounter
    val hasil = counter.wordFreq(kalimat)

    hasil.toList.sortBy(_._1).foreach { case (kata, jumlah) =>
      println(s"$kata $jumlah")
    }
  }
}

```


#### Short summary: 

empty definition using pc, found symbol in pc: scala/Unit#