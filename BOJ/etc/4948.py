n = int(input())

while n != 0:
    sum = n
    for i in range(n+1, 2*n+1):
        for j in range(2, int(i**0.5)+1):
            if i%j == 0:
                sum -= 1
                break
    print(sum)
    n = int(input())
