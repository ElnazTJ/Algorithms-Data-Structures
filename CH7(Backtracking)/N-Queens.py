n, k = map(int, input().split())

a = [[' '] * n for _ in range(n)]


def check(row, col):

    # سطر
    for j in range(n):
        if a[row][j] == 'Q':
            return False

    # ستون
    for i in range(n):
        if a[i][col] == 'Q':
            return False

    # قطر بالا-چپ
    i = row - 1
    j = col - 1

    while i >= 0 and j >= 0:
        if a[i][j] == 'Q':
            return False
        i -= 1
        j -= 1

    # قطر بالا-راست
    i = row - 1
    j = col + 1

    while i >= 0 and j < n:
        if a[i][j] == 'Q':
            return False
        i -= 1
        j += 1

    # قطر پایین-چپ
    i = row + 1
    j = col - 1

    while i < n and j >= 0:
        if a[i][j] == 'Q':
            return False
        i += 1
        j -= 1

    # قطر پایین-راست
    i = row + 1
    j = col + 1

    while i < n and j < n:
        if a[i][j] == 'Q':
            return False
        i += 1
        j += 1

    return True


def solve(pos, cnt):

    if cnt == k:
        return 1

    if pos == n * n:
        return 0

    ans = 0

    for p in range(pos, n * n):

        i = p // n
        j = p % n

        if check(i, j):

            a[i][j] = 'Q'

            ans += solve(p + 1, cnt + 1)

            a[i][j] = ' '

    return ans


print(solve(0, 0))