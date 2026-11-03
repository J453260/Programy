import java.util.*;

public class SzafkaZPolkami extends Szafka {
    // Mapa przechowująca zawartość półek: Klucz to numer półki, Wartość to zbiór książek (Set zapobiega duplikatom)
    private Map<Integer, Set<String>> zawartoscPolek = new HashMap<>();

    // Mapa przechowująca pojemność dla każdej półki: Klucz to numer półki, Wartość to maksymalna liczba książek
    private Map<Integer, Integer> pojemnosciPolek = new HashMap<>();

    private int aktualnaPolfka = -1;

    @Override
    public void pojemnoscPolki(int przedmiotow) {
        // Implementacja metody pojemnoscPolki
        if (aktualnaPolfka != -1) {
            pojemnosciPolek.put(aktualnaPolfka, przedmiotow);
        }
    }

    @Override
    public void naPolke(int numerPolki, String przedmiot) {
        // Implementacja metody naPolke
        if (!zawartoscPolek.containsKey(numerPolki)) {
            zawartoscPolek.put(numerPolki, new HashSet<>());
        }
        zawartoscPolek.get(numerPolki).add(przedmiot);
    }

    @Override
    public void usunWszystkoZPolki(int numerPolki) {
        // Implementacja metody usunWszystkoZPolki
        if (zawartoscPolek.containsKey(numerPolki)) {
            zawartoscPolek.get(numerPolki).clear();
        }
    }

    @Override
    Set<String> coJestNaPolce(int numerPolki) {
        // Implementacja metody coJestNaPolce
        return zawartoscPolek.getOrDefault(numerPolki, new HashSet<>()); // Zwraca zbiór książek na danej półce
    }
}