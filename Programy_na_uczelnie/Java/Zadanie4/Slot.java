/**
 Pojedynczy przedział czasowy, w którym stacja telewizyjna emituje program.
 Slot zaczyna się o godzinie atH minut atM i trwa duration minut.


Creates an instance of a Slot record class.
Parameters:
station - the value for the station record component
program - the value for the program record component
atH - the value for the atH record component
atM - the value for the atM record component
duration - the value for the duration record component
 */

public record Slot( String station, String program, int atH, int atM, int duration ) {

    public final String toString();
    /**
     * Returns a string representation of this record class. The representation contains the name of the class, followed by the name and value of each of the record components.
     * Specified by:
     * toString in class Record
     * Returns:
     * a string representation of this object
     */

    public final int hashCode();
    /**
     * Returns a hash code value for this object. The value is derived from the hash code of each of the record components.
     * Specified by:
     * hashCode in class Record
     * Returns:
     * a hash code value for this object
     */

    public final boolean equals(Object o);
    /**
     * Indicates whether some other object is "equal to" this one. The objects are equal if the other object is of the same class and if all the record components are equal. Reference components are compared with Objects::equals(Object,Object); primitive components are compared with the compare method from their corresponding wrapper classes.
     * Specified by:
     * equals in class Record
     * Parameters:
     * o - the object with which to compare
     * Returns:
     * true if this object is the same as the o argument; false otherwise.
     */

    public String station();
    /**
     * Returns the value of the station record component.
     * Returns:
     * the value of the station record component
     */

    public String program();
    /**
     * Returns the value of the program record component.
     * Returns:
     * the value of the program record component
     */

    public int atH();
    /**
     * Returns the value of the atH record component.
     * Returns:
     * the value of the atH record component
     */

    public int atM();
    /**
     * Returns the value of the atM record component.
     * Returns:
     * the value of the atM record component
     */

    public int duration();
    /**
     * Returns the value of the duration record component.
     * Returns:
     * the value of the duration record component
     */
}