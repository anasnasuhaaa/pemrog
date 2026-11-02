import scala.io.StdIn;

object Soal1 {
	def main(args: Array[String]): Unit = {
		val n = StdIn.readInt()
		val angka = StdIn.readLine().trim.split("\\s+").map(_.toLong)

		val result = angka.filter(_%2==0).map(x => x * x).sum
		println(result)
	}
}
