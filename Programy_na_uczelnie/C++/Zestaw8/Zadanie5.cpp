#include <iostream>

template<typename T>
class Variable
{
public:
    T operator()(T x) const
    {
        return x;
    }
};

template<typename T>
class Constant
{
    T _c;
public:
    Constant(T c) :_c(c) {};
    T operator()(T) const
    {
        return _c;
    }
};


template<typename T, typename LHS, typename RHS>
class AddExpr
{
    LHS _lhs;
    RHS _rhs;
public:
    AddExpr(const LHS &l,const RHS &r) :_lhs(l),_rhs(r) {};
    T operator()(T x) const
    {
        return _lhs(x)+_rhs(x);
    }
};


template<typename T, typename E>
class Expr
{
    E _e;
public:
    Expr(const E &e) : _e(e) {}
    T operator()(T x) const
    {
        return _e(x);
    }
    const E& get() const
    {
        return _e;
    }
};


template<typename T, typename LHS,typename RHS >
Expr<T, AddExpr<T,LHS,RHS>> operator+(const Expr<T,LHS> &l, const Expr<T,RHS> &r)
{
    return Expr<T, AddExpr<T,LHS,RHS>>(AddExpr<T,LHS,RHS>(l.get(), r.get()));
};


template<typename T>
Expr<T, Variable<T>> var()
{
    return Expr<T, Variable<T>>(Variable<T>());
}

template<typename T>
Expr<T, Constant<T>> constant(T c)
{
    return Expr<T, Constant<T>>(Constant<T>(c));
}


template<typename T, typename E>
T integrate(const Expr<T,E> &f, T a, T b, int n = 1000)
{
    T h = (b - a) / T(n);
    T sum = T(0);
    for (int i = 0; i < n; ++i)
        sum = sum + f(a + h * T(i)) * h;
    return sum;
}


int main()
{
    auto x = var<double>();
    auto expr = x + constant(2.0);      // f(x) = x + 2

    double wynik = integrate(expr, 0.0, 1.0);
    std::cout << "double: " << wynik << std::endl;   // 2.4995
    return 0;
}
