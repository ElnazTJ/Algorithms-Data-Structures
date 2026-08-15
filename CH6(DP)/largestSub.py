n = int(input())
a = list(map(int, input().split()))

current = a[0]
ans = a[0]

for i in range(1, n):
    current = max(a[i], a[i] + current)
    ans = max(ans, current)

print(ans)