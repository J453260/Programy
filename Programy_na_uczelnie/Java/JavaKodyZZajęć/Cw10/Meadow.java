import java.util.Arrays;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Meadow {
	private final int[] meadow;
	private final Lock lock = new ReentrantLock();
	private final Condition[] conditions;

	public Meadow(int size) {
		meadow = new int[size];

		conditions = new Condition[size];

		for (int i = 0; i < size; i++)
			conditions[i] = lock.newCondition();

	}

	public Lock lock() {
		return lock;
	}
	
	public Condition[] conditions() {
		return conditions;
	}
	
	
	public int size() {
		return meadow.length;
	}

	synchronized public boolean isTaken(int idx) {
		return meadow[idx] != 0;
	}

	synchronized public void take(int idx, int value) {
		meadow[idx] = value;
	}

	synchronized public void release(int idx) {
		take(idx, 0);
	}

	synchronized public String toString() {
		return Arrays.toString(meadow);
	}

}
