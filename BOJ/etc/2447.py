def star_func(k):
    make = []
    for i in range(3*len(k)):
        if i // len(k) == 1:
            make.append(k[i%len(k)] + ' '*len(k) + k[i%len(k)])
        else:
            make.append(3*k[i%len(k)])
    return make

star = ['***', '* *', '***']

n = int(input())
x = 0
while n != 3:
    n /= 3
    star = star_func(star)

print('\n'.join(i for i in star))
