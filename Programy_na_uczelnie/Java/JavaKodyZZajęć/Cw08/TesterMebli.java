
public class TesterMebli {
	public static void main(String[] args) {
		
		Mebel m = new Szafa();		
		test(m);
		
		m = new OswietlenieDoMebla(m);
		test(m);
		
		m = new DrzwiDoSzafy(m);
		test(m);
		
		StatystykaUżyciaMebla mPrim = new StatystykaUżyciaMebla(m);
		test(mPrim);
		
		System.out.println( "gets " + mPrim.getCounter() );
		System.out.println( "puts " + mPrim.putCounter() );
	}
	
	private static void test( Mebel m ) {
		System.out.println( "-".repeat(20));
		m.put();
		m.get();
	}
	
}
