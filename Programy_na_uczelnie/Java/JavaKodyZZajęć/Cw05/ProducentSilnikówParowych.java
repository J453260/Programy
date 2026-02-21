
public class ProducentSilnikówParowych implements ProducentSilników {
	@Override
	public Silnik dawajMiTuZarazSilnik() {
		return new SilnikParowy();
	}
}
