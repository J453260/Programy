public class JednakMozna {
    private int pole_jeden;
    private int pole_dwa;
    private int pole_trzy;

    public String toString() {
        // brak kodu
        return "jeden -> " + pole_jeden + ", dwa -> " + pole_dwa + ", trzy -> " + pole_trzy;
    }

    // konstruktor(y) ???
    public JednakMozna() {
        pole_jeden = 1;
        pole_dwa = 2;
        pole_trzy = 3;
    }

    public JednakMozna( int jeden ) {
        pole_jeden = jeden;
        pole_dwa = 2;
        pole_trzy = 3;
    }

    public JednakMozna( int jeden, int dwa ) {
        pole_jeden = jeden;
        pole_dwa = dwa;
        pole_trzy = 3;
    }

    public JednakMozna( int jeden, int dwa, int trzy ) {
        pole_jeden = jeden;
        pole_dwa = dwa;
        pole_trzy = trzy;
    }

    public static void main( String[] argv ) {
        JednakMozna jm1 = new JednakMozna();
        JednakMozna jm2 = new JednakMozna( 11 );
        JednakMozna jm3 = new JednakMozna( 11, 22 );
        JednakMozna jm4 = new JednakMozna( 11, 22, 33 );

        System.out.println( "jm1 : " + jm1 ); // powinno sie pojawic jm1 : jeden -> 1, dwa -> 2, trzy -> 3
        System.out.println( "jm2 : " + jm2 ); // powinno sie pojawic jm2 : jeden -> 11, dwa -> 2, trzy -> 3
        System.out.println( "jm3 : " + jm3 ); // powinno sie pojawic jm3 : jeden -> 11, dwa -> 22, trzy -> 3
        System.out.println( "jm4 : " + jm4 ); // powinno sie pojawic jm4 : jeden -> 11, dwa -> 22, trzy -> 33
    }
}