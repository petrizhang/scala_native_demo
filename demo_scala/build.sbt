import util._

name := "demo_scala"

version := "0.1"

scalaVersion := "2.12.3"

lazy val projectName = "demo_scala"
lazy val cProjcetName = "demo_cpp"
lazy val cProjectPath = s"../$cProjcetName"

lazy val nativeClassNames = List(
  "NativeDemo"
)

lazy val targetClassPath = "target/scala-2.12/classes"
lazy val cmakeListPath = s"$cProjectPath/CMakeLists.txt"
lazy val headerOutputDir = cProjectPath

(compile in Compile) := (compile in Compile).map(
  x => {
    // post-compile work
    println("post-compile work")
    nativeClassNames.foreach {
      name =>
        genHeader(headerOutputDir, name, targetClassPath)
        appendCmakeList(name, cmakeListPath)
    }
    x
  }
).value

(run in Compile) := {
  (run in Compile).evaluated
  // post-run wokr
  println("post-run work")
}
