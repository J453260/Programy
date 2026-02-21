
public class ProducentSilnikówElektrycznych implements ProducentSilników {
	@Override
	public Silnik dawajMiTuZarazSilnik() {
		return new SilnikElektryczny();
	}
}
