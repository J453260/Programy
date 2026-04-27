#ifndef _checking_policy_
#define _checking_policy_


struct No_checking_policy
{
    static void check_push(size_t,size_t) {};
    static void check_pop(size_t) {};
    static void check_top(size_t) {};
};

struct Abort_on_error_policy
{
    static void check_push(size_t top,size_t size)
    {

        if(top >= size)
        {
            std::cerr<<"trying to push elemnt on full stack: aborting"<<std::endl;
            abort();
        }
    };

    static void check_pop(size_t top)
    {
        if(top == 0)
        {
            std::cerr<<"trying to pop an empty stack: aborting"<<std::endl;
            abort();
        }
    };
    static void check_top(size_t top)
    {
        if(top == 0)
        {
            std::cerr<<"trying to read from empty stack: aborting"<<std::endl;
            abort();
        }
    };
};

struct Std_exception_on_error_policy
{

    static void check_push(size_t top,size_t size)
    {

        if(top >= size)
        {
            throw std::range_error("over the top");
        }
    };
    static void check_pop(size_t top)
    {
        if(top == 0)
        {
            throw std::range_error("poping empty");
        }
    };
    static void check_top(size_t top)
    {
        if(top == 0)
        {
            throw std::range_error("reading empty");
        }
    };

};
#endif
