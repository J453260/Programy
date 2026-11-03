import java.util.Set;

/**
 * Klasa reprezentuje szafkę do przechowywania przedmiotów na półkach.
 */
public abstract class Szafka {
    /**
     * Na półce wolno położyć maksymalnie tyle przedmiotów ile tu podano. Pojemność
     * półki może ulec zmianie w dowolnym momencie. Należy postępować zgodnie z
     * instrukcją w opisie zadania.
     *
     * @param przedmiotow pojemność półki w przedmiotach
     */
    abstract public void pojemnoscPolki(int przedmiotow);

    /**
     * Na półkę o numerze numerPolki kładziemy przedmiot. Odkładając przedmiot na
     * półkę należy przestrzegać zasad omówionych w opisie zadania.
     *
     * @param numerPolki numer półki
     * @param przedmiot  to co umieszczamy na półce
     */
    abstract public void naPolke(int numerPolki, String przedmiot);

    /**
     * Usuwamy wszystko co znajduje się na półce o podanym numerze. Numer półki może
     * być dowolny, w tym wcześniej nieużywany.
     *
     * @param numerPolki numer sprzątanej półki.
     */
    abstract public void usunWszystkoZPolki(int numerPolki);

    /**
     * Metoda zwraca zbiór przedmiotów, które umieszczone zostały na półce. Jeśli
     * półka jest pusta lub nieznana (jej numer nie pojawił się wcześniej), to
     * metoda zwraca zbiór pusty.
     *
     * @param numerPolki numer sprawdzanej półki
     * @return zbiór przedmiotów na sprawdzanej półce.
     */
    abstract Set<String> coJestNaPolce(int numerPolki);
}