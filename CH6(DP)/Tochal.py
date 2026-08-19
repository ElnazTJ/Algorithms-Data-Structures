MOD = 1000000007

n = int(input())
h = list(map(int, input().split()))

values = sorted(set(h))
rank = {x: i for i, x in enumerate(values)}
h = [rank[x] for x in h]

dp = [[0] * (n + 1) for _ in range(n)]

for i in range(n):
    dp[i][i] = 1
    dp[i][i + 1] = 1

for length in range(2, n + 1):
    for l in range(n - length + 1):
        r = l + length

        dp[l][r] = dp[l][r - 1]

        if h[l] == h[r - 1]:
            dp[l][r] += 1

            for x in range(l + 1, r - 1):
                if h[x] >= h[l]:
                    dp[l][r] += dp[x][r - 1]

            dp[l][r] %= MOD

ans = 0

for l in range(n):
    ans += dp[l][n]
    ans %= MOD

print(ans)