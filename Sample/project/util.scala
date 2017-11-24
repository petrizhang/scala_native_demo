import java.io.FileWriter

import scala.io.Source

import sys.process._

import java.nio.file.{Paths, Files}

object util {
  def appendCmakeList(className: String, cmakeListPath: String) {
    // check if CmakeList.txt contains targets for every native class.
    var f = Source.fromFile(cmakeListPath)
    var cmakeContents = f.mkString
    f.close()

    // if the two lines not found, add them to CMakeList.txt
    val setStr = s"set(${className}_SOURCE_FILES $className.h $className.cpp)"
    val libStr = s"add_library($className SHARED $${${className}_SOURCE_FILES})"
    var appendContent = "\n"
    if (!cmakeContents.contains(setStr)) {
      appendContent = s"$appendContent$setStr\n"
    }
    if (!cmakeContents.contains(libStr)) {
      appendContent = s"$appendContent$libStr\n"
    }

    if (appendContent != "\n") {
      val out = new FileWriter(cmakeListPath, true)
      out.write(appendContent)
      out.close()
    }
  }

  /// generate .h files for compiled .class files
  def genHeader(outputDir: String, className: String, classPath: String) = {
    // invoke javah command to generate .h files
    s"javah -d $outputDir -classpath $classPath $className" !

    // read the generated header's content
    val header = Source.fromFile(s"$outputDir/$className.h")
    val headerContens = header.mkString
    header.close()

    // copy the c++ function definitions to cpp file
    val cppPath = s"$outputDir/$className.cpp"
    val cppExists = Files.exists(Paths.get(cppPath))
    if (!cppExists) {
      val cpp = new FileWriter(cppPath)
      val pattern = "[\\s\\S]*#endif([\\s\\S]*?)#ifdef __cplusplus[\\s\\S]*".r
      val pattern(funcDefs) = headerContens
      cpp.write(
        s"""
#include "$className.h"
$funcDefs
""")
      cpp.close()
    }
  }
}