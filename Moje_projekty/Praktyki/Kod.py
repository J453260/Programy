import math


def suma(n):
    suma = 0
    for i in range(1, n + 1):
        suma += pow(math.sqrt(i + 1 / i) - math.sqrt(i - 1 / i), 2)

    return suma


n = int(input("Podaj n: "))
wynik = suma(n)
print(wynik)
