# 3-2. 큰 수의 법칙

n, m, k = map(int, input().split())
data = list(map(int, input().split()))

data.sort()
first = data[-1]
second = data[-2]

count = m // (k+1) * k
count += m % (k+1)

result = 0
result += count * first
result += (m-count) * second

print(result)