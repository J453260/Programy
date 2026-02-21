
public class Main {
	public static void main(String[] args) {
		
		Klatka<Ssak> klatka = new Klatka<>();
		
		tygrysDoKlatki(klatka);

		Klatka<Tygrys> specjalnaNaTygrysy = new Klatka<Tygrys>();

		tygrysDoKlatki(	specjalnaNaTygrysy );
		

		głaskanie( specjalnaNaTygrysy );
		
	}
	
	private static void tygrysDoKlatki( Klatka<? super Tygrys> k ) {
		k.cos = new Tygrys();
	}
	
//	private static void tygrysDoKlatki( Klatka<Ssak> k ) {
//		k.cos = new Tygrys();
//	}
	
	private static void głaskanie( Klatka<? extends Kot> k ) {
		k.cos.mruczenie();
	}
	
	private static boolean klatkaZCzyms( Klatka<?> k ) {
		return k.cos != null;
	}
	


}
