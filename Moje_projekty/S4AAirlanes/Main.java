package org.example;
import java.util.Scanner;

public class Main{
    static Samolot[] samoloty;

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();//Liczba tras
        int q = scanner.nextInt();//Liczba zapytań
        samoloty = new Samolot[n+1];

        for(int i=1; i<=n; i++){

            //Wczytywanie maks osób dla samolotu o id = i
            int pasazerowie = scanner.nextInt();
            samoloty[i] = new Samolot(pasazerowie, i);
        }

        for (int i = 0; i < q; i++) {

            char operacja = scanner.next().charAt(0);

            switch (operacja) {

                case 'P': {
                    int trasa = scanner.nextInt();
                    int p = scanner.nextInt();
                    long t = scanner.nextLong();

                    samoloty[trasa].zapytanieP(p, t);
                    break;
                }

                case 'C': {
                    int trasa = scanner.nextInt();
                    long t = scanner.nextLong();

                    samoloty[trasa].zapytanieC(t);
                    break;
                }

                case 'A': {
                    int trasa = scanner.nextInt();
                    int p = scanner.nextInt();
                    long t = scanner.nextLong();

                    // nowy samolot od nowa
                    samoloty[trasa] = new Samolot(p, trasa);
                    samoloty[trasa].zapytanieA(p, t);

                    break;
                }

                case 'Q': {
                    int i1 = scanner.nextInt();
                    int i2 = scanner.nextInt();
                    long t = scanner.nextLong();

                    long suma = 0;

                    for (int k = i1; k <= i2; k++) {
                        suma += samoloty[k].zapytanieQ(t);
                    }

                    System.out.println(suma);
                    break;
                }

                default:
                    System.out.println("Nieznana operacja");
            }
        }
        scanner.close();
    }
}