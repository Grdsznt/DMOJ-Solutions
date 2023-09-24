
a, b = map(int, input().split())

lights = [0]*(a+2)
# do not need to convert to diff array because 0 diff array is already made
for i in range(b):
    l, r = map(int, input().split())

    # l[L] += v, l[R+1] -=v
    lights[l] += 1
    lights[r+1] -= 1

ans = 0
# we do not use indx 0, we do not use the last index, just loop through the diff array
for j in range(1, a+1):
    lights[j+1] = lights[j] + lights[j+1];

    #this works, because if lights are odd, that means they are on. Which also means that the mod 2 of the number will be one, and you add one everytime
    #you see a light that is on, so it will produce the right output
    ans += lights[j] % 2

print(ans)