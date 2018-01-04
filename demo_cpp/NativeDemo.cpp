#include "NativeDemo.h"
#include <string.h>

/*
 * Class:     NativeDemo
 * Method:    add
 * Signature: (DD)D
 */
JNIEXPORT jdouble JNICALL Java_NativeDemo_add
        (JNIEnv *env, jobject obj, jdouble a, jdouble b) {
    return a + b;
}

/*
 * Class:     NativeDemo
 * Method:    distance
 * Signature: ([D[D)D
 */
JNIEXPORT jdouble JNICALL Java_NativeDemo_distance
        (JNIEnv *env, jobject obj, jdoubleArray lhs, jdoubleArray rhs) {

    jsize lLength = env->GetArrayLength(lhs);
    jsize rLength = env->GetArrayLength(rhs);

    if (lLength != rLength) {
        env->FatalError("the length must be same");
    }

    jdouble *plhs = env->GetDoubleArrayElements(lhs, 0);
    jdouble *prhs = env->GetDoubleArrayElements(rhs, 0);

    jdouble result = 0;
    for (int i = 0; i < lLength; i++) {
        result += (plhs[i] - prhs[i]) * (plhs[i] - prhs[i]);
    }

    return result;
}
