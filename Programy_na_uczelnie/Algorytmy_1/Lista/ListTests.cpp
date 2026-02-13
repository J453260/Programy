#include "gtest/gtest.h"
#include "List.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include <stdexcept>

using namespace std;

// --- GTest Typed Test Setup ---// Definiujemy listę typów, które chcemy testować.
// Nasz zestaw testów zostanie automatycznie uruchomiony dla każdego typu z tej listy.
// Testujemy używając <int> jako typu danych.
using ListImplementations = ::testing::Types<ArrayList<int>, LinkedList<int>>;

// Tworzymy "fixture" testową, która jest szablonem opartym na typie.
template <typename T>
//class ListTest : public ::testing::Test

//template <typename T>
class ArrayList : public List<T>
{
private:
    T* data;
    int sz;
    int cap;

    void resize(int newCap)
    {
        T* newData = new T[newCap];
        for (int i = 0; i < sz; ++i)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        cap = newCap;
    }

public:
    ArrayList() : sz(0), cap(4)
    {
        data = new T[cap];
    }

    ~ArrayList() override
    {
        delete[] data;
    }

    void append(const T &value) override
    {
        if (sz == cap)
            resize(cap * 2);
        data[sz++] = value;
    }

    void insert(int index, const T &value) override
    {
        if (index < 0 || index > sz)
            throw std::out_of_range("Index out of range");
        if (sz == cap)
            resize(cap * 2);
        for (int i = sz; i > index; --i)
            data[i] = data[i - 1];
        data[index] = value;
        ++sz;
    }

    void remove(int index) override
    {
        if (index < 0 || index >= sz)
            throw std::out_of_range("Index out of range");
        for (int i = index; i < sz - 1; ++i)
            data[i] = data[i + 1];
        --sz;
    }

    T get(int index) override
    {
        if (index < 0 || index >= sz)
            throw std::out_of_range("Index out of range");
        return data[index];
    }

    void set(int index, const T &value) override
    {
        if (index < 0 || index >= sz)
            throw std::out_of_range("Index out of range");
        data[index] = value;
    }

    int size() const override
    {
        return sz;
    }

    bool isEmpty() const override
    {
        return sz == 0;
    }

    void clear() override
    {
        sz = 0;
    }
};







// Rejestrujemy to jako zestaw testów TYPU (TYPED test suite)
TYPED_TEST_SUITE(ListTest, ListImplementations);

// --- Testy ---
// Używamy TYPED_TEST zamiast TEST_F. Ten test zostanie uruchomiony dla każdego typu
// na liście ListImplementations. 'this->list' będzie wskazywać na poprawny
// obiekt (ArrayList lub LinkedList) dla danego przebiegu testu.

TYPED_TEST(ListTest, InitialState)
{
    EXPECT_EQ(this->list->size(), 0);
    EXPECT_TRUE(this->list->isEmpty());
}

TYPED_TEST(ListTest, Append)
{
    this->list->append(10);
    EXPECT_EQ(this->list->size(), 1);
    EXPECT_FALSE(this->list->isEmpty());
    EXPECT_EQ(this->list->get(0), 10);

    this->list->append(20);
    EXPECT_EQ(this->list->size(), 2);
    EXPECT_EQ(this->list->get(0), 10);
    EXPECT_EQ(this->list->get(1), 20);
}

TYPED_TEST(ListTest, InsertMiddle)
{
    this->list->append(10);
    this->list->append(30);
    this->list->insert(1, 20); // Wstaw 20 pomiędzy 10 a 30

    EXPECT_EQ(this->list->size(), 3);
    EXPECT_EQ(this->list->get(0), 10);
    EXPECT_EQ(this->list->get(1), 20);
    EXPECT_EQ(this->list->get(2), 30);
}

TYPED_TEST(ListTest, InsertAtFront)
{
    this->list->append(10);
    this->list->insert(0, 5); // Wstawienie na indeksie 0
    EXPECT_EQ(this->list->size(), 2);
    EXPECT_EQ(this->list->get(0), 5);
    EXPECT_EQ(this->list->get(1), 10);
}

TYPED_TEST(ListTest, InsertAtBack)
{
    this->list->append(10);
    this->list->insert(1, 20); // Równoważne z append(), gdy index == size()
    EXPECT_EQ(this->list->size(), 2);
    EXPECT_EQ(this->list->get(0), 10);
    EXPECT_EQ(this->list->get(1), 20);
}

TYPED_TEST(ListTest, RemoveMiddle)
{
    this->list->append(10);
    this->list->append(20);
    this->list->append(30);

    this->list->remove(1); // Usuń 20
    EXPECT_EQ(this->list->size(), 2);
    EXPECT_EQ(this->list->get(0), 10);
    EXPECT_EQ(this->list->get(1), 30);
}

