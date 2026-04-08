import java.util.*;
public class KolkoIKrzyzyk{
    public char[][] board;
    int size;

    public void setSize(int size){
        this.size = size;
        board = new char[size][size];

        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                board[i][j] = '-';
            }
        }
    }

    //displays the board
    public void display(){
        System.out.println("------");
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println("------");
    }

    public boolean player1fill(int i, int j){
        if(board[i-1][j-1] == '-'){
            board[i-1][j-1] = 'X';
            return true;
        }else{
            return false;
        }
    }

    public boolean player2fill(int i, int j){
        if(board[i-1][j-1] == '-'){
            board[i-1][j-1] = 'O';
            return true;
        }else{
            return false;
        }
    }

    public boolean checkWin(char player){
        // wiersze
        for(int i=0;i<size;i++){
            boolean win = true;
            for(int j=0;j<size;j++)
                if(board[i][j] != player) win = false;
            if(win) return true;
        }

        // kolumny
        for(int j=0;j<size;j++){
            boolean win = true;
            for(int i=0;i<size;i++)
                if(board[i][j] != player) win = false;
            if(win) return true;
        }

        // przekątna \
        boolean win = true;
        for(int i=0;i<size;i++)
            if(board[i][i] != player) win = false;
        if(win) return true;

        // przekątna /
        win = true;
        for(int i=0;i<size;i++)
            if(board[i][size-1-i] != player) win = false;
        return win;
    }

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        KolkoIKrzyzyk gra = new KolkoIKrzyzyk();
        System.out.print("Podaj rozmiar planszy: ");
        int size = input.nextInt();
        gra.setSize(size);
        System.out.println("Wprowadzaj pozycję w formacje: ");
        System.out.println("Pierwsza liczba - pozycja wiersza");
        System.out.println("Druga liczba - pozycja kolumny");
        while(true){
            gra.display();
            System.out.println("Kolej 1 gracza");
            System.out.println("Wprowadź pozycję w oddzielnych liniach: ");
            int i, j;
            i = input.nextInt();
            j = input.nextInt();
            gra.player1fill(i, j);
            if(gra.checkWin('X')){
                System.out.println("Gracz 1 wygrywa!");
                break;
            }

            gra.display();
            System.out.println("Kolej 2 gracza");
            System.out.println("Wprowadź pozycję w oddzielnych liniach: ");
            int k, l;
            k = input.nextInt();
            l = input.nextInt();
            gra.player2fill(k, l);

            if(gra.checkWin('O')){
                System.out.println("Gracz 2 wygrywa!");
                break;
            }
        }
    }
}
