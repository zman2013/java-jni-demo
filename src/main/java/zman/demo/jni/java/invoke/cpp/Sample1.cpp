#include "zman_demo_jni_java_invoke_cpp_Sample1.h"
#include <string.h>

JNIEXPORT jint JNICALL Java_zman_demo_jni_java_invoke_cpp_Sample1_intMethod
  (JNIEnv *env, jobject obj, jint num) {
   return num * num;
 }

 JNIEXPORT jboolean JNICALL Java_zman_demo_jni_java_invoke_cpp_Sample1_booleanMethod
   (JNIEnv *env, jobject obj, jboolean boolean) {
   return !boolean;
 }

 JNIEXPORT jstring JNICALL Java_zman_demo_jni_java_invoke_cpp_Sample1_stringMethod
   (JNIEnv *env, jobject obj, jstring string) {
     const char *str = env->GetStringUTFChars(string, 0);
     char cap[128];
     strcpy(cap, str);
     env->ReleaseStringUTFChars(string, str);
     return env->NewStringUTF("adsf");
 }
 
 JNIEXPORT jint JNICALL Java_zman_demo_jni_java_invoke_cpp_Sample1_intArrayMehtod
   (JNIEnv *env, jobject obj, jintArray array) {
     int i, sum = 0;
     jsize len = env->GetArrayLength(array);
     jint *body = env->GetIntArrayElements(array, 0);
     for (i=0; i<len; i++)
     {sum += body[i];
     }
     env->ReleaseIntArrayElements(array, body, 0);
     return sum;
 }

int main(){return 0;}
