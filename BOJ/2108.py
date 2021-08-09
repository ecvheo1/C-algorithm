import sys
from collections import Counter

n = int(input())
arr = []
for _ in range(n):
    arr.append(int(sys.stdin.readline()))

arr.sort()

print(int(round(sum(arr)/n, 0)))
print(arr[n//2])
if n == 1:
    print(arr[0])
else:
    c = Counter(arr).most_common(2)
    print(c[1][0] if c[0][1] == c[1][1] else c[0][0])
print(max(arr)-min(arr))
