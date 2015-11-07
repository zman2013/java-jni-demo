

public class Sample1 {

	public native int intMethod(int n);
	public native boolean booleanMethod(boolean bool);
	public native String stringMethod(String text);
	public native int intArrayMehtod(int[] intArray);
	
	static{
			System.loadLibrary("HelloWorld");
	}
	
	public static void main(String[] args){
		System.setProperty("java.library.path", "/Users/weizilu/workspace/demo/java-jni-demo/");
		System.out.println(System.getProperty("java.library.path"));
		
		Sample1 sample = new Sample1();
		int square = sample.intMethod(5);
		boolean bool = sample.booleanMethod(true);
		String text = sample.stringMethod("JAVA");
//		int sum = sample.intArrayMehtod(new int[]{1,2,3,5,8,13});
		
		System.out.println("intMethod: " + square);
		System.out.println("booleanMethod: " + bool );
		System.out.println("stringMethod: " + text);
//		System.out.println("intArrayMethod: " + sum );
	}
}
