
public class SilnikElektryczny extends Silnik {

	@Override
	public void dźwięk() {
		if ( włączony )
			System.out.println( "bzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
		else 
			System.out.println("................................");
	}
	
	@Override
	public Silnik klonowanie() {
		return new SilnikElektryczny();
	}
	
}
