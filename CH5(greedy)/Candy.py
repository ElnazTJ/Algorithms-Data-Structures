import heapq

n, c = map(int, input().split())

pq = []

nums = map(int, input().split())

for x in nums:
    heapq.heappush(pq, -x)


while c > 0 and pq:
    x = -heapq.heappop(pq)

    d = min(c, max(0, x - c))
    c -= d


print(c)