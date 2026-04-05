import java.util.*;

class Main {
    public static final double PI = 3.141592654;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        //System.out.println("Podaj r i d: ");
        double r = scanner.nextDouble();
        double d = scanner.nextDouble();

        double x = r*r - (d*d)/4;
        System.out.printf(Locale.US, "%.2f%n", PI * x);

        scanner.close();
    }
}
