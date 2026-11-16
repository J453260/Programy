/**
 * InterfejsPoszukiwania to interfejs pozwalający na przeprowadzenie procesu
 * przeszukiwania.
 */
public interface InterfejsPoszukiwania {
    /**
     * Metoda ustawia kolor robota.
     *
     * @param kolor kolor robota
     */
    public void ustawKolorRobota( Kolor kolor );

    /**
     * Metoda ustawia kolor poszukiwanej kratki.
     *
     * @param kolor poszukiwany kolor kratki
     */
    public void ustawKolorPoszukiwany( Kolor kolor );

    /**
     * Ustawia interfejs robota, który będzie wykonywał poszukiwanie.
     *
     * @param robot interfejs sterowania robotem
     */
    public void ustawInterfejsRobota( InterfejsRobota robot );

    /**
     * Start procesu poszukiwania. Metoda kończy się, gdy znajdzie kratkę o
     * zadanym kolorze.
     */
    public void wyszukaj();

    /**
     * Metoda zwraca położenie odnalezionej kratki.
     * @return kratka, której kolor był poszukiwany
     */
    public Kratka zwróćZnalezionąKratkę();
}