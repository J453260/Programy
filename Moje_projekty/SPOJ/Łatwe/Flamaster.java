import java.util.*;

class Main {
    Map<Character, Integer> licznik = new HashMap<>();

    public static String litery(String wyraz){
        StringBuilder wynik = new StringBuilder();
        int n = wyraz.length();
        //AAAABBBBBBBB n = 12
        //A4B8
        int i=0;
        while(i<n) {
            char c = wyraz.charAt(i);
            int licznik = 1;

            while (i + licznik < n && wyraz.charAt(i + licznik) == c) {
                licznik++;
            }

            if (licznik >= 3) {
                wynik.append(c).append(licznik);
            } else {
                for (int j = 0; j < licznik; j++) {
                    wynik.append(c);
                }
            }

            i += licznik;
            if(i>n){
                break;
            }
        }

        return wynik.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        //System.out.println("D: ");
        int D = scanner.nextInt();
        scanner.nextLine();

        while (D-- > 0) {
            String a = scanner.nextLine();
            String wynik = litery(a);
            System.out.println(wynik);
        }

        scanner.close();
    }
}
