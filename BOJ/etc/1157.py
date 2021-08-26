word = input().upper()
k = list(set(word))
x =[]
for i in k:
    x.append(word.count(i))

if x.count(max(x)) >= 2:
    print('?')
else:
    print(k[x.index(max(x))])
