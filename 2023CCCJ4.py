C = int(input())
row1 = list(map(int, input().split()))
row2 = list(map(int, input().split()))

total = 0

for i in range(1, C-1):
    if i % 2 == 0 :
        if row1[i] == 1:
            total += 3
            if row1[i+1] == 1:
                total -= 1
            if row1[i-1] == 1:
                total -= 1
            if row2[i] == 1:
                total -= 1
        if row2[i] == 1:
            total += 3
            if row2[i+1] == 1:
                total -= 1
            if row2[i-1] == 1:
                total -= 1
            if row1[i] == 1:
                total -= 1
    else: 
        if row1[i] == 1:
            total += 3
            if row1[i+1] == 1:
                total -= 1
            if row1[i-1] == 1:
                total -= 1
        if row2[i] == 1:
            total += 3
            if row2[i+1] == 1:
                total -= 1
            if row2[i-1] == 1:
                total -= 1
            


if row1[0] == 1:
    total += 3
    if row1[1] == 1:
        total -= 1
    if row2[0] == 1:
        total -= 1

if row2[0] == 1:
    total += 3
    if row2[1] == 1:
        total -= 1
    if row1[0] == 1:
        total -= 1

if row1[C-1] == 1:
    total += 3
    if row1[C-2] == 1:
        total -= 1
    if row2[C-1] == 1:
        total -= 1

if row2[C-1] == 1:
    total += 3
    if row2[C-2] == 1:
        total -= 1
    if row1[C-1] == 1:
        total -= 1

print(total)