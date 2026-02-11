import java.util.Set;

/**
 * Interfejs funkcji jednej zmiennej.
 */
public interface Function {
    /*
    Metoda zwraca zbiór zakresów liczb, w których funkcji nie można (nie wolno) wyliczyć. Zakresy liczb są rozłączne. Każdy zakres jest od min do max (min < max).
    Returns:
    zbiór dopełnień do dziedziny

     */

    Set<Range> domainExclusions();

    /*
    Wylicza wartość funkcji dla argumentu x. Argument nie może przybrać wartości ze zbioru dopełnień do dziedziny włącznie z granicami.
    Parameters:
    x - argument
    Returns:
    wartość funkcji dla podanego argumentu
     */
    double apply(double x);
}