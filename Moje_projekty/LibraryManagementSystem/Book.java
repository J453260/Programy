public class Book {
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
}
