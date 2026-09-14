import java.util.List;
import java.util.Optional;
import java.util.Scanner;

public class Main {

    private static final BookDAO bookDAO = new BookDAO();
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        boolean running = true;

        System.out.println("=========================================");
        System.out.println("  SYSTEM ZARZĄDZANIA BIBLIOTEKĄ (SQL)  ");
        System.out.println("=========================================");

        while (running) {
            wyświetlMenu();
            System.out.print("Wybierz opcję: ");
            String choice = scanner.nextLine().trim();

            switch (choice) {
                case "1" -> dodajKsiążkę();
                case "2" -> wyświetlWszystkieKsiążki();
                case "3" -> szukajKsiążkiPoIsbn();
                case "4" -> zmieńDostępnośćKsiążki();
                case "0" -> {
                    running = false;
                    System.out.println("\nZamykanie programu... Do widzenia!");
                }
                default -> System.out.println("\n[!] Nieprawidłowy wybór. Spróbuj ponownie.\n");
            }
        }

        scanner.close();
    }

    private static void wyświetlMenu() {
        System.out.println("\n--- MENU GŁÓWNE ---");
        System.out.println("1. Dodaj nową książkę");
        System.out.println("2. Wyświetl wszystkie książki");
        System.out.println("3. Wyszukaj książkę po ISBN");
        System.out.println("4. Zmień status dostępności (Wypożycz / Zwróć)");
        System.out.println("0. Wyjdź z programu");
        System.out.println("-------------------");
    }

    private static void dodajKsiążkę() {
        System.out.println("\n--- DODAWANIE NOWEJ KSIĄŻKI ---");

        System.out.print("Podaj tytuł: ");
        String title = scanner.nextLine();

        System.out.print("Podaj autora: ");
        String author = scanner.nextLine();

        System.out.print("Podaj numer ISBN: ");
        String isbn = scanner.nextLine();

        try {
            // Konstruktor Book automatycznie wykona walidację przez LibraryUtils
            Book newBook = new Book(title, author, isbn);

            boolean success = bookDAO.addBook(newBook);
            if (success) {
                System.out.println("[✓] Książka została pomyślnie dodana do bazy danych!");
            }

        } catch (IllegalArgumentException e) {
            System.out.println("[!] Błąd walidacji danych: " + e.getMessage());
        }
    }

    private static void wyświetlWszystkieKsiążki() {
        System.out.println("\n--- LISTA KSIĄŻEK W BAZIE ---");
        List<Book> books = bookDAO.getAllBooks();

        if (books.isEmpty()) {
            System.out.println("Brak książek w bazie danych.");
        } else {
            for (Book book : books) {
                System.out.println(book);
            }
        }
    }

    private static void szukajKsiążkiPoIsbn() {
        System.out.println("\n--- WYSZUKIWANIE KSIĄŻKI ---");
        System.out.print("Podaj ISBN książki: ");
        String isbn = scanner.nextLine();

        Optional<Book> foundBook = bookDAO.findBookByIsbn(isbn);

        if (foundBook.isPresent()) {
            System.out.println("[✓] Znaleziono książkę: " + foundBook.get());
        } else {
            System.out.println("[!] Nie znaleziono książki o podanym ISBN.");
        }
    }

    private static void zmieńDostępnośćKsiążki() {
        System.out.println("\n--- ZMIANA DOSTĘPNOŚCI KSIĄŻKI ---");
        System.out.print("Podaj ISBN książki: ");
        String isbn = scanner.nextLine();

        Optional<Book> foundBook = bookDAO.findBookByIsbn(isbn);

        if (foundBook.isPresent()) {
            Book book = foundBook.get();
            boolean newStatus = !book.isAvailable(); // Zmiana statusu na przeciwny

            boolean updated = bookDAO.updateAvailability(isbn, newStatus);
            if (updated) {
                String akcja = newStatus ? "zwrócona" : "wypożyczona";
                System.out.println("[✓] Status zmieniony! Książka została " + akcja + ".");
            }
        } else {
            System.out.println("[!] Nie znaleziono książki o podanym ISBN.");
        }
    }
}
