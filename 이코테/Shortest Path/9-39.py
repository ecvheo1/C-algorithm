import sys
import heapq
input = sys.stdin.readline
INF = int(1e9)
dx = 1, -1, 0, 0
dy = 0, 0, -1, 1

t = int(input())
for _ in range(t):
    n = int(input())
    graph = []
    for _ in range(n):
        graph.append(list(map(int, input().split())))
    
    x, y = 0, 0
    distance = [[INF] * (n) for _ in range(n)]
    distance[x][y] = graph[x][y]
    q = [(graph[x][y], x, y)]

    while q:
        dist, x, y = heapq.heappop(q)
        if distance[x][y] < dist:
            continue
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= n:
                continue
            cost = dist + graph[nx][ny]
            if cost < distance[nx][ny]:
                distance[nx][ny] = cost
                heapq.heappush(q, (cost, nx, ny))
print(distance[n-1][n-1])
