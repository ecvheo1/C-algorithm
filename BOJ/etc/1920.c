// 이분 탐색 (이진 검색)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 < num2)
		return -1;
	else if (num1 > num2)
		return 1;
	else
		return 0;
}

int main(void)
{
	int n;
	int *x;
	scanf("%d", &n);
	x = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
	}

	qsort(x, n, sizeof(int), compare);

	/*
	for (int i = n-1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (x[j] > x[j + 1])
			{
				int temp;
				temp = x[j + 1];
				x[j + 1] = x[j];
				x[j] = temp;
			}
		}
	}
	*/

	int m;
	int* k;
	scanf("%d", &m);
	k = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &k[i]);
	}

	for (int i = 0; i < m; i++)
	{
		int start = 0;
		int end = n - 1;
		int c;
		int flag = 0;
		

		while(1)
		{
			c = (start + end) / 2;
			if (start > end)
				break;
			if (k[i] == x[c])
			{
				flag = 1;
				break;
			}
			else if (k[i] > x[c])
			{
				start = c + 1;
			}
			else
			{
				end = c - 1;
			}
		}
		printf("%d\n", flag);
	}

	free(x);
	free(k);

	return 0;
}
