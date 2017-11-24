object Main {
  def main(args: Array[String]): Unit = {
    System.loadLibrary("MutiMatrix")
    System.loadLibrary("OwnMath")
    val m = new MutiMatrix
    m.test
    for (i <- 1 to 1000000) {
      val d = m.distance(Array(1.0, 2.0, 3.0, 4.0), Array(3.0, 4.0, 5.0, 6.0))
    }


    val c = new OwnMath
    println(c.add(123.0, 123.0))
  }
}
