#ifndef  _stack_2_
#define  _stack_2_

#include<cstddef>
#include<iostream>
#include<stdexcept>
#include<algorithm>

#include"checking_policy.h"
#include"allocator2_2.h"

/*
template<typename T, size_t N>
class Static_table_allocator
{
protected:
    typedef T rep_type[N];
    rep_type _rep;
    size_t _capacity;

public:
    void init(size_t n)
    {
        _capacity = n;
    }

    size_t size() const
    {
        return _capacity;
    }

    T& operator[](size_t i)
    {
        return _rep[i];
    }
    const T& operator[](size_t i) const
    {
        return _rep[i];
    }
};
*/

template<typename T = int, size_t N = 100, typename Checking_policy = No_checking_policy,
         template<typename U,size_t M>  class Allocator_policy = Static_table_allocator >
class Stack: private Checking_policy, private Allocator_policy<T,N>
{
    size_t _top;
public:
    Stack(size_t n = N):_top(0)
    {
        this->init(n);
    };

    void push(const T &val)
    {
        this->expand_if_needed(_top);
        Checking_policy::check_push(_top,this->size());
        (*this)[_top++]=val;
    }

    void pop()
    {
        Checking_policy::check_pop(_top);
        --_top;
        this->shrink_if_needed(_top);
    }

    const T& top()  const
    {
        Checking_policy::check_top(_top);
        return (*this)[_top-1];
    }

    T& top()
    {
        Checking_policy::check_top(_top);
        return (*this)[_top-1];
    }

    bool is_empty() const
    {
        return !_top;
    }

    ~Stack()
    {
        this->dealocate();
    }
};

#endif