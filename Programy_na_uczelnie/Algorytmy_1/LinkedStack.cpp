#ifndef JU_COURSE_ALGORITHMS_1_LINKEDSTACK_H
#define JU_COURSE_ALGORITHMS_1_LINKEDSTACK_H

#include "Stack.h"
#include <stdexcept>  // std::underflow_error
#include <cstddef>    // size_t

/**
 * @brief Implementacja stosu wskaźnikowego (lista jednokierunkowa)
 *        zgodna z interfejsem Stack<T>.
 *
 * @tparam T Typ elementu przechowywanego na stosie.
 */
template <typename T>
class LinkedStack : public Stack<T>
{
private:
    /**
     * @brief Węzeł listy reprezentujący jeden element stosu.
     */
    struct Node
    {
        T data;
        Node* next;
        explicit Node(const T& d, Node* n = nullptr)
            : data(d), next(n) {}
    };

    Node* topNode;   ///< wskaźnik na szczyt stosu
    size_t count;    ///< liczba elementów w stosie

public:
    /**
     * @brief Konstruktor domyślny — tworzy pusty stos.
     */
    LinkedStack() : topNode(nullptr), count(0) {}

    /**
     * @brief Wirtualny destruktor.
     * Niezbędny dla klasy bazowej z funkcjami wirtualnymi, aby zapewnić
     * poprawne wywołanie destruktorów klas pochodnych.
     */
    ~LinkedStack() override
    {
        while (!isEmpty())
            pop();
    }

    /**
     * @brief Odkłada (wstawia) element na szczyt stosu.
     * @param item Element do wstawienia.
     * @throws std::overflow_error jeśli stos jest pełny (specyficzne dla implementacji o stałym rozmiarze).
     */
    void push(const T& item) override
    {
        topNode = new Node(item, topNode);
        ++count;
    }

    /**
     * @brief Zdejmuje (usuwa) element ze szczytu stosu i zwraca go.
     * @return Wartość elementu, który znajdował się na szczycie.
     * @throws std::underflow_error jeśli stos jest pusty.
     */
    T pop() override
    {
        if (isEmpty())
            throw std::underflow_error("Stos wskaznikowy jest pusty.");

        Node* temp = topNode;
        T value = temp->data;
        topNode = topNode->next;
        delete temp;
        --count;
        return value;
    }

    /**
     * @brief Zwraca kopię (wartość) elementu ze szczytu stosu bez usuwania go.
     * @return Wartość elementu na szczycie.
     * @throws std::underflow_error jeśli stos jest pusty.
     */
    T peek() const override
    {
        if (isEmpty())
            throw std::underflow_error("Stos wskaznikowy jest pusty.");
        return topNode->data;
    }

    /**
     * @brief Sprawdza, czy stos jest pusty.
     * @return true jeśli stos nie zawiera żadnych elementów, false w przeciwnym razie.
     */
    bool isEmpty() const override
    {
        return topNode == nullptr;
    }

    /**
     * @brief Zwraca liczbę elementów aktualnie znajdujących się na stosie.
     * @return Liczba elementów jako size_t.
     */
    size_t size() const override
    {
        return count;
    }
};

#endif // JU_COURSE_ALGORITHMS_1_LINKEDSTACK_H
