#include "Stack.h"
#include <stdexcept>  // std::overflow_error, std::underflow_error
#include <cstddef>    // size_t

/**
 * @brief Implementacja stosu tablicowego (o stałej pojemności)
 *        zgodna z interfejsem Stack<T>.
 *
 * @tparam T Typ elementu przechowywanego na stosie.
 */
template <typename T>
class ArrayStack : public Stack<T>
{
private:
    T* data;           ///< Tablica przechowująca elementy stosu
    size_t capacity;   ///< Maksymalna pojemność stosu
    size_t topIndex;   ///< Liczba elementów aktualnie w stosie (indeks następnego wolnego miejsca)

public:
    /**
     * @brief Konstruktor tworzący stos o określonej pojemności.
     * @param maxSize Maksymalna liczba elementów, które mogą zostać odłożone na stos.
     */
    explicit ArrayStack(size_t maxSize)
        : data(new T[maxSize]), capacity(maxSize), topIndex(0) {}

    /**
     * @brief Destruktor — zwalnia pamięć tablicy.
     */
    ~ArrayStack() override
    {
        delete[] data;
    }

    /**
     * @brief Wstawia element na szczyt stosu.
     * @param item Element do wstawienia.
     * @throws std::overflow_error jeśli stos jest pełny.
     */
    void push(const T& item) override
    {
        if (topIndex == capacity)
            throw std::overflow_error("Stos tablicowy jest pelny.");
        data[topIndex++] = item;
    }

    /**
     * @brief Usuwa element ze szczytu stosu i zwraca jego wartość.
     * @return Element ze szczytu.
     * @throws std::underflow_error jeśli stos jest pusty.
     */
    T pop() override
    {
        if (isEmpty())
            throw std::underflow_error("Stos tablicowy jest pusty.");
        return data[--topIndex];
    }

    /**
     * @brief Zwraca wartość elementu na szczycie stosu bez jego usuwania.
     * @return Element ze szczytu stosu.
     * @throws std::underflow_error jeśli stos jest pusty.
     */
    T peek() const override
    {
        if (isEmpty())
            throw std::underflow_error("Stos tablicowy jest pusty.");
        return data[topIndex - 1];
    }

    /**
     * @brief Sprawdza, czy stos jest pusty.
     * @return true, jeśli stos nie zawiera elementów; false w przeciwnym razie.
     */
    bool isEmpty() const override
    {
        return topIndex == 0;
    }

    /**
     * @brief Zwraca liczbę elementów znajdujących się na stosie.
     */
    size_t size() const override
    {
        return topIndex;
    }
};
