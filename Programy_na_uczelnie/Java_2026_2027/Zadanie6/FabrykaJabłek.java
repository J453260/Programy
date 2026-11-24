/**
 * Interfejs reprezentujący fabrykę jabłek.
 * Fabryka umożliwia pobieranie jabłek.
 * Brak jabłek sygnalizowany jest przez wyjątek BrakJabłekException.
 */
public interface FabrykaJabłek {
    /**
     * Pobranie pojedynczego jabłka lub informacja o braku jabłek.
     *
     * @return jabłko z unikalnym identyfikatorem
     * @throws BrakJabłekException informacja o skończeniu się jabłek
     */
    public Jablko pobierzJabłko() throws BrakJabłekException;
}