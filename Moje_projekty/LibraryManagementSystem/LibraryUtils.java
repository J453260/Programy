import java.time.LocalDate;
import java.time.temporal.ChronoUnit;
import java.util.List;
import java.util.stream.Collectors;

public class LibraryUtils {

    // Sprawdza poprawność formatu ISBN (uproszczona wersja: 13 cyfr)
    public static boolean isValidIsbn(String isbn) {
        return isbn != null && isbn.matches("\\d{13}");
    }

    // Liczy liczbę dni między dwiema datami (przydatne do kar/terminów)
    public static long daysBetween(LocalDate start, LocalDate end) {
        return ChronoUnit.DAYS.between(start, end);
    }

    // Formatuje tytuł książki do jednolitego stylu (Wielka Litera Każdego Słowa)
    public static String formatTitle(String title) {
        String[] words = title.trim().toLowerCase().split("\\s+");
        StringBuilder result = new StringBuilder();
        for (String word : words) {
            if (!word.isEmpty()) {
                result.append(Character.toUpperCase(word.charAt(0)))
                        .append(word.substring(1))
                        .append(" ");
            }
        }
        return result.toString().trim();
    }

    // Filtruje listę książek po dostępności
    public static List<Book> filterAvailable(List<Book> books) {
        return books.stream().filter(Book::isAvailable).collect(Collectors.toList());
    }

    // Waliduje, czy pole tekstowe nie jest puste/nullowe
    public static void requireNonEmpty(String value, String fieldName) {
        if (value == null || value.trim().isEmpty()) {
            throw new IllegalArgumentException(fieldName + " nie może być puste");
        }
    }
}
