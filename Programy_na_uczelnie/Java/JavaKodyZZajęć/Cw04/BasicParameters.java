
public class BasicParameters implements Parameters {
	private final String initial;
	private final String delta;
	private final int iterations;
	
	public BasicParameters(String initial, String delta, int iterations) {
		this.initial = initial;
		this.delta = delta;
		this.iterations = iterations;
	}

	@Override
	public String deltaString() {
		return delta;
	}
	
	@Override
	public String initialString() {
		return initial;
	}
	
	@Override
	public int iterations() {
		return iterations;
	}
	
	
}
