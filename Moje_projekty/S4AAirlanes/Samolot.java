package org.example;
import java.util.ArrayList;

/**
 * Klasa reprezentująca samolot przypisany do trasy.
 * Przechowuje historię zmian liczby pasażerów w czasie.
 */
public class Samolot {

    /**
     * Reprezentuje pojedyncze zdarzenie w historii samolotu.
     * Określa dzień zmiany oraz liczbę pasażerów.
     * Wartość -1 oznacza wycofanie samolotu.
     */
    private static class Zdarzenie {
        long dzien;
        int pasazerowie;

        Zdarzenie(long dzien, int pasazerowie) {
            this.dzien = dzien;
            this.pasazerowie = pasazerowie;
        }
    }

    private ArrayList<Zdarzenie> historia;

    /**
     * Konstruktor
     * Tworzy nowy samolot z początkową liczbą pasażerów.
     *
     * @param pasazerowie maksymalna liczba pasażerów
     * @param id identyfikator samolotu (opcjonalny)
     */
    Samolot(int pasazerowie, int id) {
        historia = new ArrayList<>();
        // od dnia 0 samolot jest aktywny z daną liczbą pasażerów
        historia.add(new Zdarzenie(0, pasazerowie));
    }

    public void zapytanieP(int p, long t){
        /**
         * Zmienia maksymalną liczbę pasażerów od dnia t.
         *
         * @param p nowa liczba pasażerów
         * @param t dzień zmiany
         */
        historia.add(new Zdarzenie(t, p));
    }

    public void zapytanieC(long t){
        /**
         * Wycofuje samolot od dnia t (oznacza jako nieaktywny).
         *
         * @param t dzień wycofania
         */
        historia.add(new Zdarzenie(t, -1));
    }

    public void zapytanieA(int p, long t){
        /**
         * A i p t – przypisz samolot i do nowej trasy z maksymalną
         * liczbą pasażerów p w dniu t.
         */
        historia.add(new Zdarzenie(t, p));
    }

    public long zapytanieQ(long t){
        /**
         * Oblicza łączną liczbę dostępnych miejsc pasażerskich
         * od dnia 1 do dnia t.
         *
         * Uwzględnia tylko okresy, w których samolot był aktywny.
         *
         * @param t dzień końcowy
         * @return suma dostępnych miejsc w czasie
         */
        long suma = 0;
        for (int k = 0; k < historia.size(); k++) {
            Zdarzenie obecne = historia.get(k);

            // koniec przedziału: następne zdarzenie lub t
            long poczatek = Math.max(obecne.dzien, 1);
            long koniec;
            if (k + 1 < historia.size()) {
                koniec = Math.min(historia.get(k + 1).dzien, t + 1);
            } else {
                koniec = t + 1;
            }

            if (obecne.dzien > t) break;
            if (poczatek >= koniec) continue;

            if (obecne.pasazerowie != -1) {
                suma += (long) obecne.pasazerowie * (koniec - poczatek);
            }
        }
        return suma;
    }

    /**
     * Sprawdza, czy samolot jest aktywny w dniu t.
     *
     * @param t dzień sprawdzenia
     * @return true jeśli aktywny, false w przeciwnym razie
     */
    public boolean czyAktywny(long t) {
        int pasazerowie = 0;
        for (Zdarzenie z : historia) {
            if (z.dzien > t) break;
            pasazerowie = z.pasazerowie;
        }
        return pasazerowie != -1;
    }
}
