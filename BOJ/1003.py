n = int(input())

for _ in range(n):
    x = int(input())
    zero, one, tmp = 1, 0, 0
    for _ in range(x):
        tmp = one
        one = zero + one
        zero = tmp
    print(zero, one)
