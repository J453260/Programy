#include <iostream>
#include <vector>
#include <sstream>
#include <limits>
using namespace std;

struct Wspolrzedne
{
    long long x;
    long long y;
};

vector<Wspolrzedne> wczytajLamana(const string& linia)
{
    istringstream iss(linia);
    vector<Wspolrzedne> punkty;
    long long x, y;
    while (iss >> x >> y)
    {
        punkty.push_back({x, y});
    }

    // usuń powtórzony ostatni punkt
    if (!punkty.empty() && punkty.front().x == punkty.back().x &&
            punkty.front().y == punkty.back().y)
    {
        punkty.pop_back();
    }
    return punkty;
}

long long polePowierzchni(const vector<Wspolrzedne>& p)
{
    __int128 pole = 0;  // 🔥 zabezpieczenie przed overflow
    int n = p.size();
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        pole += (__int128)p[i].x * p[j].y - (__int128)p[j].x * p[i].y;
    }
    return (long long)pole; // bez abs!
}

string wczytajNiepustaLinie()
{
    string linia;
    while (getline(cin, linia))
    {
        if (!linia.empty()) return linia;
    }
    return "";
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 🔥 poprawne czyszczenie bufora

    for (int i = 0; i < n; i++)
    {
        string liniax = wczytajNiepustaLinie();
        string liniay = wczytajNiepustaLinie();

        vector<Wspolrzedne> czarna = wczytajLamana(liniax);
        vector<Wspolrzedne> szara  = wczytajLamana(liniay);

        long long polex = polePowierzchni(czarna);
        long long poley = polePowierzchni(szara);

        long long wynik2 = polex * 10 + (poley - polex) * 6;

        cout << wynik2 / 2 << "\n"; // ✔ zawsze całkowite wg treści
    }

    return 0;
}
