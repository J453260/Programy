# Autor: Jan Bajor
# Data: 04.04.2025r.
# Miejsce: Kraków

Folder zawiera 1 program - Cw4.c realizujący problem "Producent-Konsument".
Z pliku "Dane1.txt" producent pobiera dane, które później przekazuje do bufora.
Konsument pobiera dane z bufora i wpisuje je do pliku "Dane2.txt".
Nazwy plików z których są pobierane i wpisywane dane i przedział z którego są losowane liczby do funkcji sleep są podawane z linii komend.

Proces macierzysty, który jest producentem zczytuje w pętli z pliku dane i zapisuje je do bufora.
Później proces potomny, który jest konsumentem zczytuje dane z buforu, wypisuje je na ekran i przepisuje do pliku. Konsument również działa w pętli.
Funkcja rand() losuje liczby z podanego przedziału co odpowiada liczbom sekund na które program ma zostać uśpiony funkcją sleep(), co odpowiada symulacji różnych szybkości działania programu.
