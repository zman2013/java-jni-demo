#ifndef __CPP_INVOKE_JAVA_H__
#define __CPP_INVOKE_JAVA_H__

#include <jni.h>

class CppInvokeJava
{
public:
  //init nested jvm, and init java instance.
  CppInvokeJava();
  //destroy jvm
  ~CppInvokeJava();
  //normal method
  int Sum(int a, int b, int c);

private:
  JavaVM *m_jvm;
  JNIEnv *m_env;
  //the java class of CppInvokeJava
  jclass m_cppinvokejava_class;
  //the java instace of the class CppInvokeJava
  jobject m_cppinvokejava;
  //the java method id of the java sum method which will be invoked by the above 'sum' method.
  jmethodID m_sum_method;
};

#endif
