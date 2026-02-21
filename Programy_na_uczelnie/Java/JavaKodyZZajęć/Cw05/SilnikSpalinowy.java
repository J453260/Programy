
public class SilnikSpalinowy extends Silnik {
	@Override
	public void dźwięk() {
		if ( włączony )
			System.out.println( "Brum......");
		else
			System.out.println( ".....................");
	}
	
	@Override
	public Silnik klonowanie() {
		return new SilnikSpalinowy();
	}
}
