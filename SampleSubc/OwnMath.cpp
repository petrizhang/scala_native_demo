
#include "OwnMath.h"

/*
 * Class:     OwnMath
 * Method:    add
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_OwnMath_add
  (JNIEnv *env, jobject obj, jdouble a, jdouble b) {
    return a+b;
}


