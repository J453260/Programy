import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int D = sc.nextInt();

        while (D-- > 0) {
            long a = sc.nextLong();
            long b = sc.nextLong();

            if (b == 0) {
                System.out.println(1);
                continue;
            }

            int lastDigit = (int)(a % 10);
            int exp = (int)(b % 4);
            if (exp == 0) exp = 4;

            int result = 1;
            for (int i = 0; i < exp; i++) {
                result = (result * lastDigit) % 10;
            }

            System.out.println(result);
        }

        sc.close();
    }
}