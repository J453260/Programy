#include<iostream>
#include<vector>
#include<iterator>


#include"typelist.h"
#include"boostany.hpp"

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(os, " "));
    return os;
};

template<class TYPES>
void  print_any(std::ostream &of,boost::any val)
{
    typedef typename TYPES::Head Head;
    typedef typename TYPES::Tail Tail;
    if(val.type()==typeid(Head))
    {
        of<<boost::any_cast<Head>(val);
    }
    else if(val.type()==typeid(std::vector<Head>))
    {
        of<<boost::any_cast<std::vector<Head> >(val);
    }
    else
    {
        print_any<Tail>(of,val);
    }
};

template<>
void  print_any<Null_type>(std::ostream &of,boost::any val)
{
    of<<"don't know how to print this"<<std::endl;
};
