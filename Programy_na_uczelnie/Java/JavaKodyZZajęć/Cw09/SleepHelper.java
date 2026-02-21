
public class SleepHelper {
	public static void sleep( long msec ) {
		try {
			Thread.sleep(msec);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
}
