import sys

n = int(sys.stdin.readline())
array = []
for _ in range(n):
    a, b = sys.stdin.readline().split()
    array.append((a, int(b)))

array = sorted(array, key = lambda x : x[1])

for i in array:
    print(i[0], end=' ')