
public class ToTylkoAuto implements Auto {

	private final Auto auto;

	public ToTylkoAuto(Auto auto) {
		this.auto = auto;
	}
	
	@Override
	public void kierownica() {
		auto.kierownica();
	}
}
