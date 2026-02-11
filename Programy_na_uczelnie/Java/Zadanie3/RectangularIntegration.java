import java.util.Set;

public class RectangularIntegration implements NumericalIntegration {
    private Function function;

    @Override
    public void setFunction(Function f) {
        this.function = f; //funkcja przekazana przez użytkownika
    }

    @Override
    public double integrate(Range range, int subintervals) {
        if (function == null) {
            throw new IllegalStateException("Funkcja nie została ustawiona (setFunction nie wywołano).");
        }

        if (subintervals <= 0) {
            throw new IllegalArgumentException("Liczba podprzedziałów musi być większa od zera.");
        }

        double start = range.min();
        double koniec = range.max();
        double szerokosc = (koniec - start) / subintervals;
        double suma = 0.0;

        //pobiera obszary zabronione
        Set<Range> Zabronione = function.domainExclusions();

        for (int i = 0; i < subintervals; i++) {
            double sr = start + (i + 0.5) * szerokosc; //sr - środek

            boolean ObZab = false; //ObZab - obszar zabroniony
            //warunek sprawdzający czy jest jakiś obszar zabroniony
            //gdy nie ma Zabronione = NULL
            if (Zabronione != null) {
                for (Range ex : Zabronione) {
                    if (sr >= ex.min() && sr <= ex.max()) { //czy środek prostokąta leży w obszarze zabronionym
                        ObZab = true;
                        break;
                    }
                }
            }

            //jeżeli środek nie należy do obszaru zabronionego to dodaje wartość funkcji
            if (!ObZab) {
                suma += function.apply(sr);
            }
        }

        return suma * szerokosc;
    }
}