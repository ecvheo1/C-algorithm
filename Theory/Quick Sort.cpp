// 퀵정렬 
/*
	1 10 5 8 7 6 4 3 2 9
	평균 시간 복잡도: O(N*logN)
	최악의 경우 시간 복잡도 :  O(N^2) 거의 정렬이 되어있는 경우이다 
*/

#include <stdio.h>

int number = 10;
int data[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

void quickSort(int *data, int start, int end) {
	if (start >= end) // 원소가 1개인 경우 
		return;
	
	int key = start; // 키는 첫번째 원소 
	int i = start + 1;
	int j = end;
	int temp;
	
	while(i <= j) { // 엇갈릴 때까지 반복 
		while(data[i] <= data[key]) { // 키 값보다 큰 값을 만날 때까지 
			i++;
		}
		while(data[j] >= data[key] && j > start) { // 키 값보다 작은 값을 만날 때까지 
			j--;
		}
		if(i > j) { // 엇갈렸다면 
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else { // 엇갈리지 않았다면 
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}
	}
	
	quickSort(data, start, j-1);
	quickSort(data, j+1, end);
}

int main(void) {
	
	quickSort(data, 0, number-1);
	
	for(int i=0; i<10; i++)
	{
		printf("%d ", data[i]);
	}
	
	return 0;
}
