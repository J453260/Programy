
public class Amfibia implements Auto, Lodz {

	protected Silnik silnik;
	
	public void włożenieSilnika( Silnik prototyp ) {
		this.silnik = prototyp.klonowanie();
	}
	
	public void włącz() {
		silnik.włącz();
	}

	public void dźwięk() {
		silnik.dźwięk();
	}
	
	
	@Override
	public void kierownica() {
		System.out.println("Tu Amfibia: oto kierownica"); 
	}
	
	@Override
	public void ster() {
		System.out.println("Tu Amfibia: oto ster"); 
	}
	
}
