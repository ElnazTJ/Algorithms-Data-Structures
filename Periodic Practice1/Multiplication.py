n = int(input())

a = list(map(int, input().split()))
b = list(map(int, input().split()))

a = [(a[i], i) for i in range(n)]

a.sort()
b.sort()

ans = [0] * n
total = 0

for i in range(n):
    value, index = a[i]

    ans[index] = b[i]
    total += value * b[i]

print(total)
print(*ans)