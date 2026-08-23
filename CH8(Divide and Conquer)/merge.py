n, k = map(int, input().split())

a = []

for _ in range(k):
    row = list(map(int, input().split()))
    a.append(row)


def mergeTwo(left, right):

    result = []

    p1 = 0
    p2 = 0

    while p1 < len(left) and p2 < len(right):

        if left[p1] < right[p2]:
            result.append(left[p1])
            p1 += 1

        else:
            result.append(right[p2])
            p2 += 1

    while p1 < len(left):
        result.append(left[p1])
        p1 += 1

    while p2 < len(right):
        result.append(right[p2])
        p2 += 1

    return result


def mergeArrays(l, r):

    if r - l == 1:
        return a[l]

    mid = (l + r) // 2

    left = mergeArrays(l, mid)
    right = mergeArrays(mid, r)

    return mergeTwo(left, right)


ans = mergeArrays(0, k)

for x in ans:
    print(x, end=' ')