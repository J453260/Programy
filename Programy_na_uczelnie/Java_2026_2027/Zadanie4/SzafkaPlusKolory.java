import java.util.Map;

/**
 * Klasa reprezentuje szafkę do przechowywania przedmiotów na półkach.
 * Przedmioty rozróżniane są dodatkowo za pomocą kolorów.
 */
public abstract class SzafkaPlusKolory {
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
     * @param kolor      kolor umieszczanego na półce przedmiotu
     */
    abstract public void naPolke(int numerPolki, String przedmiot, Kolor kolor);

    /**
     * Usuwamy wszystko co znajduje się na półce o podanym numerze. Numer półki może
     * być dowolny, w tym wcześniej nieużywany.
     *
     * @param numerPolki numer sprzątanej półki.
     */
    abstract public void usunWszystkoZPolki(int numerPolki);

    /**
     * Metoda zwraca mapę przedmiotów, które umieszczone zostały na półce. Jeśli
     * półka jest pusta lub nieznana (jej numer nie pojawił się wcześniej), to
     * metoda zwraca pustą mapę. Metoda zwraca kopię mapy, zmiany w zwróconej mapie
     * nie wpłyną na stan obiektu.
     *
     * @param numerPolki numer sprawdzanej półki
     * @return mapa przedmiotów na sprawdzanej półce. Kluczem mapy jest kolor,
     *         wartością jest nazwa przedmiotu o tym kolorze.
     */
    abstract Map<Kolor, String> coJestNaPolce(int numerPolki);
}