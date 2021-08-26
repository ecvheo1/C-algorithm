// 10000보다 작거나 같은 자연수라는 범위 조건이 있으므로 계수 정렬

#include <iostream>

using namespace std;

int n;
int a[10001]; // 배열을 전역변수로 선언하면 프로그램이 시작과 동시에 배열에 있는 원소값은 0으로 초기화
 

int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	for(int i=0; i < 10001; i++) {
		while(a[i] != 0) {
			printf("%d\n", i);
			a[i]--;
		}	
	}
}

 
