/**
 * Interfejs calkowania numerycznego funkcji jednej zmiennej.
 */
public interface NumericalIntegration {
    /**
     * Ustawienie funkcji do scałkowania numerycznego
     * Parameters:
     * f - funkcja
     */
    void setFunction(Function f);

    /*
    Obliczenia całki w zadanym zakresie liczb (range). Zakres należy podzielić na wskazaną liczbę przedziałow (subintervals).
    Parameters:
    range - zakres liczb dla jakich wyznaczana jest całka
    subintervals - liczba podprzedziałów
    Returns:
    wynik całkowania numerycznego

     */
    double integrate(Range range, int subintervals);
}