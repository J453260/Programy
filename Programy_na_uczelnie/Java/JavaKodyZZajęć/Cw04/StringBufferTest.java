
public class StringBufferTest extends GeneralTest {
	
	public StringBufferTest() {
		super("budowy ciągu za pomocą StringBuffer-a" );
	}
	
	@Override
	public void execute() {
		StringBuffer sb = new StringBuffer();

		sb.append(par.initialString());

		for (int i = 0; i < par.iterations(); i++)
			sb.append(par.deltaString());

		String txt = sb.toString();
	}
}
