object sort{
    def main(args:Array[String]) = {
        val dd = List(5, 3, 1, 4, 2, 2)
        println(dd.sorted)
        println(dd.sortWith(_>_))
        

        val dt = List(1, 3, 2, 5, 2, 3, 4, 1, 6)
        dt.groupBy(_%2).foreach(println)
        println()
        dt.groupBy(_%2).foreach {
        case (k,v) => println(s"$k -> $v")
        }



        val buah = List("pisang", "nangka","jambu", "apel", "nanas")
        buah.groupBy(_.length).foreach{
            case(x,y) => println(s"Ukuran: $x -> Buahnya: $y")
        }

        println(buah(0).endsWith("g"))
    }
}