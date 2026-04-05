#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

void printfloat(float a)
{
    unsigned int bits;
    memcpy(&bits, &a, sizeof(float));
    for (int i = 3; i >= 0; --i)
    {
        unsigned char byte = (bits >> (i*8)) & 0xFF;
        cout << hex << (int)byte;
        if (i > 0)
            cout << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        float x;
        cin >> x;
        printfloat(x);
    }
    return 0;
}
