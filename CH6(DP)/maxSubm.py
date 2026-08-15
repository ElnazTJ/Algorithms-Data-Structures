n, m = map(int, input().split())

a = []

for _ in range(n):
    a.append(list(map(int, input().split())))


if n > m:
    b = [[0] * n for _ in range(m)]

    for i in range(n):
        for j in range(m):
            b[j][i] = a[i][j]

    a = b
    n, m = m, n


answer = float('-inf')


for top in range(n):

    temp = [0] * m

    for bottom in range(top, n):

        for col in range(m):
            temp[col] += a[bottom][col]

        # Kadane
        current = temp[0]
        best = temp[0]

        for col in range(1, m):
            current = max(temp[col], temp[col] + current)
            best = max(best, current)

        answer = max(answer, best)


print(answer)