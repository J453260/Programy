
abstract public class Silnik {
	
	protected boolean włączony;
	
	public void włącz( ) {
		dźwięk();
		włączony = true;
		dźwięk();
	}

	abstract public void dźwięk();
	
	abstract public Silnik klonowanie();
}
