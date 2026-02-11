import java.util.*;
import java.util.stream.Collectors;

public class TVScheduler implements Scheduler {
    private final List<Slot> slots = new ArrayList<>();

    @Override
    public void addSlot(Slot program) {
        slots.add(program);//Dodaje program do slotu
    }

    @Override
    public Set<List<Slot>> match(Set<String> programs) {

        /*
        Dla każdego tytułu filmu mapa zawiera wszystkie jego wystąpienia.
        Wykorzystywane do generowania kombinacji
         */
        Map<String, List<Slot>> grupy = slots.stream()
                .filter(s -> programs.contains(s.program()))
                .collect(Collectors.groupingBy(Slot::program));

        //Jeśli brakuje któregoś programu — brak rozwiązania
        if (!grupy.keySet().containsAll(programs)) {
            return Set.of();
        }

        Set<List<Slot>> wynik = new HashSet<>();
        List<String> tytuly = new ArrayList<>(grupy.keySet());

        //Generowanie wszystkich kombinacji emisji
        List<List<Slot>> kombinacje = new ArrayList<>();
        kombinacje.add(new ArrayList<>()); // startujemy od pustej listy

        for (String tytul : tytuly) {
            List<Slot> WszystkieEmisje = grupy.get(tytul);
            List<List<Slot>> NoweKombinacje = new ArrayList<>();

            for (List<Slot> CzyJest : kombinacje) {
                for (Slot s : WszystkieEmisje) {
                    List<Slot> newList = new ArrayList<>(CzyJest);
                    newList.add(s);
                    NoweKombinacje.add(newList);
                }
            }
            kombinacje = NoweKombinacje;
        }
        /*
        W powyższej pętli tworzą się wszystkie możliwe kombinacje filmów, które potem będą
        sprawdzane pod kątem kolidowania.
         */

        for (List<Slot> option : kombinacje) {
            boolean konflikt = false;

            for (int i = 0; i < option.size(); i++) {
                for (int j = i + 1; j < option.size(); j++) {
                    Slot a = option.get(i);
                    Slot b = option.get(j);

                    //konwertujemy na minuty od północy
                    int startA = a.atH() * 60 + a.atM();
                    int koniecA = startA + a.duration();
                    int startB = b.atH() * 60 + b.atM();
                    int koniecB = startB + b.duration();

                    boolean NachNaSiebie = !(koniecA <= startB || startA >= koniecB); //Nachodzące na siebie
                    if (NachNaSiebie) {
                        konflikt = true;
                        break; //Opuszczamy pętle
                    }
                }
                if (konflikt) break; //Większą też
            }

            if (!konflikt) {
                wynik.add(option); //Jeżeli nie ma konfliktu to dodajemy
            }
        }

        return wynik;
    }
}