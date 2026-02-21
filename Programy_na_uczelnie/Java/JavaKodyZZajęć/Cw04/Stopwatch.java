
public class Stopwatch {
	
	private final static double CONVERTER_TO_SEC = 1000;
	
	private long start;
	private long finish;
	
	public void click() {
		if ( start == 0 ) {
			start = now();
		} else {
			finish = now();
		}	
	}
	
	public double get() {
		return ( finish - start ) / CONVERTER_TO_SEC;
	}

	private long now() {
		return System.currentTimeMillis();
	}	

}
