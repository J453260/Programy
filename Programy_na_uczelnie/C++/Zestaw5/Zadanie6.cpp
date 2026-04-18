#include<iostream>
#include<string>
#include"typelist.h"
#include"any_print.h"

int main()
{

    typedef TypeList<int,Null_type> T1;
    typedef TypeList<double,T1> T2;
    typedef TypeList<float,T2> T3;
    typedef TypeList<std::string,T3> T4;

    std::cout<<Length<T1>::val<<" ";
    std::cout<<Length<T2>::val<<" ";
    std::cout<<Length<T3>::val<<"\n";


    typedef At<1,T1>::Result at1;
    typedef At<1,T3>::Result at2;
    typedef At<3,T3>::Result at3;

    boost::any a(3.14);

    print_any<T3>(std::cout,a);
    std::cout<<"\n";

    a=std::string("abc");
    print_any<T3>(std::cout,a);
    std::cout<<"\n";

    print_any<T4>(std::cout,a);
    std::cout<<"\n";

    return 0;
}
