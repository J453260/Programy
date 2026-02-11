Autor: Jan Bajor
Data: 24.04.2025
Miejsce: Kraków

Program realizuje problem wzajemnego wykluczania procesów używając semaforów.
Program tworzy w pętli n procesów a następnie wysyła je do sekcji krytycznej. N jest podawane jako argument wejścia programu.
W sekcji krytycznej jest otwierany plik z którego jest pobierana liczba a następnie inkrementowana.
Ostatecznie liczba powinna być zinkrementowana o n.
Jeżeli jeden proces wejdzie do sekcji krytycznej to semafor blokuje tę możliwość innemu, aż do czasu odblokowania przez proces, który wszedł.

Program wymaga argumentów wejścia, które należy wpisywać w następującej strukturze:
./Cw6, Nazwa pliku, Dolna granica przedziału, Górna granica przedziału, Nazwa semafora, ./Sekcja_krytyczna, n procesów.