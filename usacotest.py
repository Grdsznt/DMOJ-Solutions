def count_pairs(n, breed, e):
    guernsey = holstein = 0
    count = 0
    while guernsey < n and holstein < n:
        if breed[guernsey] == 'G':
            if e[guernsey] >= holstein + 1:
                count += 1
                holstein = e[guernsey]
            guernsey += 1
        else:
            if e[holstein] >= guernsey + 1:
                count += 1
                guernsey = e[holstein]
            holstein += 1
    return count if guernsey == n or holstein == n else count + 1

n = int(input().strip())
breed = input().strip()
e = list(map(int, input().strip().split()))
print(count_pairs(n, breed, e))
