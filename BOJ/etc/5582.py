import sys

a = sys.stdin.readline().rstrip()
b = sys.stdin.readline().rstrip()

lcs = [[0] *  (len(b)+1) for _ in range(len(a)+1)]
answer = 0

for i in range(1, len(a)+1):
    for j in range(1, len(b)+1):
        if a[i-1] == b[j-1]:
            lcs[i][j] = lcs[i-1][j-1] + 1
            answer = max(lcs[i][j], answer)

print(answer)
