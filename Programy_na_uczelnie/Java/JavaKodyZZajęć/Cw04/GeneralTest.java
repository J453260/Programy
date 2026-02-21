
abstract public class GeneralTest implements Test {
	protected Parameters par;
	protected String description;
	
	public GeneralTest( String description ) {
		this.description = description;
	}
	
	@Override
	public void setParameters(Parameters par) {
		this.par = par;
	}
	
	@Override
	public String description() {
		return "Test: " + description + " dla " + par.iterations() + 
				" iteracji";
	}
}
