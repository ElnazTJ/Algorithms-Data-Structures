n, m = map(int, input().split())

a = []

for _ in range(n):
    a.append(list(map(int, input().split())))

INF = 10**30

left = [INF] * m
right = [INF] * m

right[0] = a[0][0]

for j in range(1, m):
    right[j] = right[j - 1] + a[0][j]

left[0] = a[0][0]

for i in range(1, n):
    newleft = [INF] * m
    newright = [INF] * m

    for j in range(m):
        up = min(left[j], right[j])

        if j == 0:
            newright[j] = up + a[i][j]
        else:
            newright[j] = min(up, newright[j - 1]) + a[i][j]

    for j in range(m - 1, -1, -1):
        up = min(left[j], right[j])

        if j == m - 1:
            newleft[j] = up + a[i][j]
        else:
            newleft[j] = min(up, newleft[j + 1]) + a[i][j]

    left = newleft
    right = newright

print(right[m - 1])