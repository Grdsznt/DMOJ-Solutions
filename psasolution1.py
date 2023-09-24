import sys
input = sys.stdin.readline

string = input().strip()

# init 2D array for first index to n is for one num. We use 0s. we do it 26 times for the 26 letters
# I think it's because it takes less time to do this then to check for each letter
psa[[0] * (len(string)+1) for i in range (26)]



