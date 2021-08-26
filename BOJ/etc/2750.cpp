// Selection Sort

#include <stdio.h>

int main() {
	
	int n, min, index, temp;
	scanf("%d", &n);
	int arr[1001];
		
	for(int i=0; i < n ; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	for(int i=0; i< n ; i++)
	{
		min = 1001;
		for(int j = i; j<n; j++)
		{
			if(arr[j] < min)
			{
				min = arr[j];
				index = j;
			}
		}
		temp = arr[i];
		arr[i] = min;
		arr[index] = temp;
	}
	
	for(int i=0; i < n ; i++)
	{
		printf("%d\n", arr[i]);
	}
	
	
	return 0;
}
