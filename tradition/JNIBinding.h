#pragma once

#include <jni.h>
#include "src/Test.h"

extern "C" {
    JNIEXPORT jint JNICALL
    Java_com_reactnativecppdemo_MylibraryModule_runTest(JNIEnv* env, jobject thiz);
}