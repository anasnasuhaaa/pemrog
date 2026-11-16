import scala.io.StdIn;
object soal1{
    def main(args:Array[String]): Unit = {   
        val nk = StdIn.readLine().trim.split("\\s+").map(_.toInt)
        val k =  nk(1)
        val data = StdIn.readLine().trim.split("\\s+").map(_.toLong)

        val hasil = data.filter(x => x > 0 && x % 2 == 0).map(x => x*x).sortWith(_ > _).take(k).sum;
        println(hasil);
    }
}