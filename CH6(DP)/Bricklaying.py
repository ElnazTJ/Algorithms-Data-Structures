MOD = 10**9 + 7

q = int(input())

Q = []
max_n = 0

for _ in range(q):
    n = int(input())
    Q.append(n)
    max_n = max(max_n, n)

f = [0] * (max_n + 1)

f[0] = 1

if max_n >= 1:
    f[1] = 1

if max_n >= 2:
    f[2] = 1

if max_n >= 3:
    f[3] = 2

for i in range(4, max_n + 1):
    f[i] = (f[i-1] + f[i-2] + f[i-3] - f[i-4]) % MOD

for n in Q:
    print(f[n])