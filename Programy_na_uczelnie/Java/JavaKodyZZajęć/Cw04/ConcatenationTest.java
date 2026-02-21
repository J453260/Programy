
public class ConcatenationTest extends GeneralTest {
	
	public ConcatenationTest() {
		super("użycia operatora +");
	}

	@Override
	public void execute() {
		String tmp = par.initialString();
		
		for ( int i = 0; i < par.iterations(); i++ )
			tmp += par.deltaString();
	}
}
