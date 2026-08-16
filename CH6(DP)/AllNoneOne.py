n, S = map(int, input().split())

size = []
total_price = []
min_c = []

for _ in range(n):
    data = list(map(int, input().split()))

    s = data[0]
    prices = data[1:]

    size.append(s)
    total_price.append(sum(prices))

    if s > 0:
        min_c.append(min(prices))
    else:
        min_c.append(0)

dp = [[0] * (S + 1) for _ in range(n + 1)]
choice = [['0'] * (S + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    for j in range(S + 1):

        dp[i][j] = dp[i - 1][j]
        choice[i][j] = '0'

        if size[i - 1] > 0 and j >= min_c[i - 1]:
            val = dp[i - 1][j - min_c[i - 1]] + 1

            if val > dp[i][j]:
                dp[i][j] = val
                choice[i][j] = '1'

        if j >= total_price[i - 1]:
            val = dp[i - 1][j - total_price[i - 1]] + size[i - 1]

            if val > dp[i][j]:
                dp[i][j] = val
                choice[i][j] = '2'

ans = ['0'] * n
j = S

for i in range(n, 0, -1):
    ans[i - 1] = choice[i][j]

    if choice[i][j] == '1':
        j -= min_c[i - 1]

    elif choice[i][j] == '2':
        j -= total_price[i - 1]

print(dp[n][S])
print(''.join(ans))