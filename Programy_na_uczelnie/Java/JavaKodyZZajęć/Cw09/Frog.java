
public class Frog implements Runnable {

	private final int id;
	private final Meadow meadow;
	private int pos;
	private int nextPos;

	public Frog(int pos, Meadow meadow) {
		this.pos = pos;
		id = pos + 1;
		this.meadow = meadow;
		meadow.take(pos, id);
	}

	@Override
	public void run() {
		while (true) {
			nextPos = (pos + 1) % meadow.size();

/*
Używany jest jeden blok sychronized. Dzięki zastosowaniu wait
wątek (żaba), który nie może wykonać pracy (przeskoku na
kolejną pozycję), jest usypiany z oddaniem dostępu do sekcji
synchronized. 
 */
			synchronized (meadow) {
				while (meadow.isTaken(nextPos)) {
					// System.out.println( "Żaba " + id + " idzie spać");
					try {
						meadow.wait();
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
					// System.out.println( "Żaba " + id + " obudzona");
				}

				// System.out.println( "Żaba " + id + " skacze z " + pos + " -> " + nextPos );
				meadow.release(pos);
				meadow.take(nextPos, id);
				meadow.notifyAll();
				// System.out.println( "Żaba " + id + " budzi");
			} // synchronized

			pos = nextPos;
		}
	}
}
