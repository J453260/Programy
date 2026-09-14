import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DatabaseManager {

    private static final String URL = "jdbc:sqlserver://localhost\\SQLEXPRESS;databaseName=LibraryDB;encrypt=true;trustServerCertificate=true";

    private static final String USER = "library_app";
    private static final String PASSWORD = "TwojeSilneHaslo123!";

    private DatabaseManager() {}

    public static Connection getConnection() throws SQLException {
        return DriverManager.getConnection(URL, USER, PASSWORD);
    }
}
