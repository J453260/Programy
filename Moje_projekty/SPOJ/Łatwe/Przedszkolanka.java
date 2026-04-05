import java.util.*;

class Main {
    static int NWD(int a, int b){
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    static long NWW(int a, int b){
        return (long)a / NWD(a, b) * b;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        //System.out.println("D: ");
        int D = scanner.nextInt();
        scanner.nextLine();

        while (D-- > 0) {
            //System.out.println("Podaj dwie liczby: ");
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            System.out.println(NWW(a, b));
        }

        scanner.close();
    }
}
