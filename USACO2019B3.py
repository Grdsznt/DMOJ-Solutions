import sys
from itertools import permutations
input = sys.stdin.readline

n, x, y = int(input()), [] , []
for i in range(n):
    s = input().strip().split(" ")
    x.append(s[0])
    y.append(s[-1])

a = ["Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"]
a.sort()

for perm in permutations(a):
    work = True
    for j in range(n):
        if abs(perm.index(x[j]) - perm.index(y[j])) != 1:
            work = False
    
    if work:
        print('\n'.join(perm))
        sys.exit(0)