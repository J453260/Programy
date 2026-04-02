#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define T_SIZE 1001

char* string_merge(char* a, char* b)
{
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);

    size_t min_len = (len_a < len_b) ? len_a : len_b;

    char* result = new char[2 * min_len + 1];

    for(size_t i = 0; i < min_len; i++)
    {
        result[2 * i] = a[i];
        result[2 * i + 1] = b[i];
    }

    result[2 * min_len] = '\0';

    return result;
}

int main()
{
    int t;
    char S1[T_SIZE], S2[T_SIZE], *S;

    cin >> t;

    while(t)
    {
        cin >> S1 >> S2;

        S = string_merge(S1, S2);
        cout << S << endl;

        delete[] S;

        t--;
    }

    return 0;
}
