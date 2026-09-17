import sys

m = int(input())
for _ in range(m):
    wiersz = list(map(int, sys.stdin.readline().split()))
    parzyste = []
    nieparzyste = []
    for i in range(len(wiersz)):
        if i == 0:
            continue

        if i%2 == 0:
            parzyste += [wiersz[i]]
        else:
            nieparzyste += [wiersz[i]]

    razem = parzyste + nieparzyste

    print(*razem)
