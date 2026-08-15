from decimal import Decimal, getcontext

getcontext().prec = 30

n, V = map(int, input().split())

vh = []

for _ in range(n):
    h, v = map(int, input().split())
    vh.append((h, v))

vh.sort(key=lambda x: Decimal(x[0]) / Decimal(x[1]), reverse=True)

ans = Decimal(0)

for h, v in vh:

    if V == 0:
        break

    if V >= v:
        ans += h
        V -= v

    else:
        ans += Decimal(V) / Decimal(v) * Decimal(h)
        V = 0
        break

print(f"{ans:.4f}")