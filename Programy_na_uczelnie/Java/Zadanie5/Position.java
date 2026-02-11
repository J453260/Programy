/**
 * Położenie jako para liczb: kolumna i wiersz.
 *
 * @param col kolumna
 * @param row wiersz
 */

public record Position( int col, int row ) {
    public final String toString();

    /**
     * Returns a string representation of this record class. The representation contains the name of the class, followed by the name and value of each of the record components.
     * Specified by:
     * toString in class Record
     */

    public final int hashCode();

    /**
     * Returns a hash code value for this object. The value is derived from the hash code of each of the record components.
     * Specified by:
     * hashCode in class Record
     */

    public final boolean equals(Object o);

    /**
     * Indicates whether some other object is "equal to" this one. The objects are equal if the other object is of the same class and if all the record components are equal. All components in this record class are compared with the compare method from their corresponding wrapper classes.
     * Specified by:
     * equals in class Record
     * Parameters:
     * o - the object with which to compare
     * Returns:
     * true if this object is the same as the o argument; false otherwise.
     */

    public int static col();
    //Returns the value of the col record component.

    public int static row()
    //Returns the value of the row record component.
}