import java.time.LocalDate;
import java.util.*;

public class LoanManager {
    static final int RETURN_INTERVAL = 14;
    static final double FINE_PER_DAY = 1.0; //kara za przekroczenie terminu o 1 dzień
    private Map<Integer, List<Loan>> loansByUser = new HashMap<>();

    private LocalDate calculateDueDate(LocalDate loanDate) {
        // LocalDate DueDate = LocalDate.now();
        // dzisiejsza data
        // należy dodać do niej czas na oddanie - 14 dni
        loanDate = loanDate.plusDays(RETURN_INTERVAL);

        return loanDate;
    }

    public double calculateFine(LocalDate dueDate, LocalDate returnDate)
    {
        double fine = 0.0;
        if(returnDate.isBefore(dueDate)) {
            return fine;
        }

        long dni = LibraryUtils.daysBetween(dueDate, returnDate);
        fine = dni * FINE_PER_DAY;

        return fine;
    }

    private Optional<Loan> findActiveLoan(User user, Book book) {
        List<Loan> userLoans = loansByUser.get(user.getID());
        if (userLoans != null) {
            for (Loan loan : userLoans) {
                if (loan.getBook().getIsbn().equals(book.getIsbn()) && loan.getReturnDate() == null) {
                    return Optional.of(loan);
                }
            }
        }
        return Optional.empty();
    }

    public void borrowBook(User user, Book book){
        if(!book.isAvailable()){
            throw new IllegalArgumentException("Książka niedostępna");
        }

        LocalDate now = LocalDate.now();

        LocalDate dueDate = calculateDueDate(now);
        Loan loan1 = new Loan(user, book, now, dueDate);
        loansByUser.computeIfAbsent(user.getID(), k -> new ArrayList<>()).add(loan1);
        book.setAvailable(false);
    }

    public double returnBook(User user, Book book)
    {
        Loan loan = findActiveLoan(user, book).orElseThrow(() -> new IllegalArgumentException("..."));
        loan.setReturnDate(LocalDate.now());
        book.setAvailable(true);

        return calculateFine(loan.getDueDate(), loan.getReturnDate());
    }

    public List<Loan> getOverdueLoans() {
        List<Loan> overdueLoans = new ArrayList<>();
        for (List<Loan> userLoans : loansByUser.values()) {
            for (Loan loan : userLoans) {
                if (loan.isOverdue()) {
                    overdueLoans.add(loan);
                }
            }
        }
        return overdueLoans;
    }
}
