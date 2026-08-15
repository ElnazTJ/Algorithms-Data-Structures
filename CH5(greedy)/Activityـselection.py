n = int(input())

v = []

for i in range(n):
    l, r = map(int, input().split())
    v.append((l, r))

v.sort(key=lambda  x : x[1])

ans=0
last=-1

for l , r in v:
    if l>= last:
        last= r
        ans+=1

print(ans)