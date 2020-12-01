#include<stdio.h>
#include<string.h>
#include<Windows.h>
#pragma warning (disable:4996)

	////qsort的练习
	//#include <stdlib.h>
	//void print(int *i, int n)
	//{
	//	for (int a = 0; a < n; a++)
	//	{
	//		printf("%d  ", *(i + a));
	//	}
	//	printf("\n");
	//}
	//int comint(const void * x,const  void * y)
	//{
	//	int *a = (int *)x;
	//	int *b = (int *)y;
	//	return (*a) - (*b);
	//}
	//int main()
	//{
	//	int arr[] = { 44, 56, 34, 23, 27, 48, 69 };
	//	int num = sizeof(arr) / sizeof(arr[0]);
	//	print(arr, num);
	//	qsort(arr, num, sizeof(arr[0]), comint);
	//	print(arr, num);
	//	system("pause");
	//	return 0;
	//}



	//二维数组用qsort，重要在于比较comstr这个自定义函数中，明白强转的意义，strcmp识别的是要比较的元素（每一个字符串）的起始地址；
	
//
//int comstr(const void* xp, const void* yp)
//{
//	char *s1 = (char *)xp;
//	char *s2 = (char *)yp;
//	
//	return strcmp(s1, s2);
//}
//int main()
//{
//	char arr[][4] = { "abcd", "acdr", "4", "bcdf" };
//	int num = sizeof(arr) / sizeof(arr[0]);
//	int s = sizeof(arr[0]);
//	qsort(arr[0], num, sizeof(arr[0]), comstr);
//	//print(arr, num);
//	
//system("pause");
//return 0;
//}




