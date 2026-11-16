
import scala.io.StdIn

object soal22 {
    def hurufMutu(x: Int): String = {
        if (x >= 85 && x <= 100) return "A"
        else if (x >= 70 && x <= 84) return "B"
        else if (x >= 60 && x <= 69) return "C"
        else return "TIDAK LULUS"
    }

    def main(args: Array[String]): Unit = {
        val n = StdIn.readInt()

        val data = Iterator
            .continually(StdIn.readLine())
            .takeWhile(_ != null)
            .flatMap(_.trim.split("\\s+"))
            .filter(_.nonEmpty)
            .take(n)
            .map(_.toInt)
            .toList

        val dataRes = data
            .groupBy(hurufMutu(_))
            .filter(_._1 != "TIDAK LULUS")

        if (dataRes.isEmpty) {
            println("TIDAK ADA")
        }
        else {
            dataRes.map {
                case (k, v) => (k, v.size)
            }
            .toList
            .sortWith((a, b) =>
                if (a._2 == b._2) a._1 < b._1
                else a._2 > b._2
            )
            .foreach {
                case (k, v) => println(s"$k $v")
            }
        }
    }
}
