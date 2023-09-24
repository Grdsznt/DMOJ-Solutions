import sys
input = sys.stdin.readline

N = int(input())

arr = list(map(int, input().split()))

memo = [[0]* N for i in range(N)]

ans  = [float('inf')] * (N+1)
ans[1] = 0

for len in range(2, N+1):
    for L in range(N-len):
        L, R = 0, len-1
        while R < N:
            memo[L][R] = abs(arr[L] - arr[R]) + memo[L+1][R+1]
            ans[len] = min(ans[len], memo[L][R])
            L += 1
            R += 1 

for i  in range(1, N+1):
    print(ans[i], end = ' ');