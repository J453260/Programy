#ifndef JU_COURSE_ALGORITHMS_1_LIST_H
#define JU_COURSE_ALGORITHMS_1_LIST_H

#include <stdexcept>

/**
 * @brief Abstrakcyjny interfejs (Abstrakcyjny Typ Danych) dla Listy.
 * Ta klasa definiuje "kontrakt" dla kontenera sekwencyjnego.
 * Jest szablonem (template) przechowującym dowolny typ danych. Wszystkie funkcje są czysto wirtualne,
 * co oznacza, że konkretne implementacje MUSZĄ je zapewnić.
 * Ten interfejs wymusza sprawdzanie granic. Każdy dostęp (pobranie, wstawienie, usunięcie)
 * z nieprawidłowym indeksem musi zgłosić (rzucić) std::out_of_range.
 */

template <typename T>
class List
{
private:
    /*
    T* data;          // wskaźnik na tablicę elementów
    size_t size;      // liczba aktualnych elementów
    size_t capacity;  // maksymalna liczba elementów w tablicy
    */

    void resize(size_t new_capacity); // prywatna metoda powiększania tablicy

public:
    /**
     * @brief Wirtualny destruktor.
     * Jest to kluczowe, aby zapewnić poprawne wywołanie destruktorów klas pochodnych,
     * gdy obiekt jest usuwany przez wskaźnik klasy bazowej (np. List<T>* list = new ArrayList<T>(); delete list;).
     */
    virtual ~List() = default;

    /**
     * @brief Dodaje element na koniec listy.
     * @param data Dane do dodania.
     */
    virtual void append(const T &data) = 0;

    /**
     * @brief Wstawia element pod określonym indeksem.
     * @param index Pozycja, na którą należy wstawić (0 <= index <= size()).
     * Wstawienie na pozycji size() jest równoważne z append().
     * @param data Dane do wstawienia.
     * @throws std::out_of_range jeśli index < 0 lub index > size().
     */
    virtual void insert(int index, const T &data) = 0;

    /**
     * @brief Usuwa element pod określonym indeksem.
     * @param index Pozycja do usunięcia (0 <= index < size()).
     * @throws std::out_of_range jeśli lista jest pusta lub indeks jest poza zakresem.
     */
    virtual void remove(int index) = 0;

    /**
     * @brief Pobiera element pod określonym indeksem.
     * @param index Pozycja do pobrania (0 <= index < size()).
     * @return Element.
     * @throws std::out_of_range jeśli lista jest pusta lub indeks jest poza zakresem.
     */
    virtual T get(int index) = 0;

    /**
     * @brief Ustawia (zastępuje) element pod określonym indeksem.
     * @param index Pozycja do modyfikacji (0 <= index < size()).
     * @param element Nowe dane do umieszczenia na tym indeksie.
     * @throws std::out_of_range jeśli lista jest pusta lub indeks jest poza zakresem.
     */
    virtual void set(int index, const T &element) = 0;

    /**
     * @brief Zwraca liczbę elementów aktualnie znajdujących się na liście.
     * @return Rozmiar (liczba całkowita).
     */
    [[nodiscard]] virtual int size() const = 0;

    /**
     * @brief Sprawdza, czy lista zawiera jakiekolwiek elementy.
     * @return true jeśli size() == 0, w przeciwnym razie false.
     */
    [[nodiscard]] virtual bool isEmpty() const = 0;

    /**
     * @brief Usuwa wszystkie elementy z listy, ustawiając jej rozmiar na 0.
     */
    virtual void clear() = 0;
};

#endif //JU_COURSE_ALGORITHMS_1_LIST_H
