import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Wczytujemy tekst w pętli, aby obsłużyć również teksty wielolinijkowe
        while (scanner.hasNextLine()) {
            String linia = scanner.nextLine();
            
            // Dzielimy linię na wyrazy według spacji
            String[] slowa = linia.split(" ");
            StringBuilder wynik = new StringBuilder();

            for (int i = 0; i < slowa.length; i++) {
                String slowo = slowa[i];
                if (!slowo.isEmpty()) {
                    // Pierwsze słowo zostaje bez zmian (lub z wielką literą, jeśli tak wpisano),
                    // a kolejne wyrazy mają zamienioną pierwszą literę na wielką
                    if (i > 0 && Character.isLowerCase(slowo.charAt(0))) {
                        slowo = Character.toUpperCase(slowo.charAt(0)) + slowo.substring(1);
                    }
                    wynik.append(slowo);
                }
            }
            
            System.out.println(wynik.toString());
        }
        
        scanner.close();
    }
}
