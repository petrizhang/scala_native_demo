class MutiMatrix {

  //xM
  @native def vectorMutiMatrix(lx: Array[Double],rM:Array[Double]): Array[Double]
  //Mx
  @native def matrixMutiVector(lM: Array[Double], rx: Array[Double]): Array[Double]
  //MM
  @native def matrixMutiMatrix(lM: Array[Double],rM:Array[Double], k: Int): Array[Double]
  //xMx'
  @native def distance(x: Array[Double],M:Array[Double]): Double

  def test = {
    println("helloworld")
  }

}