
public class DrzwiDoSzafy implements Mebel {
	
	private final Mebel mebelBazowy;
	
	public DrzwiDoSzafy(Mebel mebelBazowy) {
		this.mebelBazowy = mebelBazowy;
	}

	@Override
	public void get() {
		System.out.println( "Owieram drzwi");
		mebelBazowy.get();
		System.out.println( "Zamykam drzwi");		
	}
	
	@Override
	public void put() {
		System.out.println( "Owieram drzwi");
		mebelBazowy.put();
		System.out.println( "Zamykam drzwi");
	}

}
