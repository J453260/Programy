import sys

m, n = map(int, input().split())
macierz = []
for _ in range(m):
    wiersz = list(map(int, sys.stdin.readline().split()))
    macierz.append(wiersz)

# m = wiersz
# n = kolumna
macierz2 = [[0 for _ in range(m)] for _ in range(n)]
for i in range(m):
    for j in range(n):
        macierz2[j][i] = macierz[i][j]

for i in range(n):
    for j in range(m):
        print(macierz2[i][j], end=" ")
    print()
