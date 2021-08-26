n = int(input())

for _ in range(n):
    ps = list(input());
    x = {}
    for i in ps:
        if i == '(':
            if '(' in x:
                x['('] = x['('] + 1
            else:
                x['('] = 1
        else:
            if '(' in x and x['('] >= 1:
                x['('] = x['('] - 1
            else:
                x['*'] = 1
    if ('(' in x and x['('] >= 1) or '*' in x:
        print('NO')
    else:
        print('YES')
