#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	
	int n;
	scanf("%d", &n);
	int arr[1000];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		
	}


	for (int i = n-1; i >= 0 ; i--)
	{
		for (int j = 0; j < i; j++)
		{
			int temp;
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}
	
	return 0;
}
