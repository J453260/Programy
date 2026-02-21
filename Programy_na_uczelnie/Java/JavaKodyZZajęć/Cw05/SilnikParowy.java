
public class SilnikParowy extends Silnik{

	
	@Override
	public void dźwięk() {
		if ( włączony ) 
			System.out.println( "Pufff... Pufff.... [syczecznie]");
		else 
			System.out.println( "--------------------------------");
	}
	
	@Override
	public Silnik klonowanie() {
		return new SilnikParowy();
	}
}
