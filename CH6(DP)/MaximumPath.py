n, m = map(int, input().split())

a = []

for _ in range(n):
    a.append(list(map(int, input().split())))

dp = [[0] * m for _ in range(n)]
parent = [[''] * m for _ in range(n)]

dp[n - 1][0] = a[n - 1][0]

for i in range(n - 2, -1, -1):
    dp[i][0] = dp[i + 1][0] + a[i][0]
    parent[i][0] = 'U'

for j in range(1, m):
    dp[n - 1][j] = dp[n - 1][j - 1] + a[n - 1][j]
    parent[n - 1][j] = 'R'

for i in range(n - 2, -1, -1):
    for j in range(1, m):
        if dp[i + 1][j] > dp[i][j - 1]:
            dp[i][j] = dp[i + 1][j] + a[i][j]
            parent[i][j] = 'U'
        else:
            dp[i][j] = dp[i][j - 1] + a[i][j]
            parent[i][j] = 'R'

print(dp[0][m - 1])

answer = ""

i = 0
j = m - 1

while i != n - 1 or j != 0:
    if parent[i][j] == 'U':
        answer += 'U'
        i += 1
    else:
        answer += 'R'
        j -= 1

answer = answer[::-1]

print(answer)