#include <iostream>
using namespace std;

int main()
{
    int testy;
    cin >> testy;

    long long doba = 86400;

    for (int i = 0; i < testy; i++)
    {
        long long N, M;
        cin >> N >> M;

        long long lacznie = 0;

        for (int j = 0; j < N; j++)
        {
            long long czas;
            cin >> czas;

            lacznie += doba / czas; // suma ciastek wszystkich obżartuchów
        }

        // jedno ceiling division na końcu
        cout << (lacznie + M - 1) / M << "\n";
    }

    return 0;
}
