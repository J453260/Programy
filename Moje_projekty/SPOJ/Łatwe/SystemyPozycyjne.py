t = int(input())
for _ in range(t):
    v1 = int(input())
    temp1 = v1
    temp2 = v1
    tablica_szes = []
    tablica_jeden = []
    while temp1 > 0:
        reszta = temp1 % 16
        if reszta == 10:
            tablica_szes += str("A")
        elif reszta == 11:
            tablica_szes += str("B")
        elif reszta == 12:
            tablica_szes += str("C")
        elif reszta == 13:
            tablica_szes += str("D")
        elif reszta == 14:
            tablica_szes += str("E")
        elif reszta == 15:
            tablica_szes += str("F")
        else: tablica_szes += str(reszta)
        temp1 = temp1 // 16

    while temp2 > 0:
        reszta = temp2 % 11
        if reszta == 10:
            tablica_jeden += str("A")
        else: tablica_jeden += str(reszta)
        temp2 = temp2 // 11

    wynik1 = "".join(tablica_szes[::-1])
    wynik2 = "".join(tablica_jeden[::-1])
    print(wynik1, wynik2)
