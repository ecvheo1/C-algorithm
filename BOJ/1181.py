import sys


n = int(input())
arr = []
for _ in range(n):
    word = sys.stdin.readline().strip()
    arr.append((word, len(word)))

arr = list(set(arr))

arr.sort(key = lambda word: (word[1], word[0]))

for i in arr:
    print(i[0])
