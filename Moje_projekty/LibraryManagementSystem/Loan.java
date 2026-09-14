import java.time.LocalDate;

public class Loan {
    private final User user;
    private final Book book;
    private final LocalDate loanDate;
    private final LocalDate dueDate;
    private LocalDate returnDate; // null dopóki książka nie wróci

    public Loan(User user, Book book, LocalDate loanDate, LocalDate dueDate){
        this.user = user;
        this.book = book;
        this.loanDate = loanDate;
        this.dueDate = dueDate;
    }

    public User getUser() { return user; }
    public Book getBook() { return book; }
    public LocalDate getLoanDate() { return loanDate; }
    public LocalDate getDueDate() { return dueDate; }
    public LocalDate getReturnDate() { return returnDate; }

    public void setReturnDate(LocalDate returnDate) {
        this.returnDate = returnDate;
    }

    public boolean isOverdue() {
        return returnDate == null && LocalDate.now().isAfter(dueDate);
    }
}
