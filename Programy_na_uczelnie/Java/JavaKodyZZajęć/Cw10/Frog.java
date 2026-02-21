
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
			meadow.lock().lock();
			{
				while (meadow.isTaken(nextPos)) {
					System.out.println("Żaba " + id + " idzie spać, bo " + nextPos + " zajęte");
					try {
						meadow.conditions()[nextPos].await();
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
					System.out.println("Żaba " + id + " obudzona");
				}
				System.out.println("Żaba " + id + " skacze z " + pos + " -> " + nextPos);
				meadow.release(pos);
				meadow.take(nextPos, id);
				meadow.conditions()[pos].signal();
				System.out.println("Żaba " + id + " budzi");
			}
			meadow.lock().unlock();

			pos = nextPos;
		}
	}
}
