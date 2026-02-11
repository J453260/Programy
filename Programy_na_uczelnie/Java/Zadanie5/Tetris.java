import java.util.List;

/**
 * Interfejs tetrisa
 */
public interface Tetris {

    /**
     * Ustawia głębokość studni w kratkach. Studnia ma wiersze od 1 do rows.
     * Parameters:
     * rows - głębokość studni
     */

    void rows(int rows);

    /**
     * Ustawia szerokość studni w kratkach. Studnia ma kolumny od 0 do cols-1.
     * Parameters:
     * cols - szerokość studni
     */
    void cols(int cols);

    /**
     * Zrzut klocka bez optymalizacji. Klocek w przekazanym kształcie opuszczany jest na dno studni, aż do oparcia się o dno i/lub elementy innych klocków.
     * Parameters:
     * block - zrzucany klocek.
     */
    void drop(Block block);

    /**
     * Zrzut z optymalizacją położenia klocka. Zasady optymalizacji przedstawia opis zadnia.
     * Parameters:
     * block - zrzucany klocek
     */
    void optimalDrop(Block block);

    /**
     * Wynik pracy. Lista zawiera pozycję najwyższej zajętej kratki dla kolejnych kolumn. Stan początkowy to lista zawierające same zera.
     * Returns:
     * najwyższa, zajeta kratka dla kolejnych kolumn.
     */
    List<Integer> state();
}