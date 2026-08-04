import sys

rejestry = [0] * 10  # 10 rejestrow, wszystkie zaczynaja od zera

for linia in sys.stdin:
    dane = linia.split()
    if not dane:
        continue

    operacja = dane[0]
    a = int(dane[1])
    b = int(dane[2])

    if operacja == '+':
        print(rejestry[a] + rejestry[b])
    elif operacja == '-':
        print(rejestry[a] - rejestry[b])
    elif operacja == '*':
        print(rejestry[a] * rejestry[b])
    elif operacja == '/':
        print(int(rejestry[a] / rejestry[b]))
    elif operacja == '%':
        wynik = rejestry[a] - int(rejestry[a] / rejestry[b]) * rejestry[b]
        print(wynik)
    elif operacja == 'z':
        rejestry[a] = b
