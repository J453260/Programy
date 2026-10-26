/**
 * Klasa abstrakcyjna umożliwiająca przetworzenie tablicy wg opisu z zadania 2.
 */
public abstract class PolaczN {
    /**
     * N to minimalna liczba powtórzeń danej liczby w wierszu. Powtórki dotyczą
     * wyłącznie liczb bezpośrednio sąsiadujących ze sobą.
     *
     * @param N minimalna liczba powtórzeń
     */
    abstract public void liczbaN(int N);

    /**
     * Tablica z danymi do przetworzenia.
     *
     * @param tablica prostokątna tablica z danymi.
     */
    abstract public void tablica(int[][] tablica);

    /**
     * Zlecenie przetworzenia danych w tablicy.
     */
    abstract public void przetworzTablice();

    /**
     * Metoda zwraca wynik. Wynikiem jest tablica o identycznych wymiarach jak
     * tablica oryginalna.
     *
     * @return wynik przetworzenia przekazanej przez użytkownika tablicy
     */
    abstract public int[][] wynik();
}