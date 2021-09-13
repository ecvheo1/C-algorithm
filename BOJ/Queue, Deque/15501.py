import sys
from collections import deque

n = int(sys.stdin.readline())
puzzleOne = list(map(int, sys.stdin.readline().split()))
puzzleTwo = list(map(int, sys.stdin.readline().split()))

x = [[int(0)] * 2 for _ in range(n+1)]

if n == 1:
    print('good puzzle')
else:
    for i in range(n):
        if i == 0:
            x[puzzleOne[i]][0] = puzzleOne[-1]
            x[puzzleOne[i]][1] = puzzleOne[i+1]
        elif i == n-1:
            x[puzzleOne[i]][0] = puzzleOne[i-1]
            x[puzzleOne[i]][1] = puzzleOne[0]
        else:
            x[puzzleOne[i]][0] = puzzleOne[i-1]
            x[puzzleOne[i]][1] = puzzleOne[i+1]

    flag = 0
    for i in range(n):
        if i == 0:
            if (puzzleTwo[-1] not in x[puzzleTwo[i]]) or (puzzleTwo[i+1] not in x[puzzleTwo[i]]):
                flag = 1
                break
        elif i == n-1:
            if (puzzleTwo[i-1] not in x[puzzleTwo[i]]) or (puzzleTwo[0] not in x[puzzleTwo[i]]):
                flag = 1
                break
        else:
            if (puzzleTwo[i-1] not in x[puzzleTwo[i]]) or (puzzleTwo[i+1] not in x[puzzleTwo[i]]):
                flag = 1
                break

    if flag == 0:
        print('good puzzle')
    else:
        print('bad puzzle')