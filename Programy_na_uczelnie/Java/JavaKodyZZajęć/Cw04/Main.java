import java.util.List;

public class Main {
	public static void main(String[] args) {
		List<Parameters> pars = List.of(new BasicParameters("", "AlaMaKota", 100000),
				new BasicParameters("", "AlaMaKota", 200000));

		List<Test> tests = List.of(new ConcatenationTest(), new StringBufferTest(),
				new RepeatTest());

		for (Test test : tests)
			for (Parameters par : pars) {
				test.setParameters(par);
				TestExecutor.execute(test);
			}
	}
}
