#pragma once

#include "src/Test.h"
#include <jsi/jsi.h>

#if ANDROID
#include <jni.h>
#endif

using namespace facebook;

#if ANDROID
extern "C" {
    JNIEXPORT void JNICALL
    Java_com_reactnativecppdemo_MainActivity_install(JNIEnv* env, jobject thiz, jlong runtimePtr);
}
#endif

namespace example {

  class TestBinding : public jsi::HostObject {
  public:
    static void install(
                        jsi::Runtime &runtime,
                        std::shared_ptr<TestBinding> testBinding);

    TestBinding(std::unique_ptr<Test> test);

    jsi::Value get(jsi::Runtime &runtime, const jsi::PropNameID &name) override;

  private:
    std::unique_ptr<Test> test_;
  };

}