#include <assert.h>
int cmpint(const void * xp,const void* yp)
{
	int *src = (int *)xp;
	int *dst = (int *)yp;
	if (*src > *dst){
		return 1;
	}
	else if (*src < *dst){
		return -1;
	}
	else{
		return 0;
	}
}
void swap( char *src, char *dst, int s)
{
	for (int i = 0; i < s; i++)
	{
		char temp = *src;
		*src = *dst;
		*dst = temp;
		src++;
		dst++;
	}
}
void my_qsort(void *arr, int num, int sz, int(*compar)(const void *,const void *))
{
	assert(arr != NULL);
	assert(compar != NULL);
	char *e = (char *)arr;
	for (int i = 0; i < num - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < num - 1 - i; j++)
		{
			if (compar(e + j*sz,e + (j+1)*sz)>0)
			{
				flag = 1;
				swap(e + j*sz, e + (j + 1)*sz, sz);
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
int main()
{
	int arr[] = { 23,12,13,99,4,54,45,36,78 };
	int num = sizeof(arr) / sizeof(arr[0]);
	my_qsort(arr, num, sizeof(int), cmpint);
	system("pause");
	return 0;
}

//#include<stdlib.h>
//int ComInt(const void*_src, const void*_dst)
//{
//	int* src = (int*)_src;
//	int* dst = (int*)_dst;
//	
//	if (*src > *dst)
//	{
//		return 1;
//	}
//	else if (*src < *dst)
//	{
//		return -1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int ComChar(const void*_src, const void*_dst)
//{
//	
//	char *src = (char*)_src;
//	char *dst = (char*)_dst;
//	if (*src > *dst)
//	{
//		return 1;
//	}
//	else if (*src < *dst)
//	{
//		return -1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int arr[] = { 23, 12, 13, 99,  300, 4, 54, 45, 36, 78 };
//	char brr[] = { 23, 33, 5, 12, 'x', 'X' };
//	int num = sizeof(arr) / sizeof(arr[0]);
//	int num2 = sizeof(brr) / sizeof(brr[0]);
//	qsort(arr, num, sizeof(int), ComInt);
//	qsort(brr, num2, sizeof(char), ComChar);
//	system("pause");
//	return 0;
//}


//int main()
//{
//	int arr[7] = { 12, 23, 11, 1, 44, 25, 99 };
//	int num = sizeof(arr) / sizeof(arr[0]);
//
//	for (int i = 0; i < num - 1; i++)
//	{
//		for (int j = 0; j < num - 1 - i; j++)
//		{
//			if (arr[j] < arr[j + 1]){
//				int t = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = t;
//			}
//		}
//	}
//	for (int i = 0; i < num; i++)
//	{
//		printf("%d  ", arr[i]);
//	}
//	system("pause");
//	return 0;
//}


																		//旋转字符串查找（没有重复字符的）
//int IsRot(char *arr, char* brr, int len1, int len2)
//{
//	if (len1 != len2)
//	{
//		return 0;
//	}
//	
//	char t[2] = { brr[0] };
//	char *q = brr;
//	char *p = strstr(arr, t);
//	for (int i = 0; i < len1; i++)
//	{
//		if (*p == '\0')
//		{
//			p  = arr;
//		}
//		if (*p != *q)
//		{
//			return 0;
//		}
//		if (*q == '\0')
//		{
//			return 1;
//		}
//		p ++;
//		q ++;
//		
//	}
//	return 1;
//}
//int main()
//{
//	char arr[] = "AABBCD";
//	char brr[] = "BCDAAB";
//	int len1 = strlen(arr);
//	int len2 = strlen(brr);
//	int ret = IsRot(arr, brr, len1, len2);
//	if (ret)
//		printf("yes\n");
//	else
//		printf("no\n");
//	system("pause");
//	return 0;
//}
//char* my_strcpy(char *_src, char * dst)
//{
//	char *src = _src;
//	while (*src++ = *dst++)
//		;
//	return _src;
//}
//char* my_strcpy(char *_src, char * dst)
//{
//	char *src = _src;
//	*src = *dst;
//	while (*src)
//	{
//		src++;
//		dst++;
//		*src = *dst;
//		
//		
//	}
//	return _src;
//}
//int main()
//{
//	char arr[20];
//	char brr[] = "abcd";
//	char* p = my_strcpy(arr, brr);
//	printf("%s", p);
//	system("pause");
//	return 0;
//



//int mystrlen(char * arr)
//{
//	int num = 0;
//	while (*arr != '\0')
//	{
//		num++;
//		arr++;
//	}
//	return num;
//}
//int main()
//{
//	char arr[] = "abcd";
//	
//	int s = mystrlen(arr );
//	printf("%d", s);
//	system("pause");
//	return 0;
//}



//
//void Adj(int *p,int num)
//{
//	int left = 0;
//	int right = num -1;
//	for (int i = 0; i < num - 1; i++)
//	{
//		for (; left < num - 1; left++)
//		{
//		
//			if ((*(p + left) % 2) == 0)
//			{
//				
//				break;
//			}		
//		}
//		for (; right >=0;right--)
//		{
//			if ((*(p + right) % 2) == 1)
//			{
//				
//				break;
//			}
//		}
//		if (left < right)
//		{
//			int tmp = *(p + left);
//			*(p + left) = *(p + right);
//			*(p + right) = tmp;
//		}
//
//	}
//
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11 };
//	int num = sizeof(arr) / sizeof(arr[0]);
//	Adj(arr,num);
//	for (int i = 0; i < num ; i++)
//	{
//		printf("%d  ", arr[i]);
//	}
//	system("pause");
//	return 0;
//}

//int IsRot(char *arr, char * brr, int len1, int len2)
//{
//	if (len1 != len2)
//		return 0;
//	char src[500] = { 0 };
//	strcpy(src, arr);
//	strcat(src, arr);
//	if (NULL != strstr(src, brr))
//		return 1;
//	else
//		return 0;
//}

//int main()
//{
//	char arr[] = "abc";
//	int len = strlen(arr);
//	int i = 0;
//	scanf("%d", &i);
//	if (i > len)
//	i = i % len;
//	char xp[20] = { 0 };
//	strcpy(xp, arr);
//	strcat(xp, arr);
//	char *p = xp + i;
//	*(xp + i +len) = '\0';
//	printf("%s", p);
//	system("pause");
//	return 0;
//}/*
//int main()
//{
//	char arr[] = "abc";
//	char *p = arr + 1;
//	*(arr + 2) = '\0';
//	printf("%s", p);
//	system("pause");
//	return 0;
//}*/

//found(int arr[][4], int x, int y, int goal)
//{
//	int i = 0;
//	int j = y - 1;
//	while (i < x&& j > 0)
//	{
//		if (arr[i][j] < goal) //比我大就向下
//		{
//			i++;
//		}
//		else if (arr[i][j] > goal) //比我小就向左
//		{
//			j--;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//	return 0;
//	}
//
//int main()
//{
//	int arr[3][4] = { { 1,3,5,7}, { 3, 5, 7, 9 }, { 5, 7, 9, 11 } };
//	int a = 0;
//	scanf("%d", &a);
//	found(arr, 3, 4, a);
//	system("pause");
//	return 0;
//}
//char* my_strcat(char* src, char* dst)
//{
//	char* p = src;
//	while (*p !='\0')
//	{
//		p++;
//	}
//	*p = *dst;
//	while ((*p++ = *dst++) != '\0')
//		;
//	return src;
//}
//int my_strcmp(char* src, char* dst)
//{
//	int ret = 0;
//	while (1)
//	{
//		//ret = (unsigned)(*src) - (unsigned)(*dst);	
//		ret = *(unsigned char*)src - *(unsigned char*)dst;
//		if (*src == '\0' || *dst == '\0')
//			break;
//		if (ret)
//			break;
//		src++;
//		dst++;
//	}
//	return ret;
//}
//int main()
//{
//	char arr[] = "ABCD";
//	char brr[] = "ABC";
//
//	int res = my_strcmp(arr, brr);
//	if (res > 0)
//		printf("arr is big!\n");
//	else if (res == 0)
//		printf("equal\n");
//	else
//	printf("brr is big\n");
//	system("pause");
//	return 0;
//}
//char* my_strcpy(char* p, char* dst)
//{
//	char* src = p;
//	while (*src++ = *dst++)
//		;
//	return p;
//}
//#include <assert.h>
//void * my_memcpy(void* src, void* dst, int num)
//{
//	assert(src != NULL);
//	assert(dst != NULL);
//	char* x = (char*)src;
//	char* y = (char*)dst;
//	
//	
//
//		for (int i = 0; i < num; i++)
//		{
//			*x = *y;
//			x++;
//			y++;
//		}
//	
//	return src;
//}
//int main()
//{
//	int brr[4];
//	int arr[] = { 1, 2, 3, 4 };
//	int num = sizeof(arr);
//	my_memcpy(brr,arr,num);
//	for (int i = 0; i < 4; i++)
//	{
//		printf("%d  ", brr[i]);
//	}
//	system("pause");
//	return 0;
////}
//char * my_strstr(char* src, char* dst)
//{
//	int len1 = strlen(src);
//	int len2 = strlen(dst);
//	char*q = dst;
//	for (int i = 0; i < len1; i++)
//	{
//		if (*src == *dst)
//		{
//			char * p = src;
//			while (*p == *dst)
//			{
//				if (*(dst+1) == '\0')
//				{
//
//					return src;
//				}
//				++p;
//				++dst;
//			}
//			dst = q;
//		}
//		src++;
//	}
//	return NULL;
//}
//int main()
//{
//	char arr[] = "ABBCE";
//	char brr[] = "BC";
//	char* t = my_strstr(arr, brr);
//	printf("%s", t);
//	system("pause");
//	return 0;
////}
//int main()
//{
//	unsigned char puc[4];
//	struct tagPIM
//	{
//		unsigned char ucPim1;
//		unsigned char ucData0 : 1;
//		unsigned char ucData1 : 2;
//		unsigned char ucData2 : 3;
//	}*pstPimData;
//	pstPimData = (struct tagPIM*)puc;
//	memset(puc, 0, 4);
//	pstPimData->ucPim1 = 2;
//	pstPimData->ucData0 = 3;
//	pstPimData->ucData1 = 4;
//	pstPimData->ucData2 = 5;
//	printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
//	return 0;
//}
 /*struct n
{
	
	 struct n * ps;
	int a;
}s1;
int *ps;
int main()
{
	s1.a = 2;
	s1.ps = NULL;*/
	/*student* p = NULL;
	system("pause");
	return 0;
	student a = { NULL, 10 };
	student b = { NULL, 20 };*/
////模拟实现strncat
//#define num 3
//
//char* _strncat(char*src, char*dst,int a)
//{
//	char*xp = src;
//	while (*dst != '\0')
//	{
//		while ('\0' != *src)
//		{
//			src++;
//		}
//		for (int i = 0; i < a; i++)
//		{
//			*src = *dst;
//			src++;
//			dst++;
//		}
//	}
//	return xp;
//}
//int main()
//{
//	char arr[40] = "abcd";
//	char *brr = "efgh";
//	_strncat(arr, brr, num);
//	return 0;
//}
//#define num 5
//char* my_strncpy(char* src, char* dst, int a)
//{
//	char* xp = src;
//	for (int i = 0; i < a; i++)
//	{
//		*src = *dst;
//		src++;
//		dst++;
//	}
//	return xp;
//}
//int main()
//{
//	char arr[20];
//	char *brr = "abcdefg";
//	my_strncpy(arr, brr, num);
//	return 0;
//}


//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。编写一个函数找出这两个只出现一次的数字。
//
//int* LookFor(int* arr, int num)
//{
//	for (int i = 0; i < num - 1; i++)
//	{
//		int j = i + 1;
//		int p = 1;
//		while (p)
//		{
//			
//			if (*(arr + i) == *(arr + j))
//			{
//				p = 0;
//				break;
//			}
//			if (j == num - 1)
//			{
//				return arr + i;
//
//			}
//			j++;
//		}
//	}
//	return NULL;
//
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 5, 4, 3, 2, 1 };
//	int num = sizeof(arr) / sizeof(arr[0]);
//	int brr[2] = *(LookFor(arr, num));
//	return 0;
//}