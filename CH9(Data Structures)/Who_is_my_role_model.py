import sys
from collections import deque
def solve():
    input = sys.stdin.read().split()
    if not input:
        return
    n=int(input[0])
    a=[0]+[int(x) for x in input[1:n+1]]
    in_degree=[0]*(n+1)
    for i in range(1,n+1):
        in_degree[a[i]] += 1

    q=deque(i for i in range(1,n+1) if in_degree[i]==0)
    while q:
        u = q.popleft()
        v=a[u]
        in_degree[v] -=1
        if in_degree[v] == 0:
            q.append(v)

    ans=[i for i in range(1,n+1) if in_degree[i]>0]
    print(len(ans))
    print(*ans)

if __name__ == "__main__":
    solve()