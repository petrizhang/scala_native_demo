import util._


name := "Sample"

version := "0.1"

scalaVersion := "2.12.3"

lazy val projectName = "Sample"
lazy val cProjcetName = "SampleSubc"
lazy val cProjectPath = s"../$cProjcetName"

lazy val nativeClassNames = List(
  "MutiMatrix",
  "OwnMath"
)

lazy val targetClassPath = "target/scala-2.12/classes"
lazy val cmakeListPath = s"$cProjectPath/CMakeListTest.txt"
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