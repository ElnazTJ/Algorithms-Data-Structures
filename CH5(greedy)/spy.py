n = int(input())

for _ in range(n):
    s = input()

q = int(input())

agencies = set()
ans = 0

for _ in range(q):
    s = input()
    agencies.add(s)

    if len(agencies) == n:
        ans += 1
        agencies.clear()
        agencies.add(s)

print(ans)