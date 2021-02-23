// 선택정렬 : 가장 작은 것을 골라서 가장 앞으로 보낸다
/*
	1 2 3 4 5 6 7 8 9 10
	10 + 9 + 8 + ... 1
	=> 10 * (10 + 1) / 2 = 55
	=> N * (N + 1) / 2
	=> O(N^2) : 빅오 표기법이랑 특정한 알고리즘의 수행시간(총 연산횟수)을
				 가장 간략하게 표현하는 것 
*/

#include <stdio.h>

int main(void) {
	
	int i, j, min, index, temp;
	int array[10] = {1,10,5,8,7,6,4,3,2,9};
		
	for(i=0; i < 10; i++) {
		min = 9999;
		for(j=i; j<10; j++)
		{
			if(min > array[j]) {
				min = array[j];
				index = j;
			}
		}
		temp = array[i];
		array[i] = min;
		array[index] = temp;
	}
	
	for(int i=0; i<10; i++)
	{
		printf("%d ", array[i]);
	}
	
	return 0;
}
