n, k = map(int, input().split())

pattern = []

for i in range(n):
    pattern.append(input())


def solve(x, y, k):

    if k == 0:
        return "."

    blocksize = pow(n, k - 1)

    row = x // blocksize
    col = y // blocksize

    if pattern[row][col] == "*":
        return "*"

    x %= blocksize
    y %= blocksize

    return solve(x, y, k - 1)


size = pow(n, k)

for i in range(size):
    for j in range(size):
        print(solve(i, j, k), end="")
    print()