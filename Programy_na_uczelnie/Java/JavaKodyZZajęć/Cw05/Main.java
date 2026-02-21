
public class Main {
	public static void main(String[] args) {
		Amfibia amfibia1 = new Amfibia();
		Amfibia amfibia2 = new Amfibia();

		Silnik silnik = new SilnikParowy();
		
		amfibia1.włożenieSilnika( silnik );
		amfibia2.włożenieSilnika( silnik );
		
		amfibia1.włącz();
		
		amfibia2.dźwięk();
	}

	private static void trash( Amfibia amfibia ) {
		kapitan(amfibia);
		kierowca(new TonącaAmfibia());
		kierowca(new ToTylkoAuto(amfibia));		
	}
	
	private static void kierowca( Auto auto ) {
		System.out.println( "To ja kierowca");
		auto.kierownica();
		
		if ( auto instanceof Lodz lodz ) {
			lodz.ster();			
		}
		
	}
	
	private static void kapitan( Lodz lodz ) {
		System.out.println( "To ja kapitan");
		lodz.ster();
	}
}
