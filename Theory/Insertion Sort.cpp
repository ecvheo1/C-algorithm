// 삽입정렬 :  
// 정렬이 되어있다고 가정한다. 
/*
	1 2 3 4 5 6 7 8 9 10
	1 + 2 + 3 + ... 10
	=> O(N^2)
	정렬 알고리즘 중 가장 베스트인 알고리즘
	거의 정렬된 상태에 한해서는 어떤 알고리즘보다도 빠르다는 특징을 가지고있다.
	ex) 2 3 4 5 6 7 8 9 10 1 
*/

#include <stdio.h>

int main()
{
	int i,j,temp;
	int array[10] = {1,10,5,8,7,6,4,3,2,9};
	
	for(int i=1; i<10; i++)
	{
		j = i;
		while(array[j-1] > array[j]) {
			temp = array[j-1];
			array[j-1] = array[j];
			array[j] = temp;
			j--;
		}
	}
	
	for(int i=0; i<10; i++)
	{
		printf("%d ",array[i]);
	} 
	
	return 0;	
} 
