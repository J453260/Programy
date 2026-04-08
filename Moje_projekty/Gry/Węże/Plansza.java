import java.util.Random;

public class Plansza {
    Tile[][] plansza;
    Waz waz;
    int size;
    Random rand = new Random();

    Plansza(int size){
        plansza = new Tile[size][size];
        this.size = size;
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                plansza[i][j] = Tile.EMPTY;
            }
        }
    }

    void wyczyscPlansze(){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                plansza[i][j] = Tile.EMPTY;
            }
        }
    }

    void rysujPlansze(){

        for(int i = 0; i < plansza.length; i++){
            for(int j = 0; j < plansza[i].length; j++){
                switch(plansza[i][j]){
                    case EMPTY: System.out.print("."); break;
                    case HEAD: System.out.print("▲"); break;
                    case BODY: System.out.print("■"); break;
                    case FOOD: System.out.print("●"); break;
                }
            }
            System.out.println();
        }
    }

    void aktualizujPlansze(){

        wyczyscPlansze();

        for(int[] s : waz.segments){
            if(!czyPozaPlansza(s[0], s[1])){
                plansza[s[0]][s[1]] = Tile.BODY;
            }
        }

        int[] head = waz.segments.getFirst();
        if(!czyPozaPlansza(head[0], head[1])){
            plansza[head[0]][head[1]] = Tile.HEAD;
        }
    }

    void stworzWeza(int i, int j){
        waz = new Waz(i, j, 2);
    }

    boolean czyPozaPlansza(int x, int y){
        return x < 0 || y < 0 || x >= size || y >= size;
    }

    void dodajJedzenie(){
        int x, y;

        do{
            x = rand.nextInt(size);
            y = rand.nextInt(size);
        }while(plansza[x][y] != Tile.EMPTY);

        plansza[x][y] = Tile.FOOD;
    }

    boolean czyTfrailNaJedzenie(int x, int y){
        return plansza[x][y] == Tile.FOOD;
    }

    void zjadl(int x, int y){
        if(czyTfrailNaJedzenie(x, y)){
            waz.dodaj();
        }
    }
}