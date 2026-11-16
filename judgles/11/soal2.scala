import scala.io.StdIn;

object soal2{
    def hurufMutu(x : Int): String = {
        if(x >= 85 && x <= 100) return "A";
        else if (x >= 70 && x <= 84) return "B";
        else if (x >= 60 && x <= 69) return "C";
        else return "TIDAK LULUS"
    }

    def main(args:Array[String]): Unit = {
        val n = StdIn.readInt();

        val data = StdIn.readLine().trim.split("\\s+").map(_.toInt).toList
        val dataRes = data.groupBy(hurufMutu(_))
        
        if(dataRes.isEmpty) {
            println("TIDAK ADA");
        }
        else {
            dataRes.map{
                case(k, v) => (k, v.size)
            }
            .toList
            .sorted
            .sortWith(_._2 > _._2)
            .foreach{
                case(k, v) => println(s"$k $v");
            }
        }
    }
}