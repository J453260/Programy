import java.util.*;

public class JavaTetris implements Tetris {
    boolean[][] studnia;
    /**
     * studnia jest prawda fałsz
     * true jeśli zajęte
     * false jeśli wolne
     */
    int r, c; // rows i cols

    @Override
    public void rows(int rows) {
        this.r = rows;
        InicjujStudnie();
    }

    @Override
    public void cols(int cols) {
        this.c = cols;
        InicjujStudnie();
    }

    private void InicjujStudnie() {
        if (r > 0 && c > 0) {
            studnia = new boolean[r + 1][c];
        }
    }


    private boolean CzyKlocekMiesciSie(Block block, int kolumnaBazowa) {
        // Sprawdzamy kratkę bazową
        if (kolumnaBazowa < 0 || kolumnaBazowa >= c) return false;

        // Sprawdzamy wszystkie kratki klocka
        for (Vector v : block.squares()) {
            int kolumna = kolumnaBazowa + v.dCol();
            if (kolumna < 0 || kolumna >= c) return false;
        }
        return true;
    }


    private Set<Position> PobierzPozycjeKlocka(Block block, int BazowaCol, int BazowaRow) {
        Set<Position> pozycje = new HashSet<>();
        pozycje.add(new Position(BazowaCol, BazowaRow));

        for (Vector v : block.squares()) {
            pozycje.add(new Position(BazowaCol + v.dCol(), BazowaRow + v.dRow()));
        }

        return pozycje;
    }


    public boolean CzyMozeSpascNizej(Block block, int BazowaCol, int BazowaRow) {
        Set<Position> pozycje = PobierzPozycjeKlocka(block, BazowaCol, BazowaRow);

        for (Position p : pozycje) {
            if (p.row() == 1) return false;

            if (studnia[p.row() - 1][p.col()]) return false;
        }

        return true;
    }


    private void ZapiszWStudni(Block block, Position base) {
        Set<Position> pozycje = PobierzPozycjeKlocka(block, base.col(), base.row());

        for (Position p : pozycje) {
            studnia[p.row()][p.col()] = true;
        }

        for (int i = 1; i <= r; i++) {
            int licznik = 0;
            for (int j = 0; j < c; j++) {
                if (studnia[i][j]) {
                    licznik++;
                }
            }

            if (licznik == c) {
                for (int j = i; j < r; j++) {
                    for (int k = 0; k < c; k++) {
                        studnia[j][k] = studnia[j + 1][k];
                    }
                }

                for (int j = 0; j < c; j++) {
                    studnia[r][j] = false;
                }
                i--;
            }
        }
    }

    @Override
    public void drop(Block block) {
        Position base = block.base();

        while (CzyMozeSpascNizej(block, base.col(), base.row())) {
            base = new Position(base.col(), base.row() - 1);
        }

        ZapiszWStudni(block, base);
    }

    @Override
    public void optimalDrop(Block block) {
        int NajRows = 99999999;
        //bardzo duża wartość dla NajRows ponieważ chcę minimum
        //później będzie porównanie
        int NajCols = -1;

        for (int kolumnaBazowa = 0; kolumnaBazowa < c; kolumnaBazowa++) {
            if (!CzyKlocekMiesciSie(block, kolumnaBazowa)) continue;

            int wysokosc = SymulujUpuszczenieZeSledzeniem(block, kolumnaBazowa);


            //tutaj
            if (wysokosc < NajRows) {
                NajRows = wysokosc;
                NajCols = kolumnaBazowa;
            }
        }

        if (NajCols != -1) {
            Position nowaBaza = new Position(NajCols, block.base().row());

            while (CzyMozeSpascNizej(block, nowaBaza.col(), nowaBaza.row())) {
                nowaBaza = new Position(nowaBaza.col(), nowaBaza.row() - 1);
            }

            ZapiszWStudni(block, nowaBaza);
        }
    }


    private int SymulujUpuszczenieZeSledzeniem(Block block, int kolumnaBazowa) {
        boolean[][] kopia = new boolean[r + 1][c];
        for (int i = 1; i <= r; i++) {
            for (int j = 0; j < c; j++) {
                kopia[i][j] = studnia[i][j];
            }
        }

        //tablica śledząca
        boolean[][] kratkiKlocka = new boolean[r + 1][c];

        Position nowaBaza = new Position(kolumnaBazowa, block.base().row());

        while (CzyMozeSpascNizejWKopii(block, nowaBaza.col(), nowaBaza.row(), kopia)) {
            nowaBaza = new Position(nowaBaza.col(), nowaBaza.row() - 1);
        }

        Set<Position> pozycje = PobierzPozycjeKlocka(block, nowaBaza.col(), nowaBaza.row());
        for (Position p : pozycje) {
            kopia[p.row()][p.col()] = true;
            kratkiKlocka[p.row()][p.col()] = true;
        }

        UsunPelneWierszeWKopiiZeSledzeniem(kopia, kratkiKlocka);

        int maxWysokosc = 0;
        for (int row = r; row >= 1; row--) {
            for (int col = 0; col < c; col++) {
                if (kratkiKlocka[row][col]) {
                    return row;
                }
            }
        }

        return maxWysokosc;
    }


    private void UsunPelneWierszeWKopiiZeSledzeniem(boolean[][] kopia, boolean[][] kratkiKlocka) {
        for (int i = 1; i <= r; i++) {
            int licznik = 0;
            for (int j = 0; j < c; j++) {
                if (kopia[i][j]) {
                    licznik++;
                }
            }

            if (licznik == c) {
                for (int j = i; j < r; j++) {
                    for (int k = 0; k < c; k++) {
                        kopia[j][k] = kopia[j + 1][k];
                        if (kratkiKlocka != null) {
                            kratkiKlocka[j][k] = kratkiKlocka[j + 1][k];
                        }
                    }
                }

                for (int j = 0; j < c; j++) {
                    kopia[r][j] = false;
                    if (kratkiKlocka != null) {
                        kratkiKlocka[r][j] = false;
                    }
                }

                i--;
            }
        }
    }


    private boolean CzyMozeSpascNizejWKopii(Block block, int BazowaCol, int BazowaRow, boolean[][] kopia) {
        Set<Position> pozycje = PobierzPozycjeKlocka(block, BazowaCol, BazowaRow);

        for (Position p : pozycje) {
            if (p.row() == 1) return false;
            if (kopia[p.row() - 1][p.col()]) return false;
        }

        return true;
    }

    @Override
    public List<Integer> state() {
        List<Integer> ObecnyStan = new ArrayList<>();
        for (int col = 0; col < c; col++) {
            int Najwyzej = 0;
            for (int row = 1; row <= r; row++) {
                if (studnia[row][col]) {
                    Najwyzej = row;
                }
            }
            ObecnyStan.add(Najwyzej);
        }
        return ObecnyStan;
    }


    private List<Integer> AktualizujStan() {
        List<Integer> ObecnyStan = new ArrayList<>();
        for (int col = 0; col < c; col++) {
            int Najwyzej = 0;
            for (int row = r; row >= 1; row--) {
                if (studnia[row][col]) {
                    Najwyzej = row;
                    break;
                }
            }
            ObecnyStan.add(Najwyzej);
        }
        return ObecnyStan;
    }
}