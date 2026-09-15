t = int(input())
for _ in range(t):
    v1, v2, v3 = map(int, input().split())
    i = 0
    tablica = []
    while i < v1:
        if i%v2==0 and i%v3!=0:
            tablica.append(i)
        i += 1

    print(*tablica)
