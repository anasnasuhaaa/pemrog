import scala.io.StdIn 
object solve {
    def main(args:Array[String]): Unit = {
        val input1 = StdIn.readLine().trim.split("\\s+").map(_.toInt).toList
        val input2 = StdIn.readLine().trim.split("\\s+").map(_.toInt).toList

        val mergeList = input1.concat(input2)
        mergeList.sorted.foreach(x => print(s"$x "))
        println()
    }
}