t = int(input())
for _ in range(t):
    v1, v2 = map(int, input().split())
    vsr = (2*v1*v2)//(v1+v2)
    print(vsr)
    t = t-1
