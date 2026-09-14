import java.util.*;

public class Library {
    //private LibraryUtils pomocniczeFunkcje = new LibraryUtils();
    //private Book book;
    //private User user;
    private Map<String, Book> books = new HashMap<>();
    private Map<Integer, User> users = new HashMap<>();

    public void addBook(Book book){
        if(!(LibraryUtils.isValidIsbn(book.getIsbn()))){
            //throw exeption;
            // ma rzucić wyjątek
            throw new IllegalArgumentException("Ten ISBN jest niepoprawny");
        }

        if(books.containsKey(book.getIsbn())){
            //throw exeption;
            // ma rzucić wyjątek
            throw new IllegalArgumentException("Książka z tym ISBN już istnieje");
        }

        books.put(book.getIsbn(), book);
    }

    public void removeBook(String isbn){
        Book book = books.get(isbn);
        if (book == null) {
            throw new IllegalArgumentException("Książka o podanym ISBN nie istnieje");
        }

        if (!book.isAvailable()) {
            throw new IllegalStateException("Nie można usunąć wypożyczonej książki");
        }
        books.remove(isbn, book);
    }

    public List<Book> findBooksByAuthor(String author){
        List<Book> result = new ArrayList<>();
        for (Book book : books.values()) {
            if (book.getAuthor().equalsIgnoreCase(author)) {
                result.add(book);
            }
        }
        return result;
    }

    public Optional<Book> findBookByIsbn(String isbn){
        return Optional.ofNullable(books.get(isbn));
    }

    public void registerUser(User user){
        if(users.containsKey(user.getID())){
            throw new IllegalArgumentException("Użytkownik z tym ID już istnieje");
        }
        users.put(user.getID(), user);
    }
}
