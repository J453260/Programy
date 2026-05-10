#include <iostream>

class First
{
public:
    double operator()(double x)
    {
        return x;
    }
    double operator()(double x,double)
    {
        return x;
    }
};

class Second
{
public:
    double operator()(double,double y)
    {
        return y;
    }
    double operator()(double y)
    {
        return y;
    }
};

class Constant
{
    double _c;
public:
    Constant(double c) :_c(c) {};
    double operator()(double)
    {
        return _c;
    }
    double operator()(double,double)
    {
        return _c;
    }
};

template<typename F> double integrate(F f,double  min,double max,double ds)
{
    double integral=.0;
    for(double x=min; x<max; x+=ds)
    {
        integral+=f(x);
    }
    return integral*ds;
};

int main()
{
    First x;
    Second y;
    std::cout<<integrate(x, 0, 1, 0.001)<<std::endl;
    std::cout<<integrate(y, 0, 1, 0.001)<<std::endl;
    return 0;
}
