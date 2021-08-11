import sys

n = int(input())
arr = list(map(int, sys.stdin.readline().split()))

k = sorted(list(set(arr)))

dic = { k[i] : i for i in range(len(k)) }
for i in arr:
    print(dic[i], end=' ')
