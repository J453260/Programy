/**
 - Klasa reprezentująca wyświetlacz cztero-pozycyjny dla zegara. Poprawne ustawy
 - to od 0000 do 2359.
 */
public class Display {
    public String wyswietlacz = "0000";
    //public String kursor = "0";
    public int indeksLiczby = 0;
    public final int MAX = 2359;
    public final int MIN = 0000;

    public Display() {
        reset();
    }

    public Display(String wyswietlacz, int indeksLiczby) {
        this.wyswietlacz = wyswietlacz;
        this.indeksLiczby = indeksLiczby;
        reset();
    }

    /**
     - Ustawia pozycję kursora. Wykonanie set ustawia kursor na pierwszej pozycji
     - (skrajna lewa) przy pierwszym naciśnięciu po utworzeniu obiektu lub po
     - wykonaniu reset. Kolejne naciśnięcia set przesuwają kursor na kolejne pozycje
     - w prawo. Jeśli kursor jest na ostatniej pozycji (skrajna prawa), to
     - naciśnięcie set przenosi kursor na pozycję pierwszą.
     */
    public void set() {
        if (indeksLiczby == 0 || indeksLiczby >= 4) {
            indeksLiczby = 1;
        } else {
            indeksLiczby++;
        }
    }

    /**
     - Inkrementuje liczbę na pozycji wskazywanej przez kursor.
     */
    public void plus() {
        // 1. Konwersja na int i inkrementacja
        char[] cyfry = wyswietlacz.toCharArray();
        int idx = indeksLiczby - 1; // Konwersja na indeks tablicy (0-3)
        int cyfra = Character.getNumericValue(cyfry[idx]) + 1;

        switch(indeksLiczby)
        {
            case 1:
            {
                if(cyfra > 2){
                    cyfra = 0;
                }

                if (cyfra == 2 && Character.getNumericValue(cyfry[1]) > 3) {
                    cyfry[1] = '3';
                }
                break;
            }

            case 2:
            {
                if(cyfra > 3){
                    cyfra = 0;
                }
                break;
            }

            case 3:
            {
                if(cyfra > 5){
                    cyfra = 0;
                }
                break;
            }

            case 4:
            {
                if(cyfra > 9){
                    cyfra = 0;
                }
                break;
            }
        }

        // 2. Konwersja z powrotem na String
        cyfry[idx] = Character.forDigit(cyfra, 10);
        wyswietlacz = new String(cyfry);
    }

    /**
     - Dekrementuje liczbę na pozycji wskazywanej przez kursor.
     */
    public void minus() {
        // 1. Konwersja na int i dekrementacja
        char[] cyfry = wyswietlacz.toCharArray();
        int idx = indeksLiczby - 1;
        int cyfra = Character.getNumericValue(cyfry[idx]) - 1;

        switch(indeksLiczby)
        {
            case 1:
            {
                if(cyfra < 0){
                    cyfra = 2;
                }
                break;
            }

            case 2:
            {
                if(cyfra < 0){
                    cyfra = 3;
                }
                break;
            }

            case 3:
            {
                if(cyfra < 0){
                    cyfra = 5;
                }
                break;
            }

            case 4:
            {
                if(cyfra < 0){
                    cyfra = 9;
                }
                break;
            }
        }

        // 2. Konwersja z powrotem na String
        cyfry[idx] = Character.forDigit(cyfra, 10);
        wyswietlacz = new String(cyfry);
    }

    /**
     - Przywraca stan początkowy. Tj. stan wyświetlacza 0000. Wykonanie set po reset
     - powoduje ustawienie kursora na skrajnie lewej pozycji.
     */
    public void reset() {
        wyswietlacz = "0000";
        indeksLiczby = 0;
    }

    /**
     - Umożliwia pobranie aktualnego ustawienia wyświetlacza.
     -
     - @return stan wyświetlacza (od 0000 do 2359).
     */
    public String get() {
        return wyswietlacz; // oczywiście do zmiany
    }
}
