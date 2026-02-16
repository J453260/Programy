import java.util.*;

class Main {
    public static boolean czyPalindrom(int a){
        String liczba = String.valueOf(a);
        int n = liczba.length();
        for(int i=0; i < n/2; i++){
            if(liczba.charAt(i) != liczba.charAt(n - i - 1)){
                return false;
            }
        }

        return true;
    }

    public static int odwracanie(int a){
        String liczba = String.valueOf(a);
        String nowaLiczba = "";
        int n = liczba.length();
        for(int i = 0; i<n; i++){
            nowaLiczba += liczba.charAt(n - i - 1);
        }

        int nLiczba = Integer.parseInt(nowaLiczba);

        return nLiczba;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        //System.out.println("D: ");
        int D = scanner.nextInt();
        scanner.nextLine();

        while (D-- > 0) {
            //System.out.println("Podaj liczbę: ");
            int a = scanner.nextInt();
            int licznik = 0;

            while(!czyPalindrom(a)){
                a = a + odwracanie(a);
                licznik++;
            }

            System.out.println(a + " " + licznik);
        }

        scanner.close();
    }
}
