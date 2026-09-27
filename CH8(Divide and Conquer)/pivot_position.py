import sys

sys.setrecursionlimit(200000)

pivots = []


def partition_first(a, l, r):
    pivot = a[l]
    ls = l

    for i in range(l + 1, r + 1):
        if a[i] <= pivot:
            ls += 1
            a[i], a[ls] = a[ls], a[i]

    a[l], a[ls] = a[ls], a[l]
    return ls


def quick_sort(a, l, r):
    if l >= r:
        return

    pivots.append(a[l])

    p = partition_first(a, l, r)

    quick_sort(a, l, p - 1)
    quick_sort(a, p + 1, r)


def main():
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    n = int(input_data[0])
    a = [int(x) for x in input_data[1 : n + 1]]

    quick_sort(a, 0, n - 1)

    print(*(pivots))


if __name__ == "__main__":
    main()