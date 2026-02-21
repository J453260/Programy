
public class StatystykaUżyciaMebla implements Mebel {
	int getCounter;
	int putCounter;

	private final Mebel mebelBazowy;

	public StatystykaUżyciaMebla(Mebel mebelBazowy) {
		this.mebelBazowy = mebelBazowy;
	}

	@Override
	public void get() {
		getCounter++;
		mebelBazowy.get();
	}

	@Override
	public void put() {
		putCounter++;
		mebelBazowy.put();
	}

	public int putCounter() {
		return putCounter;
	}

	public int getCounter() {
		return getCounter;
	}
}
