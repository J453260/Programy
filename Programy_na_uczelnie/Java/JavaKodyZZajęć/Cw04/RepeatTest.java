
public class RepeatTest extends GeneralTest {
	
	public RepeatTest() {
		super( "użycia metody String.repeat");
	}
	
	@Override
	public void execute() {
		String tmp = par.initialString() + 
				par.deltaString().repeat(par.iterations());
	}
}
