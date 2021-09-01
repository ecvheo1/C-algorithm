# t = int(input())
# for _ in range(t):
#     n = int(input())
#     stock = list(map(int, input().split()))
#     answer = 0
#     while len(stock) != 0:
#         high = max(stock)
#         k = stock.index(max(stock))
#         for i in range(0, k):
#             answer = answer + (high - stock[i])
#         stock = stock[k+1:]
#     print(answer)

t = int(input())
for _ in range(t):
    n = int(input())
    stock = list(map(int, input().split()))
    answer = 0
    high = stock[-1]
    for i in range(n-2, -1, -1):
        if stock[i] > high:
            high = stock[i]
        else:
            answer = answer + (high - stock[i])
    print(answer)