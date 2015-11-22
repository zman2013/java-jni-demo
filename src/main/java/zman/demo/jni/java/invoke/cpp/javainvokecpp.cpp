#include "javainvokecpp.h"

JNIEXPORT jint JNICALL Java_zman_demo_jni_java_invoke_cpp_JavaInvokeCpp_sum
  (JNIEnv *env, jobject jobj, jint a, jint b, jint c)
{
  return a+b+c;
}
