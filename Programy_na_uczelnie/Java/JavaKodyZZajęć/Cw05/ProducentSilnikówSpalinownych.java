
public class ProducentSilnikówSpalinownych implements ProducentSilników {
	@Override
	public Silnik dawajMiTuZarazSilnik() {
		return new SilnikSpalinowy();
	}

}
