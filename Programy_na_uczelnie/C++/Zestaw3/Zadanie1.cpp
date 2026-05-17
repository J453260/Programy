#include <iostream>
#include <cstring>
#include <cstddef>
//using namespace std;

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T>
T* max(T* a, T* b) {
    return (*a > *b) ? a : b;
}

template <typename T>
T* max(T* data, size_t n) {
    if (n == 0) return nullptr;
    T* result = data;
    for (size_t i = 1; i < n; ++i) {
        if (data[i] > *result)
            result = &data[i];
    }
    return result;
}

template <>
char* max<char>(char* a, char* b) {
    return (strcmp(a, b) >= 0) ? a : b;
}

template <>
const char* max<const char>(const char* a, const char* b) {
    return (strcmp(a, b) >= 0) ? a : b;
}


int main() {
    std::cout << "=== max(T a, T b) ===\n";
    std::cout << "max(3, 7)       = " << max(3, 7)         << "\n";
    std::cout << "max(5.2, 3.8)   = " << max(5.2, 3.8)     << "\n";
    std::cout << "max('a', 'z')   = " << max('a', 'z')     << "\n\n";

    std::cout << "=== max(T* a, T* b) ===\n";
    int x = 10, y = 20;
    int* pMax = max(&x, &y);
    std::cout << "max(&10, &20)   = " << *pMax << "\n";
 
    double d1 = 3.14, d2 = 2.71;
    double* dMax = max(&d1, &d2);
    std::cout << "max(&3.14,&2.71)= " << *dMax << "\n\n";

    std::cout << "=== max(T* data, size_t n) ===\n";
    int arr[] = {4, 9, 2, 7, 1, 6};
    int* arrMax = max(arr, 6);
    std::cout << "max({4,9,2,7,1,6}) = " << *arrMax << "\n";
 
    double darr[] = {1.1, 5.5, 3.3, 2.2};
    double* darrMax = max(darr, 4);
    std::cout << "max({1.1,5.5,3.3,2.2}) = " << *darrMax << "\n\n";

    std::cout << "=== max(char* a, char* b) ===\n";
    char s1[] = "banana";
    char s2[] = "apple";
    char* sMax = max(s1, s2);
    std::cout << "max(\"banana\",\"apple\") = " << sMax << "\n\n";
    
    std::cout << "=== max(const char* a, const char* b) ===\n";
    const char* cs1 = "zebra";
    const char* cs2 = "mango";
    const char* csMax = max(cs1, cs2);
    std::cout << "max(\"zebra\",\"mango\") = " << csMax << "\n";
 
    return 0;
}
