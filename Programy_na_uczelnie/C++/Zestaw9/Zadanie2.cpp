#include <iostream>
#include <memory>

int main()
{
    int* p1 = nullptr;
    std::cout << "Zwykly wskaznik: " << sizeof(p1) << std::endl; // 8


    std::unique_ptr<int> uptr;
    std::shared_ptr<int> sptr;

    std::cout << "Unique_ptr: " << sizeof(uptr) << std::endl; // 8
    std::cout << "Shared_ptr: " << sizeof(sptr) << std::endl; // 16

    return 0;
}
