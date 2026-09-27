def power(base, exp):
    if exp == 0:
        return 1

    if exp == 1:
        return base

    result = power(base, exp // 2)

    if exp % 2 == 0:
        return result * result
    else:
        return base * result * result


base = float(input())
exp = int(input())

print(f"{power(base, exp):.3f}")