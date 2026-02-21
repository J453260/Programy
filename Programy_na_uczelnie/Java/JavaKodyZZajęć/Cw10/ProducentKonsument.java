import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.BlockingDeque;
import java.util.concurrent.LinkedBlockingDeque;

public class ProducentKonsument {

	private static final String FAJRANT = "To już koniec pracy";

	private final BlockingDeque<Job> zadania = new LinkedBlockingDeque<>();

	private class Job {
		final String txt;

		public Job(String txt) {
			this.txt = txt;
		}

		public int długość() {
			return txt.length();
		}
	}

	private class Jareczek implements Runnable {
		@Override
		public void run() {
			Job job;
			while (true) {
				try {
					while ((job = zadania.takeLast()) != null) {
						
//						if ( job.txt.equals( FAJRANT )) 
//							return;
						
						System.out.println("Odebrano zadanie " + job.txt + " pomiar długości " + job.długość());

						sleep(250);
					}
				} catch (InterruptedException e) {
					e.printStackTrace();
				}

			}
		}
	}

	public static void main(String[] args) {
		final int JOBS = 40;

		ProducentKonsument pk = new ProducentKonsument();

		for (int i = 0; i < JOBS; i++)
			pk.zadania.offerFirst(pk.new Job("x".repeat(i)));
		
		pk.zadania.offerFirst(pk.new Job(null));
		pk.zadania.offerFirst(pk.new Job(null));

		Thread t1 = Thread.ofPlatform().start(pk.new Jareczek());
		Thread t2 = Thread.ofPlatform().start(pk.new Jareczek());
		
		t1.setUncaughtExceptionHandler(new Thread.UncaughtExceptionHandler() {
			
			@Override
			public void uncaughtException(Thread t, Throwable e) {
				System.out.println( "Idę do domu.... pa pa....");
			}
		});
		
		t2.setUncaughtExceptionHandler(new Thread.UncaughtExceptionHandler() {
			
			@Override
			public void uncaughtException(Thread t, Throwable e) {
				System.out.println( "Wesołych Świąt!");
			}
		});

		
		
		while (true) {
			System.out.println("t1 w stanie " + t1.getState());
			System.out.println("t2 w stanie " + t2.getState());
			sleep(500);
		}

	}

	private static void sleep(long msec) {
		try {
			Thread.sleep(msec);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}

}
