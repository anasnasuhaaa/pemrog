import scala.io.StdIn
object solve {
  def checker(L: List[Int]): List[Int] = {
    L match {
      case Nil                      => Nil
      case a :: b :: tail if a == b =>
        checker(tail.dropWhile(_ == a))
      case head :: tail =>
        head :: checker(tail)
    }
  }

  def main(args: Array[String]): Unit = {
    val input = StdIn.readLine().trim.split("\\s+").map(_.toInt).toList

    println(checker(input).mkString(" "))
  }
}
