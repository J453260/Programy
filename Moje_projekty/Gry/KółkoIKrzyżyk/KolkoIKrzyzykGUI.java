import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class KolkoIKrzyzykGUI extends JFrame {

    private int[][] board;
    private JButton[][] buttons;
    private int size;
    private int currentPlayer = 1; // 1 - X, 2 - O

    public KolkoIKrzyzykGUI(int size) {
        this.size = size;
        board = new int[size][size];
        buttons = new JButton[size][size];

        setTitle("Kółko i Krzyżyk");
        setSize(600, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(size, size));

        initializeBoard();

        setVisible(true);
    }

    private void initializeBoard() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {

                JButton button = new JButton("");
                button.setFont(new Font("Arial", Font.BOLD, 40));

                int row = i;
                int col = j;

                button.addActionListener(e -> handleMove(row, col));

                buttons[i][j] = button;
                add(button);
            }
        }
    }

    private void handleMove(int i, int j) {
        if (board[i][j] != 0)
            return;

        board[i][j] = currentPlayer;

        if (currentPlayer == 1) {
            buttons[i][j].setText("X");
            currentPlayer = 2;
        } else {
            buttons[i][j].setText("O");
            currentPlayer = 1;
        }

        if (checkWin(board[i][j])) {
            JOptionPane.showMessageDialog(this,
                    "Gracz " + board[i][j] + " wygrywa!");
            resetGame();
        }else if(checkIfDraw()){
            JOptionPane.showMessageDialog(this,
                    "Remis");
            resetGame();
        }
    }

    private boolean checkWin(int player) {

        // wiersze
        for (int i = 0; i < size; i++) {
            boolean win = true;
            for (int j = 0; j < size; j++){
                if (board[i][j] != player){
                    win = false;
                }
            }
            if (win /** && checkIfDraw() */ ){
                return true;
            }
        }

        // kolumny
        for (int j = 0; j < size; j++) {
            boolean win = true;
            for (int i = 0; i < size; i++){
                if (board[i][j] != player){
                    win = false;
                }
            }
            if (win){
                return true;
            }
        }

        // przekątna \
        boolean win = true;
        for (int i = 0; i < size; i++){
            if (board[i][i] != player){
                win = false;
            }
        }
        if (win){
            return true;
        }

        // przekątna /
        win = true;
        for (int i = 0; i < size; i++){
            if (board[i][size - 1 - i] != player){
                win = false;
            }
        }

        return win;
    }

    private void resetGame() {
        currentPlayer = 1;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                board[i][j] = 0;
                buttons[i][j].setText("");
            }
        }
    }

    public boolean checkIfDraw(){
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if(board[i][j] == 0){
                    return false;
                }
            }
        }

        return true;
    }

    public static void main(String[] args) {

        String input = JOptionPane.showInputDialog("Podaj rozmiar planszy:");
        int size = Integer.parseInt(input);

        new KolkoIKrzyzykGUI(size);
    }
}
