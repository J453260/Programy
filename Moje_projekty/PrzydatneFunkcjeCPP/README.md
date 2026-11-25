# Dokumentacja funkcji

## Struck Trojka
`
struct Trojka
{
    int a,b,c;
};
`
Struktura potrzebna do funkcji Trojka.

## bool CzyMaPierwiastek(int a)
Funkcja sprawdzająca czy liczba a ma pierwastek całkowity. Zwraca prawdę gdy ma, fałsz w przeciwnym wypadku.

## void Trojki(int dol, int gora, vector<Trojka>& liczby);
Funkcja licząca trójki pitagorejskie.
`int dol` to dolna granica przedziału, `int gora` górna granica. Weźmy przedział [1, 10], funkcja znajdzie wszystkie trójki a^2 + b^2 = c^2 gdzie liczby a i b
należą do przedziału [1, 10], c już niekoniecznie należy do przedziału.
`vector<Trojka>& liczby` to vector do którego zapisywane są wyniki.

## int NWD(int a, int b)
Funkcja licząca największy wspólny dzielnik liczb a i b.

## int NWW(int a, int b)
Funkcja licząca najmniejszą wspólną wielokrotność liczb a i b.

## void drawSus()
Śmieszna funkcja rysująca postać z Among Us

## long long SymbolNewtona(int n, int k)
Funkcja licząca symbol Newtona, n nad k. Zwracany wynik jest typu long long.
