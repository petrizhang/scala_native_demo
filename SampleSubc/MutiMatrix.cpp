//
// Created by Pengcheng Zhang on 2017/11/22.
//


#include "MutiMatrix.h"
//#include <iostream>
#include <string.h>
#include <stdlib.h>
//using namespace std;


JNIEXPORT jdoubleArray JNICALL Java_MutiMatrix_vectorMutiMatrix
        (JNIEnv *env, jobject obj, jdoubleArray lxs, jdoubleArray rMs) {
    jsize xlen = env->GetArrayLength(lxs);
    jsize Mlen = env->GetArrayLength(rMs);
    jsize Mcol = Mlen / xlen;
    jdouble * lx = env->GetDoubleArrayElements(lxs, 0);
    jdouble * rM = env->GetDoubleArrayElements(rMs, 0);

    jdoubleArray result = env->NewDoubleArray(Mcol);
    jdouble * buff = new double[Mcol];
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

JNIEXPORT jdouble JNICALL Java_MutiMatrix_distance
        (JNIEnv *env, jobject obj, jdoubleArray x, jdoubleArray m) {

    jsize xLen = env->GetArrayLength(x);
    jsize mLen = env->GetArrayLength(m);

    if (xLen != mLen) {
        env->FatalError("the length must be same");
    }

    jdouble * lx = env->GetDoubleArrayElements(x, 0);
    jdouble * rm = env->GetDoubleArrayElements(m, 0);

    double result = 0;
    for (int i = 0; i < xLen; i++) {
            result += (lx[i]-rm[i])*(lx[i]-rm[i]);
    }

    env->ReleaseDoubleArrayElements(x, lx, 0);
    env->ReleaseDoubleArrayElements(m, rm, 0);

    jdouble jresult = result;
    return jresult;
}
