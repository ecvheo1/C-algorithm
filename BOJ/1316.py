n = int(input())
sum = n

for _ in range(n):
    word = input()
    x = {}
    for i in range(len(word)):
        if word[i] in x:
            if i-x[word[i]] == 1:
                x[word[i]] = i
            elif i-x[word[i]] >= 2:
                sum -= 1
                break
        else :
            x[word[i]] = i

print(sum)
