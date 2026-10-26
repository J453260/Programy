public class Polacz extends PolaczN {
    public int N;
    public int tablica[][];
    public int row, col;

    @Override
    public void liczbaN(int N) {
        // Implementacja metody liczbaN
        this.N = N;
    }

    @Override
    public void tablica(int[][] tablica) {
        // Implementacja metody tablica
        this.tablica = tablica;
        if (tablica != null && tablica.length > 0) {
            this.row = tablica.length;
            this.col = tablica[0].length;
        }
    }

    @Override
    public void przetworzTablice() {
        // Implementacja metody przetworzTablice
        // Tutaj można dodać logikę przetwarzania tablicy zgodnie z wymaganiami zadania
        int zmiennaRow = 0;

        while(zmiennaRow < row){
            boolean rowChanged = false;
            for(int i = 0; i < col; i++) {
                int currentValue = tablica[zmiennaRow][i];
                int count = 1;
                int startCol = i;

                if (currentValue == 0) {
                    continue;
                }

                while (i + 1 < col && tablica[zmiennaRow][i + 1] == currentValue) {
                    count++;
                    i++;
                }
                if (count >= N) {
                    for (int k = startCol; k <= i; k++) {
                        for (int r = zmiennaRow; r > 0; r--) {
                            tablica[r][k] = tablica[r - 1][k];
                        }
                        tablica[0][k] = 0; // Najwyższy wiersz staje się pusty
                    }

                    rowChanged = true;
                    // Cofamy indeks i, aby sprawdzić elementy, które właśnie spadły z góry
                    i = Math.max(-1, startCol - 1);
                }
                if (!rowChanged) {
                    zmiennaRow++;
                }
            }
        }
    }

    @Override
    public int[][] wynik() {
        // Implementacja metody wynik
        // Zwraca przetworzoną tablicę (na razie zwraca oryginalną tablicę)
        return this.tablica;
    }
}