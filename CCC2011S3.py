crystalBlock = [(1, 0), (2, 0), (2, 1), (3, 0)]
unsureBlock = [(1, 1), (2, 2), (3, 1)]

def isCrystal(m, x, y):
    block = 5**(M-1)
    bx, by = x//block, y//block
    if (bx, by) in crystalBlock: return True
    elif (bx, by) in unsureBlock:
        if m==1: return False
        return isCrystal(m-1, x%block, y%block)
    else:
        return False



for _ in range(int(input())):
    m, x, y = map(int, input().split())
    print('crystal') if isCrystal(m, x, y) else print ('empty')