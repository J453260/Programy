import java.util.*;
class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        double a = scanner.nextDouble();
        double b = scanner.nextDouble();
        double c = scanner.nextDouble();
        scanner.close();

        if(a == 0 && b == c)
        {
            System.out.println("NWR");
        }
        else if(a == 0)
        {
            System.out.println("BR");
        }
        else
        {
            double wynik = (c - b) / a;
            System.out.printf(Locale.US, "%.2f\n", wynik);
        }
    }
}
