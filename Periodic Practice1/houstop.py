n = int(input())
c = [0] + list(map(int, input().split()))

suff = [0] * (n + 1)
suff[n] = n

for i in range(n - 1, 0, -1):
    if c[i] <= c[suff[i + 1]]:
        suff[i] = i
    else:
        suff[i] = suff[i + 1]

ans = 0
current = 0

while current < n:
    next = suff[current + 1]

    ans += (next - current) * c[next]

    current = next

print(ans)