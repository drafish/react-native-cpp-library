#include "JNIBinding.h"

extern "C"
{
  JNIEXPORT jint JNICALL
  Java_com_reactnativecppdemo_MylibraryModule_runTest(JNIEnv* env, jobject thiz)
  {
      example::Test test;
      int j = test.runTest();
      return j;
  }
}