n = int(input())
w = list(map(int, input().split()))

if n >= 20:
    print("YAY!")
    exit()

sums = set()

for mask in range(1, 1 << n):

    total = 0

    for i in range(n):
        if mask & (1 << i):
            total += w[i]

    if total in sums:
        print("YAY!")
        exit()

    sums.add(total)

print("AWW!")