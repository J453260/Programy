
public class TestExecutor {
	public static void execute( Test test ) {
		System.out.println( test.description() );
		Stopwatch sw = new Stopwatch();
		
		sw.click();
		test.execute();
		sw.click();
		
		System.out.println( "Czas trwania to: " + sw.get() + " sekund");
	}
}
