public class TrywialnyKalkulator {
    private double a;
    private double b;

    public void ustawA( double a ) {
        this.a = a;
    }

    public void ustawB( double b ) {
        this.b = b;
    }

    public double dodaj_A_do_B() {
        return a + b;
    }

    public double odejmij_A_do_B() {
        return a - b;
    }

    public double odejmij_B_do_A() {
        return b - a;
    }
}
