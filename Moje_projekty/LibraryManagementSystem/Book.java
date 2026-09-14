public class Book {
    private int id;
    private String title;
    private String author;
    private String isbn;
    private boolean isAvailable = true;

    public Book(String title, String author, String isbn){
        LibraryUtils.requireNonEmpty(title, "Tytuł książki");
        LibraryUtils.requireNonEmpty(author, "Autor książki");
        LibraryUtils.requireNonEmpty(isbn, "ISBN książki");
        if(!LibraryUtils.isValidIsbn(isbn))
        {
            throw new IllegalArgumentException("Ten ISBN jest niepoprawny");
        }
        this.title = title;
        this.author = author;
        this.isbn = isbn;
    }

    public Book(int id, String title, String author, String isbn, boolean isAvailable) {
        this(title, author, isbn);
        this.id = id;
        this.isAvailable = isAvailable;
    }

    public String getTitle(){
        return title;
    }

    public String getAuthor(){
        return author;
    }

    public String getIsbn(){
        return isbn;
    }

    public boolean isAvailable(){
        return isAvailable;
    }

    public void setAvailable(boolean available){
        this.isAvailable = available;
    }

    @Override
    public String toString() {
        return String.format("[%d] %s - %s (ISBN: %s) | Dostępna: %s", id, title, author, isbn, isAvailable ? "TAK" : "NIE");
    }
}
