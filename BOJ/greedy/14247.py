n = int(input())
tree = list(map(int, input().split()))
grow = list(map(int, input().split()))

k = []
for i in range(n):
    k.append([tree[i], grow[i]])

k.sort(key = lambda x : x[1])

answer = 0
for i in range(n):
    answer += k[i][0] + k[i][1] * i
print(answer)