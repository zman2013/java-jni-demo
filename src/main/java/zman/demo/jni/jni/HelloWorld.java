package zman.demo.jni.jni;

public class HelloWorld {
    
    static{
        try{
            System.loadLibrary("hello");
        }catch(Exception e){
            System.out.println("loading hello library failed");
        }
    }
    
    public native void sayHello(String name);
    
    
}
