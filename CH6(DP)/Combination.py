MOD = 10**9 + 7

q = int(input())

queries = []
max_n = 0

for _ in range(q):
    n, r = map(int, input().split())
    queries.append((n, r))
    max_n = max(max_n, n)


dp = [[0] * (max_n + 1) for _ in range(max_n + 1)]


for n in range(max_n + 1):
    dp[n][0] = 1
    dp[n][n] = 1


for n in range(1, max_n + 1):
    for r in range(1, n):
        dp[n][r] = (dp[n-1][r-1] + dp[n-1][r]) % MOD


for n, r in queries:
    if r > n:
        print(0)
    else:
        print(dp[n][r])