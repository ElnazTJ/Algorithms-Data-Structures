n, k = map(int, input().split())

p = []
used = [False] * 8
ans = 0


def solve():
    cnt = 0

    for i in range(n):
        for j in range(i + 1, n):
            if p[i] > p[j]:
                cnt += 1

    return cnt


def build():
    global ans

    if len(p) == n:
        if solve() == k:
            ans += 1
        return

    for i in range(1, n + 1):
        if not used[i]:

            p.append(i)
            used[i] = True

            build()

            used[i] = False
            p.pop()


if __name__ == "__main__":
    build()
    print(ans)