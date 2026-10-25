public class Main {
    public static void main(String[] args) {
        Display wyswietlacz = new Display("0000", 0);
        System.out.println("Hello, World!");
        System.out.println("This is a test");
        wyswietlacz.set();
        wyswietlacz.plus();

        wyswietlacz.set();
        wyswietlacz.plus();
        wyswietlacz.plus();
        wyswietlacz.plus();

        wyswietlacz.set();
        wyswietlacz.plus();
        wyswietlacz.plus();
        wyswietlacz.plus();

        wyswietlacz.set();
        wyswietlacz.plus();
        wyswietlacz.plus();
        wyswietlacz.plus();
        wyswietlacz.plus();
        wyswietlacz.plus();
        wyswietlacz.plus();

        System.out.println(wyswietlacz.get());
    }
}
