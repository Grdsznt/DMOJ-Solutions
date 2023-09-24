import sys
input = sys.stdin.readline
 
word = input().strip()
R, C = int(input()), int(input())
g = [input().strip().split() for i in range(R)]
ways = 0
dir = [(-1, 0), (-1, 1),  (0, 1), (1, 1) , (1, 0) , (1, -1) , (0, -1), (-1, -1)]
 
def fun(r, c, k, idx, turn):
    global ways
    if idx == len(word): #base case, if it's as long as the word
        ways += 1
        return #stop this one recursive call
    for i in range(k-2, k+3, 2):
        nk = (i + 8) % 8 # k to be perpendicular
        nr, nc = r + dir[nk][0], c + dir[nk][1]
        if 0 <= nr < R and 0 <= nc < C and g[nr][nc] == word[idx] and (nk == k or not turn):
            fun(nr, nc, nk, idx+1, turn or nk != k)
 
for i in range(R): #horizontal pointer
    for j in range(C): #vertical pointer
        if g[i][j] == word[0]: #if a letter starts with the first letter of the word
            for k in range(8): # 8 directions
                ni, nj = i + dir[k][0], j + dir[k][1] #new vert and horizontal to get a new index, using direction system
                if 0 <= ni < R and 0 <= nj < C and g[ni][nj] == word[1]: #check if the new index is out of bounds, and if it's equal to the second letter
                    fun(ni, nj, k, 2, False)
print(ways)