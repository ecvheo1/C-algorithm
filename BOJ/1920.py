// 이분 탐색 (이진 검색)

n = int(input())
x = list(map(int, input().split()))

x.sort(reverse=False)

m = int(input())
k = list(map(int, input().split()))

for i in range(m):
    start = 0
    end = n-1
    answer = 0

    while(1):
        c = int((start+end) / 2)
        if(start > end):
            break

        if(k[i] > x[c]):
            start = c+1
        elif(k[i] < x[c]):
            end = c-1
        else:
            answer = 1
            break
    print(answer)    

