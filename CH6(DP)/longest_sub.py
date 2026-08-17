s = input()
p = input()

n = len(s)
m = len(p)

dp = [[0] * (m + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    for j in range(1, m + 1):
        if s[i - 1] == p[j - 1]:
            dp[i][j] = dp[i - 1][j - 1] + 1
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

i = n
j = m
answer = []

while i > 0 and j > 0:
    if s[i - 1] == p[j - 1]:
        answer.append(s[i - 1])
        i -= 1
        j -= 1
    elif dp[i - 1][j] >= dp[i][j - 1]:
        i -= 1
    else:
        j -= 1

answer.reverse()

print(dp[n][m])
print(''.join(answer))