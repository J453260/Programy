
public class OswietlenieDoMebla implements Mebel {

	private final Mebel mebelBazowy;
	
	public OswietlenieDoMebla(Mebel mebelBazowy) {
		this.mebelBazowy = mebelBazowy;
	}

	@Override
	public void get() {
		System.out.println( "Oświetlenie włącz");
		mebelBazowy.get();
		System.out.println( "Oświetlenie wyłącz");
	}
	
	@Override
	public void put() {
		System.out.println( "Oświetlenie włącz");
		mebelBazowy.put();
		System.out.println( "Oświetlenie wyłącz");
	}
	
}
