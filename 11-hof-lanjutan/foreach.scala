object foreach{
    def main(args:Array[String]) = {
        println("Anas Ganteng");

        val dt = List(100, 200, 300);

        val dt5 = dt.map(x => x * 5);
        dt5.foreach(x => println(x))

        // dt.map(x => x*2).foreach(x => print(s"$x "));
    }


}