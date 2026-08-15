import heapq

n, k = map(int, input().split())

v = []

for _ in range(n):
    b, a = map(int, input().split())
    v.append((b, a))

v.sort()       
pq = []         # Min Heap
i = 0

while True:

    while i < n and v[i][0] <= k:
        heapq.heappush(pq, -(v[i][1] - v[i][0]))
        i += 1

    if not pq:
        break

    best = -heapq.heappop(pq)

    if best <= 0:
        break

    k += best

print(k)