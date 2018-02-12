
/**
 * Demonstrates that memory usage in Java is surprising.
 */

class Point {
	private int x;
	private int y;
	public Point() { x = y = 0; }	
};


public class Memory {
	static final int SIZE=125*1000*1024; // 125000 KB

	public static void main(String[] args) throws InterruptedException {
		System.out.println("Before new");
		Thread.sleep(3000);

		Point[] p = new Point[SIZE];
		for (int  i=0; i<SIZE; ++i)
			p[i] = new Point();
		
		System.out.println("After new");

		// The free memory should drop by 2 million KB (?)

		Thread.sleep(5000);
	}
}