import scala.io.StdIn

class WordCounter {
  def wordFreq(kalimat: List[String]): Map[String, Int] = {
    kalimat
      .flatMap(_.toLowerCase.split("[^a-z]+"))
      .filter(_.nonEmpty)
      .groupBy(identity)
      .map { case (kata, jumlah) => kata -> jumlah.size }
  }
}

object SoalC {
  def main(args: Array[String]): Unit = {
    val n = StdIn.readLine().toInt

    val kalimat = (1 to n).map(_ => StdIn.readLine()).toList

    val counter = new WordCounter
    val hasil = counter.wordFreq(kalimat)

    hasil.toList.sortBy(_._1).foreach { case (kata, jumlah) =>
      println(s"$kata $jumlah")
    }
  }
}
