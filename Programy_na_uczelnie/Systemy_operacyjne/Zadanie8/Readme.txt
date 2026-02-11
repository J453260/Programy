Autor: Jan Bajor
Data: 18.05.2025
Miejsce: Kraków

Folder zawiera 5 kodów realizujących problem serwer-klient.
Kody mqhelper.h i .c zawierają odpowiednio deklaracje i implementacje funkcji używanych do obsługi kolejek.

Serwer odbiera zapytanie od klientów w postaci operacji arytmetycznej i zwraca je klientowi, wypisując przy okazji kolejkę tego klienta.
Klient również wewnątrz odblicza zadaną operację w celu sprawdzenia poprawności.

Aby uruchomić program należy użyć komendy make run-cw8.
Liczba klientów i losowy czas spania są podawane jako argumenty wejścia programu i są zmiennymi w makefile.