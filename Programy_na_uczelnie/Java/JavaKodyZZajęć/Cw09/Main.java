
public class Main {
	
	private final static int LIMIT = 100000000;
	
	private static class Box {
		int i;
	}
	
	private static class Worker implements Runnable {
		private final Box box;
		
		public Worker(Main.Box box) {
			this.box = box;
		}

		@Override
		public void run() {
			for ( int i = 0; i < LIMIT; i++ ) {
				synchronized (box) {
					box.i ++;					
				}
			}
		}
	}
	
	public static void main(String[] args) throws InterruptedException {
		
		Box box = new Box();
		
		long ts = System.currentTimeMillis(); 
		Thread t1 = new Thread( new Worker(box));
		t1.start();
		
		Thread t2 = Thread.ofPlatform().start( new Worker( box ));
		
		// while ( t1.isAlive() ) {}  <- tego nie używać!
		// while ( t2.isAlive() ) {}
		
		t1.join();
		t2.join();
		long tf = System.currentTimeMillis();
		
		System.out.println( "Wynik końcowy: " + box.i );
		System.out.println( "Wynik po : " + ( tf - ts ) + " ms");
	}
	
	
	
}
