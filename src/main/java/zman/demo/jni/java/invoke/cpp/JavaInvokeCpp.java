package zman.demo.jni.java.invoke.cpp;

public class JavaInvokeCpp {

    public native int sum(int m, int n, int k);

    static {
        System.loadLibrary("javainvokecpp");
    }

    public static void main(String[] args) {

	JavaInvokeCpp sample = new JavaInvokeCpp();
	
        System.out.println("The sum of 1, 2, 3 is: " + sample.sum(1, 2, 3));
        
    }
}
