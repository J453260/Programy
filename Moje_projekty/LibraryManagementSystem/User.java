import java.util.*;

public class User {
    private String name;
    private int ID;

    public User(String name, int ID){
        LibraryUtils.requireNonEmpty(name, "Imię użytkownika");
        if (ID <= 0) {
            throw new IllegalArgumentException("ID musi być liczbą dodatnią");
        }
        this.name = name;
        this.ID = ID;
    }

    public int getID(){
        return ID;
    }

    public String getName() {
        return name;
    }
}
