def hansu(k):
    if k < 100:
        return 1
    else:
        value = list(str(k))
        for i in range(1, len(value)-1):
            if int(value[0])-int(value[1]) != int(value[i])-int(value[i+1]):
                return 0
            else:
                return 1

n = int(input())
sum = 0
for i in range(1, n+1):
    sum += hansu(i)
print(sum)
