import sys
import heapq
input = sys.stdin.readline
INF = int(1e9)


n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append((b, 1))
    graph[b].append((a, 1))

distance = [INF] * (n+1)
distance[1] = 0

q = [(0, 1)]
while q:
    dist, now = heapq.heappop(q)
    if distance[now] < dist:
        continue
    for i in graph[now]:
        cost = dist + i[1]
        if cost < distance[i[0]]:
            distance[i[0]] = cost
            heapq.heappush(q, (cost, i[0]))

maxValue = int(-1e9)
for i in distance:
    if i != INF:
        maxValue = max(maxValue, i)

print(distance.index(2), maxValue, distance.count(maxValue))