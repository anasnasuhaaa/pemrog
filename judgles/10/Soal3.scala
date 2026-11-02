import scala.io.StdIn

object Soal3 {
  def main(args: Array[String]): Unit = {
    val Array(n, c) = StdIn.readLine().trim.split("\\s+")
    val nama = Array.fill(n.toInt)(StdIn.readLine())
    val result = nama.count(_.toLowerCase.contains(c.toLowerCase))

    println(result)
  }
}
