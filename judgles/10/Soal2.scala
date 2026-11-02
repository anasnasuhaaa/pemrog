import scala.io.StdIn

object Soal2 {
  def main(args: Array[String]): Unit = {
    val Array(n, k) = StdIn.readLine().trim.split("\\s+").map(_.toInt)
    val angka = StdIn.readLine().trim.split("\\s+").map(_.toInt)

    val result = angka.exists(_ == k)

    if (result) println(1)
    else println(0)
  }
}