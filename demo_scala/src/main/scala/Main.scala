object Main {
  def main(args: Array[String]): Unit = {
    // 加载动态库，一定要保证jvm能找到此动态库
    System.loadLibrary("NativeDemo")
    val demo = new NativeDemo

    val a = Array(1.0, 2.0, 3.0, 4.0)
    val b = Array(3.0, 4.0, 5.0, 6.0)

    println(demo.add(123.0, 123.0))
    println(demo.distance(a, b))
  }
}
