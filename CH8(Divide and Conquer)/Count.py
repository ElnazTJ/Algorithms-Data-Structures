from bisect import bisect_left, bisect_right

T = int(input())

for _ in range(T):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    ps = [0] * (n + 1)

    for i in range(1, n + 1):
        ps[i] = ps[i - 1] + a[i - 1]

    ps.sort()

    ans = 0

    for i in range(n + 1):

        left = bisect_left(ps, ps[i] - k)
        right = bisect_right(ps, ps[i] + k)

        bad = right - left

        ans += (n + 1) - bad

    print(ans // 2)