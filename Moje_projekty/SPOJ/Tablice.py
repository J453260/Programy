t = int(input())
for _ in range(t):
    dane = list(map(int, input().split()))
    n = dane[0]
    zestaw = dane[1:]
    print(*zestaw[::-1])
