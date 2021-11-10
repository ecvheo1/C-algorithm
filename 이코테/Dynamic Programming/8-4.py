import sys
input = sys.stdin.readline

n = int(input())

d = [0] * 1000

d[1] = 1
d[2] = 3
d[3] = 5

for i in range(4, n+1):
    d[i] = d[i-1] + d[i-2] * 2

print(d[n])