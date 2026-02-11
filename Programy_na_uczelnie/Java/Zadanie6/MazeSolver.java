import java.util.*;

public class MazeSolver implements Maze {

    public boolean[][] plansza;
    private boolean[][] sprawdzone;
    private int r, c; // wiersze i kolumny

    /**
     * plansza:
     * true = zajęte
     * false = wolne
     *
     * sprawdzone:
     * true = sprawdzone
     * false = nie
     */

    private List<Integer> jakDaleko = new ArrayList<>(); // jak wysoko zajdzie
    private List<Integer> jakDuzo = new ArrayList<>(); // ile kratek uda się znaleźć
    private Set<Square> punkty = new HashSet<>(); // niedostępne kratki
    private Set<Square> odwiedzone = new HashSet<>(); // kratki w ogóle odwiedzone

    @Override
    public void rows(int rows) {
        this.r = rows;
        if (c > 0) inicjalizujPlansze();
    }

    @Override
    public void cols(int cols) {
        this.c = cols;
        if (r > 0) inicjalizujPlansze();
    }

    private void inicjalizujPlansze() {
        plansza = new boolean[r][c];
        sprawdzone = new boolean[r][c];

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                plansza[i][j] = false;
                sprawdzone[i][j] = false;
                //wolne i nie sprawdzone
            }
        }
    }

    @Override
    public void occupiedSquare(Set<Square> squares) {
        for (Square square : squares) {
            int row = square.row();
            int col = square.col();
            if (row >= 0 && row < r && col >= 0 && col < c) {
                plansza[row][col] = true;
                //true zajęte
            }
        }
    }

    @Override
    public List<Integer> howFar() {
        jakDaleko.clear();
        jakDuzo.clear();
        odwiedzone.clear();

        for (int kol = 0; kol < c; kol++) {
            if (plansza[0][kol]) {
                jakDaleko.add(0);
                jakDuzo.add(0);
                continue;
            }

            Square start = new Square(kol, 0); // row=0, col=kol

            Queue<Square> kolejka = new LinkedList<>();
            Set<Square> lokalnieOdwiedzone = new HashSet<>();

            kolejka.add(start);
            lokalnieOdwiedzone.add(start);

            int maxWiersz = 0; // max wiersz osiągnięty

            while (!kolejka.isEmpty()) {
                Square obecny = kolejka.poll();
                int obRow = obecny.row();
                //int obCol = obecny.col();

                if (obRow > maxWiersz) maxWiersz = obRow;

                for (Square n : obecny.neighbours()) {
                    int nRow = n.row();
                    int nCol = n.col();

                    if (nRow < 0 || nCol < 0 || nRow >= r || nCol >= c)
                        continue;

                    if (plansza[nRow][nCol]) // zajęte pole to wychodzę z iteracji
                        continue;

                    Square neighbor = new Square(nCol, nRow);
                    if (lokalnieOdwiedzone.contains(neighbor)){
                        continue; //jeżeli sąsiad sprawdzony to wychodzę z iteracji
                    }

                    lokalnieOdwiedzone.add(neighbor);
                    kolejka.add(neighbor);
                }
            }

            jakDaleko.add(maxWiersz);
            jakDuzo.add(lokalnieOdwiedzone.size());
            odwiedzone.addAll(lokalnieOdwiedzone);
        }

        return jakDaleko;
    }

    @Override
    public List<Integer> area() {
        return jakDuzo;
    }

    @Override
    public Set<Square> unreachableSquares() {
        punkty.clear();
        for (int wiersz = 0; wiersz < r; wiersz++) {
            for (int kolumna = 0; kolumna < c; kolumna++) {
                Square pole = new Square(kolumna, wiersz);
                boolean jestZajete = plansza[wiersz][kolumna];
                boolean byloOdwiedzone = odwiedzone.contains(pole);

                if (!jestZajete && !byloOdwiedzone) {
                    punkty.add(pole); //jeżeni nie zajęte i nie odwiedzone to nieosiągalne
                }
            }
        }

        return punkty;
    }
}