import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int D = scanner.nextInt();

        while (D-- > 0) {
            long a = scanner.nextLong();
            long result = 0;
            while(a-- > 0){
                long liczba = scanner.nextLong();
                result+=liczba;
            }

            System.out.println(result);
        }

        scanner.close();
    }
}
