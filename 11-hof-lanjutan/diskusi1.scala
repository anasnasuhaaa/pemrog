object diskusi1 {
  def main(args: Array[String]): Unit = {
    val n = scala.io.StdIn.readInt()
    val data = scala.io.StdIn.readLine()
      .trim.split("\\s+").map(_.toInt).toList

    val hasil = data
      .groupBy(x => x)
      .view.mapValues(_.size).toMap
      .toSeq
      .sortBy(_._1)

    hasil.foreach {
      case (angka, jumlah) => println(s"$angka -> $jumlah")
    }
  }
}