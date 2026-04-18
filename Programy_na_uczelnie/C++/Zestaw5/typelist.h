#ifndef _typelist_
#define _typelist_

template<typename H, typename T> struct TypeList
{
    typedef H Head;
    typedef T Tail;
};

class  Null_type {};
struct Empty_type {};

// --- Length ---
template<typename TL> struct Length
{
    enum { val = 1 + Length<typename TL::Tail>::val };
};
template<> struct Length<Null_type>
{
    enum { val = 0 };
};

// --- At (bez ochrony) ---
template<int N, typename T> struct At
{
    typedef typename At<N-1, typename T::Tail>::Result Result;
};
template<typename T> struct At<1, T>
{
    typedef typename T::Head Result;
};

// --- At2 (z ochroną) ---
template<int N, typename T> struct At2
{
    typedef typename At2<N-1, typename T::Tail>::Result Result;
};
template<typename H, typename T> struct At2<1, TypeList<H,T>>
{
    typedef H Result;
};
template<int N> struct At2<N, Null_type>
{
    typedef Empty_type Result;
};

// --- In ---
template<typename T, typename TL> struct In
{
    enum { yes = In<T, typename TL::Tail>::yes };
};
template<typename T, typename Tail> struct In<T, TypeList<T,Tail>>
{
    enum { yes = 1 };
};
template<typename T> struct In<T, Null_type>
{
    enum { yes = 0 };
};

#endif
