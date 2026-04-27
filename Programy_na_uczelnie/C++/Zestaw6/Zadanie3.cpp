#include<iostream>
#include"stack2.h"

const int n=10;

int main()
{
    int n=10;
    Stack<int,0,Std_exception_on_error_policy,Expandable_new_allocator > s1(n);
    Stack<int,10,Abort_on_error_policy,Static_table_allocator > s2(n);

    return 0;
}
