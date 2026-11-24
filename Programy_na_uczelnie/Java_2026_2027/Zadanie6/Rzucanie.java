/**
 * Główny interfejs procesu rzucania jabłkami.
 * Umożliwia otrzymanie fabryki produkującej jabłka i
 * narzędzia do rzucania jabłkami.
 */
public interface Rzucanie {
    /**
     * Umożliwia przekazanie fabryki produkującej jabłka.
     * @param fabryka fabryka produkująca jabłka
     */
    public void pobieranieJabłek(FabrykaJabłek fabryka );

    /**
     * Umożliwia przekazanie narzędzia do rzucania jabłkami.
     * @param rzucacz narzędzie do rzucania jabłkami
     */
    public void rzucaczJabłek( Rzucacz rzucacz );

    /**
     * Rozpoczęcie procesu rzucania jabłkami.
     * Metoda rzucaj kończy się, gdy zabraknie jabłek.
     */
    public void rzucaj();
}