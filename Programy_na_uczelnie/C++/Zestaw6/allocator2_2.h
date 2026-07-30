#ifndef _allocator2_2_
#define _allocator2_2_

#include <cstddef>
#include <algorithm>

template<typename T, size_t N>
struct Static_table_allocator
{
protected:
    typedef T rep_type[N];
    rep_type _rep;
    size_t   _capacity;

public:
    void init(size_t n)
    {
        _capacity = n;
    }
    void expand_if_needed(size_t)    {}
    void shrink_if_needed(size_t)    {}
    void dealocate()                 {}

    size_t size() const
    {
        return _capacity;
    }

    T&       operator[](size_t i)
    {
        return _rep[i];
    }
    const T& operator[](size_t i) const
    {
        return _rep[i];
    }
};

template<typename T,size_t N > struct Dynamic_table_allocator
{
protected:
    typedef T * rep_type;
    rep_type _rep;
    size_t _size;

public:
    void init(rep_type &rep,size_t n)
    {
        _size=n;
        rep = new T[_size];
    };
    void init(size_t n)
    {
        _size = n;
        _rep  = new T[_size];
    }
    void expand_if_needed(size_t) {}
    void shrink_if_needed(size_t) {}
    void dealocate()
    {
        delete [] _rep;
    }

    size_t size() const
    {
        return _size;
    }

    T&       operator[](size_t i)
    {
        return _rep[i];
    }
    const T& operator[](size_t i) const
    {
        return _rep[i];
    }
};

template<typename T, size_t N>
struct Expandable_new_allocator
{
protected:
    typedef T* rep_type;
    rep_type _rep;
    size_t   _size;

public:
    void init(size_t n)
    {
        _size = n;
        _rep  = new T[_size];
    }
    void expand_if_needed(size_t top)
    {
        if (top == _size)
        {
            _size = 2 * _size;
            T* tmp = new T[_size];
            std::copy(_rep, _rep + top, tmp);
            delete [] _rep;
            _rep = tmp;
        }
    }
    void shrink_if_needed(size_t) {}
    void dealocate()
    {
        delete [] _rep;
    }

    size_t size() const
    {
        return _size;
    }

    T&       operator[](size_t i)
    {
        return _rep[i];
    }
    const T& operator[](size_t i) const
    {
        return _rep[i];
    }
};

#endif
