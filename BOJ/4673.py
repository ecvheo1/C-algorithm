def d(n):
    sum = 0
    for i in list(str(n)):
        sum += int(i)
    return n + sum
    
x = list(range(1,10001))

for i in range(1, 10001):
    if d(i) in x:
        x.remove(d(i))

for i in x:
    print(i)
