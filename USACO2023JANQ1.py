N = int(input())
cs = input()
cows = []
cows.extend(cs)
listFromCow = list(map(int, input().split()))
psa = [0]*(N)
cntg = 0
cnth = 0
#get freq
for i in range(N):
    if cows[i] == "G":
        cntg += 1
    else: 
        cnth += 1

cnt=0
cnt2 = 0

#check if leader
for j in range(N):
    for k in range(listFromCow[j]-j):
        if cows[k] == "G":
            cnt += 1 
        else:
            cnt2 += 1
    if cnt == cntg:
        psa[j] = 10
    elif cnt2 == cnth:
        psa[j] = 11

numpairs = 0

for l in range(N):
    for k in range(listFromCow[j]-j):
        if psa[k+l] == 10 and psa[l] != 11 and psa[l] != 10:
            psa[l] == 11
        if psa[k+l] == 11 and psa[l] != 11 and psa[l] != 10:
            psa[l] == 10

    if psa[l] == 11:
        for m in range(N):
            if psa[m] == 10:
                numpairs += 1
                break 
    if psa[l] == 10:
        for m in range(N): 
            if psa[m] == 11:
                numpairs += 1
                break 

print(numpairs)



            

