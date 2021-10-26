import sys

n, m = map(int, sys.stdin.readline().split())
rice = sorted(list(map(int, sys.stdin.readline().split())))

left = 1
right = rice[-1]

while left <= right:
    mid = (left+right)//2
    sum = 0
    for i in rice:
        if i > mid:
            sum += (i - mid)
    if sum <  m:
        right = mid - 1
    else:
        result = mid
        left = mid + 1
print(result)