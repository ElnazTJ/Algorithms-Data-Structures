n = int(input())
a = list(map(int, input().split()))

dp = [1] * n
parent = [-1] * n

best = 0

for i in range(1, n):
    ai = a[i]
    dpi = 1
    parent_i = -1

    for j in range(i):
        if a[j] < ai:
            value = dp[j] + 1

            if value > dpi:
                dpi = value
                parent_i = j

    dp[i] = dpi
    parent[i] = parent_i

    if dpi > dp[best]:
        best = i

print(dp[best])

ans = []
cur = best

while cur != -1:
    ans.append(a[cur])
    cur = parent[cur]

ans.reverse()

print(*ans)