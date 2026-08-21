n = int(input())

a = []

for _ in range(n):
    x = list(map(int, input().split()))
    a.append(x[1:])

chosen = set()
ans = 0

def solve(i):
    global ans

    if i == n:
        ans += 1
        return

    for x in a[i]:
        if x not in chosen:
            chosen.add(x)

            solve(i + 1)

            chosen.remove(x)

solve(0)

print(ans)