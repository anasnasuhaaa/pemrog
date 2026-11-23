import scala.io.StdIn
import scala.collection.mutable

object SoalB {
  def main(args: Array[String]): Unit = {
    val awal = StdIn.readLine().split("\\s+").map(_.toInt)
    val n = awal(0)
    val q = awal(1)

    val aktif = mutable.Set.empty[Long]

    StdIn.readLine().split("\\s+").foreach { id =>
      aktif += id.toLong
    }

    (1 to q).foreach { _ =>
      val data = StdIn.readLine().split("\\s+")
      val perintah = data(0)
      val id = data(1).toLong

      perintah match {
        case "MASUK"  => aktif += id
        case "KELUAR" => aktif -= id
        case "CEK"    =>
          println(if (aktif.contains(id)) "AKTIF" else "TIDAK")
      }
    }
  }
}
