x = int(input())
n = int(input())

def power(a, n):
    return a ** n

def solve(x, i):
    if x == 0:
        return 1

    if x < 0 or power(i, n) > x:
        return 0

    ans = solve(x, i + 1)

    ans += solve(x - power(i, n), i + 1)

    return ans

print(solve(x, 1))
