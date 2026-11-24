/**
 * Interfejs procesu rzucania jabłkami. Pozwala poznać zakresy kątów i siły
 * rzutu oraz wykonać rzut jabłkiem.
 */
public interface Rzucacz {
    /**
     * Interfejs określający wartość minimalną i maksymalną.
     */
    public interface Zakres {
        /**
         * Zwraca wartość minimalną.
         *
         * @return wartość minimalna
         */
        public double min();

        /**
         * Zwraca wartość maksymalną.
         *
         * @return wartość maksymalna
         */
        public double max();
    }

    /**
     * Zwraca zakres kątów. Koszyk znajduje się gdzieś w tym zakresie.
     *
     * @return zakres kątów
     */
    public Zakres zakresKątów();

    /**
     * Tak naprawdę to chodzi o szybkość początkową jabłka, ale siła rzutu jest
     * bardziej zrozumiała. Jabłka dosięgną koszyka jeśli rzut zostanie wykonany z
     * "siłą" z otrzymanego zakresu.
     *
     * @return zakres siły rzutu
     */
    public Zakres zakresSiłyRzutu();

    /**
     * Wykonuje rzut jabłkiem. Jeśli rzut nie trafi do koszyka, zgłaszane są wyjątki
     * określające przyczynę niepowodzenia. Trafienie do koszyka objawia się brakiem
     * zgłoszenia wyjątku.
     *
     * @param jablko jabłko, którym rzucamy
     * @param kąt    kąt rzutu
     * @param siła   siła (prędkość początkowa) rzutu
     * @throws ZaBliskoException   siła za mała, jabłko nie dosięgnęło koszyka
     * @throws ZaDalekoException   siła za dużą, jabłko przelatuje za koszyk
     * @throws ZbytWPrawoException kąt za duży, jabłko ląduje na prawo od koszyka
     * @throws ZbytWLewoException  kąt za mały, jabłko ląduje na lewo od koszyka
     */
    public void rzut(Jablko jablko, double kąt, double siła)
            throws ZaBliskoException, ZaDalekoException, ZbytWPrawoException, ZbytWLewoException;
}