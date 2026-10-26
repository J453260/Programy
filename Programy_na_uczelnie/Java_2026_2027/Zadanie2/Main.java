public class Main {
    public static void main(String[] args) {
        Polacz polacz = new Polacz();
        polacz.liczbaN(3);
        int[][] tablica = {
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0 },
                { 4, 0, 5, 0, 4, 0, 0, 5, 3, 0, 5 },
                { 2, 5, 4, 4, 1, 1, 1, 3, 2, 3, 4 },
                { 1, 2, 1, 1, 3, 3, 3, 1, 2, 2, 2 }
        };
        polacz.tablica(tablica);
        polacz.przetworzTablice();
        System.out.println(wynik());
    }
}