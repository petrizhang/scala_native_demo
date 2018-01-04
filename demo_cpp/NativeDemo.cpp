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

    env->ReleaseDoubleArrayElements(lhs, plhs, 0);
    env->ReleaseDoubleArrayElements(rhs, prhs, 0);

    return result;
}

/*
 * Class:     NativeDemo
 * Method:    vectorMulti
 * Signature: ([D[D)[D
 */
JNIEXPORT jdoubleArray JNICALL Java_NativeDemo_vectorMulti
        (JNIEnv *env, jobject obj, jdoubleArray lxs, jdoubleArray rMs) {
    jsize xlen = env->GetArrayLength(lxs);
    jsize Mlen = env->GetArrayLength(rMs);
    jsize Mcol = Mlen / xlen;
    jdouble *lx = env->GetDoubleArrayElements(lxs, 0);
    jdouble *rM = env->GetDoubleArrayElements(rMs, 0);

    jdoubleArray result = env->NewDoubleArray(Mcol);
    jdouble *buff = new double[Mcol];
    memset(buff, Mcol * sizeof(jdouble), 0);

    for (int i = 0; i < Mcol; i++) {
        for (int j = 0; j < xlen; j++) {
            buff[i] += lx[j] * rM[i * Mcol + j];
        }
    }

    env->ReleaseDoubleArrayElements(lxs, lx, 0);
    env->ReleaseDoubleArrayElements(rMs, rM, 0);
    env->SetDoubleArrayRegion(result, 0, Mcol, buff);
    return result;
}
