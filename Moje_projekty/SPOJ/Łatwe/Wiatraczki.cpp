#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<char>> build(int n, bool left)
{
    if(n == 1)
        return {{'*','*'},{'*','*'}};

    vector<vector<char>> small = build(n - 1, left);
    int size = 2 * n;
    int smallSize = 2 * (n - 1);
    vector<vector<char>> big(size, vector<char>(size, '?'));

    for (int i = 0; i < smallSize; i++)
        for (int j = 0; j < smallSize; j++)
            big[i + 1][j + 1] = small[i][j];

    big[0][0] = big[0][size-1] = big[size-1][0] = big[size-1][size-1] = '*';

    // Funkcja zwracająca znak dla danej pozycji w sekwencji
    // Narożniki zajmują miejsce w sekwencji (cnt się zwiększa),
    // ale ich wartość jest już ustawiona i nie nadpisujemy
    int cnt = 0;
    auto nextChar = [&]() -> char
    {
        char c = (cnt % (2*n) < n) ? '*' : '.';
        cnt++;
        return c;
    };

    // Kolejność obchodzenia zależy od skrętności.
    // Wzdłuż każdej krawędzi iterujemy przez WSZYSTKIE elementy (łącznie z narożnikami),
    // ale nadpisujemy tylko te z '?'
    if(left) // CCW: góra(L→R), lewa(T→B)... nie, sprawdzam jeszcze raz kierunek CCW
    {
        // CCW od [0][0]: lewa(dół T→B), dół(prawo L→R), prawa(góra B→T), góra(lewo R→L)
        // lewa krawędź, z góry na dół
        for (int i = 0; i < size; i++)
        {
            char c = nextChar();
            if (big[i][0] == '?') big[i][0] = c;
        }
        // dolna krawędź, z lewa na prawo
        for (int j = 0; j < size; j++)
        {
            char c = nextChar();
            if (big[size-1][j] == '?') big[size-1][j] = c;
        }
        // prawa krawędź, z dołu na górę
        for (int i = size-1; i >= 0; i--)
        {
            char c = nextChar();
            if (big[i][size-1] == '?') big[i][size-1] = c;
        }
        // górna krawędź, z prawa na lewo
        for (int j = size-1; j >= 0; j--)
        {
            char c = nextChar();
            if (big[0][j] == '?') big[0][j] = c;
        }
    }
    else // CW od [0][0]: góra(L→R), prawa(T→B), dół(R→L), lewa(B→T)
    {
        // górna krawędź, z lewa na prawo
        for (int j = 0; j < size; j++)
        {
            char c = nextChar();
            if (big[0][j] == '?') big[0][j] = c;
        }
        // prawa krawędź, z góry na dół
        for (int i = 0; i < size; i++)
        {
            char c = nextChar();
            if (big[i][size-1] == '?') big[i][size-1] = c;
        }
        // dolna krawędź, z prawa na lewo
        for (int j = size-1; j >= 0; j--)
        {
            char c = nextChar();
            if (big[size-1][j] == '?') big[size-1][j] = c;
        }
        // lewa krawędź, z dołu na górę
        for (int i = size-1; i >= 0; i--)
        {
            char c = nextChar();
            if (big[i][0] == '?') big[i][0] = c;
        }
    }

    return big;
}

int main()
{
    int n;
    while(cin >> n && n != 0)
    {
        bool left = (n > 0);
        vector<vector<char>> wynik = build(abs(n), left);
        for (auto &row : wynik)
        {
            for (char c : row) cout << c;
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}
