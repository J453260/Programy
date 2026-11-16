/**
 * Typ wyliczeniowy Kierunek reprezentuje różne kierunki ruchu w planszy.
 * Dla każdego kierunku podano jak jego wybór wpływa na pozycję robota.
 */
public enum Kierunek {
    /**
     * Inkrementacja wiersza
     */
    W_GÓRĘ,
    /**
     * Dekrementacja wiersza
     */
    W_DÓŁ,
    /**
     * Dekrementacja kolumny
     */
    W_LEWO,
    /**
     * Inkrementacja kolumny
     */
    W_PRAWO;
}