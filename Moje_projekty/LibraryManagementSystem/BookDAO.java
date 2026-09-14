import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class BookDAO {

    // 1. Zapis książki do bazy danych
    public boolean addBook(Book book) {
        String sql = "INSERT INTO Books (Title, Author, ISBN, IsAvailable) VALUES (?, ?, ?, ?)";

        try (Connection conn = DatabaseManager.getConnection();
             PreparedStatement stmt = conn.prepareStatement(sql)) {

            stmt.setString(1, book.getTitle());
            stmt.setString(2, book.getAuthor());
            stmt.setString(3, book.getIsbn());
            stmt.setBoolean(4, book.isAvailable());

            int rowsInserted = stmt.executeUpdate();
            return rowsInserted > 0;

        } catch (SQLException e) {
            // Kod 2627 / 2601 w MS SQL oznacza naruszenie więzów unikalności (UNIQUE constraint)
            if (e.getErrorCode() == 2627 || e.getErrorCode() == 2601) {
                System.err.println("Błąd: Książka o podanym ISBN (" + book.getIsbn() + ") już istnieje w bazie!");
            } else {
                System.err.println("Błąd zapisu do bazy: " + e.getMessage());
            }
            return false;
        }
    }

    // 2. Pobranie wszystkich książek
    public List<Book> getAllBooks() {
        List<Book> books = new ArrayList<>();
        String sql = "SELECT Id, Title, Author, ISBN, IsAvailable FROM Books";

        try (Connection conn = DatabaseManager.getConnection();
             PreparedStatement stmt = conn.prepareStatement(sql);
             ResultSet rs = stmt.executeQuery()) {

            while (rs.next()) {
                int id = rs.getInt("Id");
                String title = rs.getString("Title");
                String author = rs.getString("Author");
                String isbn = rs.getString("ISBN");
                boolean isAvailable = rs.getBoolean("IsAvailable");

                // Wykorzystuje konstruktor Book z identyfikatorem ID z bazy
                books.add(new Book(id, title, author, isbn, isAvailable));
            }

        } catch (SQLException e) {
            System.err.println("Błąd odczytu z bazy: " + e.getMessage());
        }

        return books;
    }

    // 3. Wyszukiwanie książki po numerze ISBN
    public Optional<Book> findBookByIsbn(String isbn) {
        String sql = "SELECT Id, Title, Author, ISBN, IsAvailable FROM Books WHERE ISBN = ?";

        try (Connection conn = DatabaseManager.getConnection();
             PreparedStatement stmt = conn.prepareStatement(sql)) {

            stmt.setString(1, isbn);

            try (ResultSet rs = stmt.executeQuery()) {
                if (rs.next()) {
                    int id = rs.getInt("Id");
                    String title = rs.getString("Title");
                    String author = rs.getString("Author");
                    boolean isAvailable = rs.getBoolean("IsAvailable");

                    return Optional.of(new Book(id, title, author, isbn, isAvailable));
                }
            }

        } catch (SQLException e) {
            System.err.println("Błąd podczas wyszukiwania książki: " + e.getMessage());
        }

        return Optional.empty();
    }

    // 4. Zmiana statusu dostępności książki (wypożyczenie/zwrot)
    public boolean updateAvailability(String isbn, boolean isAvailable) {
        String sql = "UPDATE Books SET IsAvailable = ? WHERE ISBN = ?";

        try (Connection conn = DatabaseManager.getConnection();
             PreparedStatement stmt = conn.prepareStatement(sql)) {

            stmt.setBoolean(1, isAvailable);
            stmt.setString(2, isbn);

            return stmt.executeUpdate() > 0;

        } catch (SQLException e) {
            System.err.println("Błąd aktualizacji statusu książki: " + e.getMessage());
            return false;
        }
    }
}
