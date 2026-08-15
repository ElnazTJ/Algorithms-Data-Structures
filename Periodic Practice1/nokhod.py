m, n = map(int, input().split())
a = list(map(int, input().split()))

a.sort()

x = sum(a) - m
ans = 0

for i in range(n):
    remaining = n - i

    if a[i] * remaining <= x:
        deficit = a[i]

        ans += deficit * deficit
        x -= deficit

    else:
        q = x // remaining
        r = x % remaining

        ans += (remaining - r) * q * q
        ans += r * (q + 1) * (q + 1)

        break

print(ans)