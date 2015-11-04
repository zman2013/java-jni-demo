#include "zman_demo_jni_jni_HelloWorld.h"
#include <stdio.h>

JNIEXPORT void JNICALL Java_Hello_SayHello  (JNIEnv * env, jobject arg, jstring instring) 
{ 
  // 从 instring 字符串取得指向字符串 UTF 编码的指针
 const jbyte *str = 
   (const jbyte *)env->GetStringUTFChars( instring, JNI_FALSE ); 
 printf("Hello,%s\n",str); 
 // 通知虚拟机本地代码不再需要通过 str 访问 Java 字符串。
 env->ReleaseStringUTFChars( instring, (const char *)str ); 
 return; 
}
