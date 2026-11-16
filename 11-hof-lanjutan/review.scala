object review{
def main(args:Array[String]) : Unit = {
    // Memanggil fungsi lain sebagai parameter input
    val data = Seq(1000,2000,3000)
    var pangkat = (x: Int) => x*x
    var hasil = data.map(pangkat)

    println(hasil)

    def createMultiplier(factor: Int): Int => Int = {
        (x: Int) => x * factor
    }

    var multipleByFive = createMultiplier(5)
    val result = multipleByFive(5)
    println(result)
}
}   