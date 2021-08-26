import sys
import math

def sosu(n):
    if n == 1:
        return False
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True

n = int(sys.stdin.readline())

for i in range(n):
    x = int(sys.stdin.readline())
    for j in range(x//2, 1, -1):
        if sosu(j) and sosu(x-j):
            print(j, x-j)
            break
