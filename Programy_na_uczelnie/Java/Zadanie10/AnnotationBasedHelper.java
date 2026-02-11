import java.util.*;
import java.lang.reflect.Field;
import java.lang.reflect.Modifier;

public class AnnotationBasedHelper implements SQLiteHelper {
    private static final Map<Class<?>, String> naTypy = new HashMap<>();

    static {
        naTypy.put(int.class, "INTEGER");
        naTypy.put(long.class, "INTEGER");
        naTypy.put(Integer.class, "INTEGER");
        naTypy.put(Long.class, "INTEGER");

        naTypy.put(float.class, "REAL");
        naTypy.put(double.class, "REAL");
        naTypy.put(Float.class, "REAL");
        naTypy.put(Double.class, "REAL");

        naTypy.put(String.class, "TEXT");
    }

    @Override
    public String toSQL(Object object, String tableName){
        String ciagZnakow = "CREATE TABLE " + tableName + " (\n";

        Class<?> klasa = object.getClass();
        Field[] pola = klasa.getDeclaredFields();

        boolean pierwsza = true;

        for(Field pole : pola){
            // Sprawdzamy czy pole ma adnotację @SQL
            if(!Modifier.isPublic(pole.getModifiers()) || !pole.isAnnotationPresent(SQL.class)) {
                continue;
            }

            String nazwa = pole.getName();
            Class<?> typ = pole.getType();
            String typSQL = naTypy.get(typ);

            if(typSQL == null) {
                continue;
            }

            if(!pierwsza) {
                ciagZnakow += ",\n";
            }
            pierwsza = false;

            ciagZnakow += nazwa + " " + typSQL;
        }

        if(pierwsza) {
            throw new IllegalArgumentException(
                    "Brak pól z adnotacją @SQL w klasie " + klasa.getName()
            );
        }

        ciagZnakow += " );";

        return ciagZnakow;
    }
}