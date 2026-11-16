import scala.io.StdIn

object soal4 {
    def main(args: Array[String]): Unit = {
        val input = scala.io.Source.stdin.mkString.trim.split("\\s+")
        val n = input(0).toInt

        val hasK = input.length > 1 && input(1).forall(_.isDigit)
        val k = if (hasK) input(1).toInt else n
        val start = if (hasK) 2 else 1

        val data = input.drop(start).take(n).toList

        val dataRes = data
            .map(_.toLowerCase.replaceAll("[^a-z]", ""))
            .filter(x => x.length >= 3 && x == x.reverse)
            .distinct
            .sortWith((a, b) =>
                if (a.length == b.length) a < b
                else a.length > b.length
            )
            .take(k)

        if (dataRes.isEmpty) {
            println("TIDAK ADA")
        } else {
            println(dataRes.mkString(" "))
        }
    }
}
