import heapq

n = int(input())
w = list(map(int, input().split()))

heapq.heapify(w)

ans = 0

while len(w) > 1:
    x = heapq.heappop(w)
    y = heapq.heappop(w)

    total = x + y
    ans += total

    heapq.heappush(w, total)

print(ans)