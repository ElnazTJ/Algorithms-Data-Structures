def solve(n):

    if n==0:
        return 1
    
    if n<0:
        return 0
    
    return solve(n-1)+solve(n-2)+solve(n-5)

n=int(input())
print(solve(n))