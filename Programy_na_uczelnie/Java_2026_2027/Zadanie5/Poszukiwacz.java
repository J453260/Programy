import java.util.*;

public class Poszukiwacz implements InterfejsPoszukiwania {
    public Kolor kolorRobota;
    public Kolor kolorPoszukiwany;
    public InterfejsRobota robot;
    public Set<Kratka> odwiedzone = new HashSet<>();
    public Kratka wynik;
    private KolorowaKratka kratkaStartowa;

    public void ustawKratkeStartowa(KolorowaKratka kratka) {
        this.kratkaStartowa = Objects.requireNonNull(kratka);
    }

    public boolean DFS(KolorowaKratka aktualna){
        Kratka pozycja = aktualna.kratka();
        odwiedzone.add(pozycja);

        if(aktualna.kolor() == kolorPoszukiwany){
            wynik = pozycja;
            return true;
        }

        for(Kierunek kierunek : Kierunek.values()){
            KolorowaKratka następna = robot.wykonajKrok(kierunek);

            if(następna.kratka().equals(pozycja)){
                //jest ściana
                continue;
            }

            if(odwiedzone.contains(następna.kratka())){
                robot.wykonajKrok(kierunekPrzeciwny(kierunek));
                continue;
            }

            if(DFS(następna)){
                return true;
            }

            robot.wykonajKrok(kierunekPrzeciwny(kierunek));
        }

        return false;
    }

    public Kierunek kierunekPrzeciwny(Kierunek kierunek) {
        return switch (kierunek) {
            case W_GÓRĘ -> Kierunek.W_DÓŁ;
            case W_DÓŁ -> Kierunek.W_GÓRĘ;
            case W_LEWO -> Kierunek.W_PRAWO;
            case W_PRAWO -> Kierunek.W_LEWO;
        };
    }

    @Override
    public void ustawKolorRobota( Kolor kolor ){
        this.kolorRobota = kolor;
    }

    @Override
    public void ustawKolorPoszukiwany( Kolor kolor ){
        this.kolorPoszukiwany = kolor;
    }

    @Override
    public void ustawInterfejsRobota( InterfejsRobota robot ){
        this.robot = robot;
    }

    @Override
    public void wyszukaj() {
        odwiedzone.clear();
        wynik = null;
        DFS(kratkaStartowa);
    }

    @Override
    public Kratka zwróćZnalezionąKratkę(){
        return wynik;
    }
}