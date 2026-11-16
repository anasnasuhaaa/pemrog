import scala.io.StdIn

object Main {
  def cocok(a: List[Int], b: List[Int]): Boolean = {
    (a, b) match {
      case (Nil, _)                         => true
      case (_, Nil)                         => false
      case (headA :: tailA, headB :: tailB) =>
        headA == headB && cocok(tailA, tailB)
    }
  }

  def subList(a: List[Int], b: List[Int]): Boolean = {
    b match {
      case Nil       => a.isEmpty
      case _ :: tail =>
        cocok(a, b) || subList(a, tail)
    }
  }

  def main(args: Array[String]): Unit = {
    val n = StdIn.readInt()

    val data = List.fill(n) {
      val a = StdIn.readLine().trim.split("\\s+").map(_.toInt).toList
      val b = StdIn.readLine().trim.split("\\s+").map(_.toInt).toList
      (a, b)
    }

    data
      .map { case (a, b) =>
        if (subList(a, b)) "YA" else "TIDAK"
      }
      .foreach(println)
  }
}
