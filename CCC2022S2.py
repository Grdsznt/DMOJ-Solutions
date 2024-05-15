x = [input().strip().split() for i in range(int(input()))]
y = [input().strip().split() for i in range(int(input()))]

hashmap = {}

for i in range(int(input())):
    g, h, j = input().strip().split()
    hashmap[g] = hashmap[h] = hashmap[j] = i
ans = 0
for a, b in x:
    ans += hashmap[a] != hashmap[b]

for a, b in y:
    ans += hashmap[a] == hashmap[b]

print(ans)