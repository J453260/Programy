import java.util.Arrays;

public class Meadow {
	private final int[] meadow;

	public Meadow(int size ) {
		meadow = new int[ size ];
	}
	
	public int size() {
		return meadow.length;
	}
	
	synchronized public boolean isTaken( int idx ) {
		return meadow[ idx ] != 0;
	}
	
	synchronized public void take( int idx, int value ) {
		meadow[ idx ] = value;
	}
	
	synchronized public void release( int idx ) {
		take( idx, 0 );
	}
	
	synchronized public String toString() {
		return Arrays.toString(meadow);
	}

}
