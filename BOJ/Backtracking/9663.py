import sys

n = int(sys.stdin.readline().rstrip())
count = 0
board = [0] * n
visited = [False] * n # n번째 열에 queen이 있는지 표현하는 리스트

def check(x): # 기존에 있는 queen들과 대각선 방향으로 겹치는지 확인
    for i in range(x):
        if x - i == abs(board[x] - board[i]):
            return False
    return True

def queen(x):
    global count
    if x == n:
        count += 1
        return
    for i in range(n):
        if not visited[i]: # i번째 열에 queen이 없을 경우
            board[x] = i
            if check(x): # x행 i열에 둔 queen이 대각선 방향에 있는 queen들과 겹치치 않을 경우
                visited[i] = True
                queen(x+1)
                visited[i] = False

queen(0)
print(count)