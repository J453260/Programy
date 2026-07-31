# Autor: Jan Bajor
# Data: 02.05.2025
# Miejsce: Kraków

Program zawiera 7 kodów realizujący problem producenta i konsumenta za pomocą semaforów i pamięci dzielonej.
Producent otwiera plik wejściowy i czyta z niego dane.
Dla każdego przeczytanego znaku, producent czeka, aż będzie możliwe wstawienie danych do bufora, wstawia dane do bufora w pozycji wskazanej przez zmienną, uaktualnia wskaźnik pozycji wstawiania, sygnalizuje konsumentowi, że nowy element jest dostępny do odczytu.

Dla każdego elementu w buforze konsument czeka, aż producent wstawi dane do bufora, odczytuje dane z bufora w pozycji wskazanej przez zmienną, uaktualnia wskaźnik pozycji wyjmowania, sygnalizuje producentowi, że miejsce w buforze zostało zwolnione i może tam wstawić kolejny element.
