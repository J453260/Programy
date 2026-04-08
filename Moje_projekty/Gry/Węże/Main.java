import java.util.*;
//import static java.lang.Thread.sleep;

public class Main{
    static volatile boolean running = true;
    public static void main(String[] argv){
        Scanner scanner = new Scanner(System.in);

        System.out.print("Podaj rozmiar planszy: ");
        int n = scanner.nextInt();
        Plansza plansza = new Plansza(n);
        plansza.rysujPlansze();

        System.out.print("Podaj współrzędne startowe: ");
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        plansza.stworzWeza(x, y);
        plansza.rysujPlansze();
        //plansza.dodajJedzenie();

        // Wątek czytający klawiaturę
        Thread inputThread = new Thread(() -> {
            while(running){
                char key = scanner.next().charAt(0);
                Direction d = Waz.zmienKierunek(key);

                if(d != null){
                    plansza.waz.direction = d;
                }
            }
        });

        inputThread.setDaemon(true);
        inputThread.start();

        // Pętla gry
        while(running){

            plansza.waz.ruch(plansza.waz.direction);

            int headX = plansza.waz.segments.getFirst()[0];
            int headY = plansza.waz.segments.getFirst()[1];

            if(plansza.czyPozaPlansza(headX, headY)){
                System.out.println("Game Over");
                running = false;
                break;
            }

            plansza.aktualizujPlansze();

            System.out.print("\033[H\033[2J");
            System.out.flush();

            plansza.rysujPlansze();

            try{
                Thread.sleep(1000);
            }catch(InterruptedException e){
                e.printStackTrace();
            }
        }

        scanner.close();
    }
}