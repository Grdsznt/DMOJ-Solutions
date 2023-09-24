import sys
input = sys.stdin.readline;

n, m, k = map(int, input().split())
a = list(map(int, input().split()))
a.append(m+1)
a.insert(0, 0)
ans = 0
for i in range(1, n+2):
    if i>1:
        ans = max(ans, a[i] - max(a[i-1]-k, a[i-2])-1)
    if i <= n:
        ans = max(ans, min(a[i]+k, a[i+1]) - a[i-1]-1)
print(ans)