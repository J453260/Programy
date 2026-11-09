import java.util.*;

public class SzafkaPlusKolorZPolkami extends SzafkaPlusKolory {
    // Mapa przechowująca zawartość półek: Klucz to numer półki, Wartość to zbiór książek (Set zapobiega duplikatom)
    private Map<Integer, Map<Kolor, String>> zawartoscPolek = new HashMap<>();

    // Mapa przechowująca pojemność dla każdej półki: Klucz to numer półki, Wartość to maksymalna liczba książek
    private Map<Integer, Integer> pojemnosciPolek = new HashMap<>();

    private int aktualnaPolka = -1;

    @Override
    public void pojemnoscPolki(int przedmiotow){
        if (aktualnaPolka != -1) {
            pojemnosciPolek.put(aktualnaPolka, przedmiotow);

            // Jeśli pojemność zmalała i przekracza aktualną liczbę przedmiotów, usuwamy najstarsze
            Map<Kolor, String> polka = zawartoscPolek.get(aktualnaPolka);
            if (polka != null && polka.size() > przedmiotow) {
                // Ponieważ LinkedHashMap zachowuje kolejność, iterator zwraca elementy od najstarszego do najnowszego
                Iterator<Kolor> iterator = polka.keySet().iterator();
                while (polka.size() > przedmiotow && iterator.hasNext()) {
                    iterator.next();
                    iterator.remove(); // Usuwa najstarszy element
                }
            }
        }
    }

    @Override
    public void naPolke(int numerPolki, String przedmiot, Kolor kolor){
        // Zapamiętujemy, na której półce aktualnie pracujemy
        aktualnaPolka = numerPolki;

        // Tworzymy mapę jako LinkedHashMap, aby pamiętać kolejność dodawania elementów (najstarsze pierwsze)
        Map<Kolor, String> polka = zawartoscPolek.computeIfAbsent(numerPolki, k -> new LinkedHashMap<>());

        // Sprawdzamy pojemność (jeśli nie podano wcześniej, przyjmujemy domyślnie np. Integer.MAX_VALUE lub wg wymagań zadania)
        int limit = pojemnosciPolek.getOrDefault(numerPolki, Integer.MAX_VALUE);

        // Jeśli dany kolor już istnieje na półce, po prostu aktualizujemy przedmiot (nie zwiększa to liczby przedmiotów)
        if (polka.containsKey(kolor)) {
            polka.put(kolor, przedmiot);
            return;
        }

        // Jeśli półka osiągnęła limit, usuwamy najstarszy element (pierwszy w LinkedHashMap) przed dodaniem nowego
        if (polka.size() >= limit) {
            Iterator<Kolor> iterator = polka.keySet().iterator();
            if (iterator.hasNext()) {
                iterator.next();
                iterator.remove(); // Usuwamy najstarszy element
            }
        }

        // Dodajemy nowy przedmiot
        polka.put(kolor, przedmiot);
    }

    @Override
    public void usunWszystkoZPolki(int numerPolki){
        if (zawartoscPolek.containsKey(numerPolki)) {
            zawartoscPolek.get(numerPolki).clear();
        }
    }

    @Override
    Map<Kolor, String> coJestNaPolce(int numerPolki){
        Map<Kolor, String> oryginal = zawartoscPolek.get(numerPolki);

        if (oryginal == null) {
            return new HashMap<>();
        }

        return new HashMap<>(oryginal);
    }
}