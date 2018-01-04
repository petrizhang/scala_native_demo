object Main {
  def main(args: Array[String]): Unit = {
    System.loadLibrary("NativeDemo")
    val demo = new NativeDemo
    println(demo.distance(Array(1.0, 2.0, 3.0, 4.0), Array(3.0, 4.0, 5.0, 6.0)))
    println(demo.add(123.0, 123.0))
  }
}
