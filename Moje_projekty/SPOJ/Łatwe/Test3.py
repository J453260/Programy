i = 0
poprzednia = None
liczby = []
while True:
    t = int(input())
    liczby.append(t)
    if t == 42 and poprzednia is not None and poprzednia != 42:
        i += 1

    if i == 3:
        break
        
    poprzednia = t

for x in liczby:
    print(x)