TYPED_TEST(ListTest, GetAndSet)
{
    this->list->append(10);
    this->list->append(20);

    // Sprawdź początkową wartość za pomocą get()
    EXPECT_EQ(this->list->get(1), 20);

    // Użyj nowej metody set() do modyfikacji wartości
    this->list->set(1, 25);

    // Sprawdź, czy get() zwraca nową wartość
    EXPECT_EQ(this->list->get(1), 25);
    EXPECT_EQ(this->list->get(0), 10); // Upewnij się, że inne wartości się nie zmieniły
}

TYPED_TEST(ListTest, Clear)
{
    this->list->append(10);
    this->list->append(20);
    this->list->append(30);
    EXPECT_EQ(this->list->size(), 3);

    this->list->clear();
    EXPECT_EQ(this->list->size(), 0);
    EXPECT_TRUE(this->list->isEmpty());

    // Sprawdź, czy lista nadal jest używalna
    this->list->append(100);
    EXPECT_EQ(this->list->size(), 1);
    EXPECT_EQ(this->list->get(0), 100);
}
TYPED_TEST(ListTest, RemoveFront)
{
    this->list->append(10);
    this->list->append(20);
    this->list->append(30);

    this->list->remove(0); // Usuń 10
    EXPECT_EQ(this->list->size(), 2);
    EXPECT_EQ(this->list->get(0), 20);
    EXPECT_EQ(this->list->get(1), 30);
}

TYPED_TEST(ListTest, RemoveBack)
{
    this->list->append(10);
    this->list->append(20);
    this->list->append(30);

    this->list->remove(2); // Usuń 30 (index size() - 1)
    EXPECT_EQ(this->list->size(), 2);
    EXPECT_EQ(this->list->get(0), 10);
    EXPECT_EQ(this->list->get(1), 20);
}

TYPED_TEST(ListTest, RemoveOnlyElement)
{
    this->list->append(50);
    EXPECT_EQ(this->list->size(), 1);

    this->list->remove(0);
    EXPECT_EQ(this->list->size(), 0);
    EXPECT_TRUE(this->list->isEmpty());

    // Sprawdź, czy można bezpiecznie dodać ponownie
    this->list->append(100);
    EXPECT_EQ(this->list->size(), 1);
    EXPECT_EQ(this->list->get(0), 100);
}

TYPED_TEST(ListTest, AppendLoopStressTest)
{
    const int count = 100;
    for (int i = 0; i < count; ++i)
    {
        this->list->append(i * 5);
    }

    EXPECT_EQ(this->list->size(), count);
    for (int i = 0; i < count; ++i)
    {
        EXPECT_EQ(this->list->get(i), i * 5);
    }
}

TYPED_TEST(ListTest, ClearEmptyList)
{
    EXPECT_EQ(this->list->size(), 0);
    EXPECT_NO_THROW(this->list->clear());
    EXPECT_EQ(this->list->size(), 0);
    EXPECT_TRUE(this->list->isEmpty());
}

TYPED_TEST(ListTest, ExceptionHandling)
{
    // Testuj dostępy na pustej liście
    EXPECT_THROW(this->list->get(0), std::out_of_range);
    EXPECT_THROW(this->list->set(0, 99), std::out_of_range);
    EXPECT_THROW(this->list->remove(0), std::out_of_range);

    // Testuj prawidłowe wstawianie
    EXPECT_NO_THROW(this->list->insert(0, 10)); // wstawienie na indeks 0 na pustej liście jest prawidłowe
    EXPECT_EQ(this->list->size(), 1);

    // Testuj nieprawidłowe granice na liście niepustej
    EXPECT_THROW(this->list->get(-1), std::out_of_range);
    EXPECT_THROW(this->list->get(1), std::out_of_range);  // rozmiar to 1, więc maks. indeks to 0
    EXPECT_THROW(this->list->set(-1, 99), std::out_of_range);
    EXPECT_THROW(this->list->set(1, 99), std::out_of_range); // j.w.
    EXPECT_THROW(this->list->remove(1), std::out_of_range);
    EXPECT_THROW(this->list->insert(-1, 0), std::out_of_range);
    EXPECT_THROW(this->list->insert(2, 0), std::out_of_range); // Można wstawiać tylko na indeks 0 lub 1 (size)

    // Testuj prawidłowe wstawianie na końcu
    EXPECT_NO_THROW(this->list->insert(1, 20)); // wstawienie na indeksie 'size' jest prawidłowe
    EXPECT_EQ(this->list->size(), 2);
}
