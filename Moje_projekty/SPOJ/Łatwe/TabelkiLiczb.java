import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String line = reader.readLine();
        if (line == null) return;

        // Wczytujemy liczbę testów
        StringTokenizer st = new StringTokenizer(line);
        int t = Integer.parseInt(st.nextToken());

        while (t-- > 0) {
            // Czytamy ew. puste linie
            line = reader.readLine();
            while (line != null && line.trim().isEmpty()) {
                line = reader.readLine();
            }
            if (line == null) break;

            st = new StringTokenizer(line);
            int wiersze = Integer.parseInt(st.nextToken());
            int kolumny = Integer.parseInt(st.nextToken());

            int[][] macierz = new int[wiersze][kolumny];

            for (int i = 0; i < wiersze; i++) {
                st = new StringTokenizer(reader.readLine());
                for (int j = 0; j < kolumny; j++) {
                    macierz[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            // Obrót ramki w lewo (przeciwnie do ruchu wskazówek zegara)
            int temp = macierz[0][0];

            // Górna krawędź -> w lewo
            for (int j = 0; j < kolumny - 1; j++) {
                macierz[0][j] = macierz[0][j + 1];
            }

            // Prawa krawędź -> w górę
            for (int i = 0; i < wiersze - 1; i++) {
                macierz[i][kolumny - 1] = macierz[i + 1][kolumny - 1];
            }

            // Dolna krawędź -> w prawo
            for (int j = kolumny - 1; j > 0; j--) {
                macierz[wiersze - 1][j] = macierz[wiersze - 1][j - 1];
            }

            // Lewa krawędź -> w dół
            for (int i = wiersze - 1; i > 1; i--) {
                macierz[i][0] = macierz[i - 1][0];
            }

            macierz[1][0] = temp;

            // Wypisanie wyniku z StringBuilderem (szybkie I/O)
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < wiersze; i++) {
                for (int j = 0; j < kolumny; j++) {
                    sb.append(macierz[i][j]).append(" ");
                }
                sb.append("\n");
            }
            System.out.print(sb.toString());
        }
    }
}
