import sys

n = int(sys.stdin.readline())
store = sorted(list(map(int, sys.stdin.readline().split())))
m = int(sys.stdin.readline())
guest = list(map(int, sys.stdin.readline().split()))

def binarySearch(store, i, left, right):
    while left <= right:
        mid = (left+right)//2
        if store[mid] == i:
            return mid
        elif store[mid] > i:
            right = mid - 1
        else:
            left = mid + 1
    return None

for i in guest:
    result = binarySearch(store, i, 0, n-1)
    if result != None:
        print('Yes', end=' ')
    else:
        print('No', end=' ')