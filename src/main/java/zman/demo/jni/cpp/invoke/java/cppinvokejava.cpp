#include <jni.h>
#include <string.h>
#include "cppinvokejava.h"

CppInvokeJava::CppInvokeJava()
{
  //init jvm args
  JavaVMInitArgs vm_args;
  vm_args.version = JNI_VERSION_1_8;

  JavaVMOption options[1];
  options[0].optionString = "-Djava.class.path=build";
  vm_args.nOptions = 1;
  vm_args.options = options;

  //create jvm
  long jvmStatus = JNI_CreateJavaVM(&m_jvm, (void **)&m_env, &vm_args);
  if( jvmStatus == JNI_ERR ){
    printf("Creating JVM failed.\n");
  }

  printf("Created JVM successfully.\n");

  //find the CppInvokeJava class
  m_cppinvokejava_class = m_env->FindClass("zman/demo/jni/cpp/invoke/java/CppInvokeJava");
  if( m_cppinvokejava_class == 0 ){
    printf("Not found class CppInvokeJava.\n");
  }

  jmethodID cppinvokejava_constructor = m_env->GetMethodID(m_cppinvokejava_class, "<init>", "()V");
  if( cppinvokejava_constructor == 0 ){
    printf("Not found CppInvokeJava's constructor.\n");
  }

  m_cppinvokejava = m_env->NewObject(m_cppinvokejava_class, cppinvokejava_constructor);
  if( m_cppinvokejava == 0 ){
    printf("Creating CppInvokeJava instance failed.\n");
  }

  //find the sum method
  m_sum_method = m_env->GetMethodID(m_cppinvokejava_class, "sum", "(III)I");
  if( m_sum_method == 0 ){
    printf("Not found sum method.\n");
  }

}

CppInvokeJava::~CppInvokeJava()
{
  m_jvm->DestroyJavaVM();
}

int CppInvokeJava::Sum(int a, int b, int c)
{
  return m_env->CallIntMethod(m_cppinvokejava, m_sum_method, a, b, c);
}


int main()
{
  CppInvokeJava cppInvokeJava;
  int sum = cppInvokeJava.Sum(1, 2, 3);
  printf("The sum is: %d.\n", sum);
}


