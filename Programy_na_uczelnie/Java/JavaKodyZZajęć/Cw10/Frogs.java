import java.util.ArrayList;
import java.util.List;

public class Frogs {
	final static int FROGS = 9;
	public static void main(String[] args) {
		
		Meadow meadow = new Meadow( 10 );
	
		List<Frog> frogs = new ArrayList<Frog>();
		
		for ( int i = 0; i < FROGS; i++ )
			frogs.add( new Frog( i, meadow ));
		
		for ( Frog frog : frogs ) {
			Thread.ofPlatform().start( frog );			
		}
		
		while ( true ) {
			SleepHelper.sleep(500);
			System.out.println( meadow );
		}
	}
}
