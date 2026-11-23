import scala.io.StdIn

object SoalA {
  def mahasiswaLulus(data: Map[String, Int], batas: Int): List[(String, Int)] = {
    data.filter { case (_, nilai) => nilai >= batas }
      .toList
      .sortBy(_._1)
  }

  def main(args: Array[String]): Unit = {
    val awal = StdIn.readLine().split("\\s+").map(_.toInt)
    val n = awal(0)
    val batas = awal(1)

    val mahasiswa = (1 to n).map { _ =>
      val data = StdIn.readLine().split("\\s+")
      data(0) -> data(1).toInt
    }.toMap

    val lulus = mahasiswaLulus(mahasiswa, batas)

    println(lulus.size)
    lulus.foreach { case (nama, nilai) =>
      println(s"$nama $nilai")
    }
  }
}
