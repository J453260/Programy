#include<iostream>
#include<vector>
#include<cassert>
using namespace std;


template<bool flag,typename T1,typename T2> struct If_then_else
{
    typedef T1 Result;
};

template<typename T1,typename T2>
struct If_then_else<false,T1,T2>
{
    typedef T2 Result;
};


template<typename T1,typename T2> struct Promote
{
    typedef typename
    If_then_else<(sizeof(T1) > sizeof(T2)),
                 T1,
                 typename If_then_else< (sizeof(T1)< sizeof(T2)),
                 T2,
                 void>::Result >::Result Result;
};

template<typename T> struct Promote<T,T>
{
    typedef T Result;
};




#define MK_PROMOTION(T1,T2,Tr)             \
    template<> class Promote<T1, T2> {     \
      public:                              \
        typedef Tr ResultT;                \
    };                                     \
                                           \
    template<> class Promote<T2, T1> {     \
      public:                              \
        typedef Tr ResultT;                \
    };

MK_PROMOTION(bool, char, int)
MK_PROMOTION(bool, unsigned char, int)
MK_PROMOTION(bool, signed char, int)



template<typename T> vector<T>
operator+(const vector<T>  &a,
          const vector<T>  &b)
{


    assert(a.size()==b.size());

    vector<T> res(a);
    for(size_t i=0; i<a.size(); ++i)
        res[i]+=b[i];

    return res;
}



template<typename T,typename U>
vector<typename Promote<T,U>::Result>
operator+(const vector<T>  &a,
          const vector<U>  &b)
{

    assert(a.size()==b.size());

    vector<typename Promote<T,U>::Result> res(a.size());
    for(size_t i=0; i<a.size(); ++i)
        res[i]=a[i]+b[i];

    return res;
}

template<typename T>
void print(const std::vector<T>& v)
{
    for(size_t i = 0; i < v.size(); ++i)
        cerr << v[i] << " ";
    cerr << endl;
}

int main()
{
    vector<double> x(10, 1.5);
    vector<double> y(10, 2.5);
    vector<int>    l(10, 3);

    auto xy = x+y;
    auto lx = l+x;

    cout << "x + y: "; print(xy);
    cout << "l + x: "; print(lx);

    return 0;
}
