#include<stdio.h>
#include<string.h>
#include<Windows.h>
#pragma warning (disable:4996)

//qsortµÄÁ·Ï°
#include <stdlib.h>
void print(int *i, int n)
{
	for (int a = 0; a < n; a++)
	{
		printf("%d  ", *(i + a));
	}
	printf("\n");
}
int comint(const void * x, const  void * y)
{
	int *a = (int *)x;
	int *b = (int *)y;
	return (*a) - (*b);
}
int main()
{
	int arr[] = { 44, 56, 34, 23, 27, 48, 69 };
	int num = sizeof(arr) / sizeof(arr[0]);
	print(arr, num);
	qsort(arr, num, sizeof(arr[0]), comint);
	print(arr, num);
	system("pause");
	return 0;
}