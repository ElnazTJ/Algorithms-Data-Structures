n, k = map(int, input().split())

visited = [[False] * n for _ in range(n)]

dr = [2, 2, -2, -2, 1, 1, -1, -1]
dc = [1, -1, 1, -1, 2, -2, 2, -2]


def solve(row, col, cnt):

    if cnt == k:
        visited[row][col] = True
        return

    for i in range(8):

        nr = row + dr[i]
        nc = col + dc[i]

        if 0 <= nr < n and 0 <= nc < n:
            solve(nr, nc, cnt + 1)


solve(0, 0, 0)

ans = 0

for i in range(n):
    for j in range(n):
        if visited[i][j]:
            ans += 1

print(ans)