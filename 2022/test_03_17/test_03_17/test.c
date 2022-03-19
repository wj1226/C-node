#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	return 0;
}

//#include <Stdio.h>
//#include <string.h>
//
//// Êý×é
//void reverseString(char arr[])
//{
//	int l = 0;
//	int r = strlen(arr) - 1;
//	while (l < r)
//	{
//		char tmp = arr[l];
//		arr[l] = arr[r];
//		arr[r] = tmp;
//		l++;
//		r--;
//	}
//}
//
//// Ö¸Õë
//void reverseString1(char* arr)
//{
//	char* l = arr;
//	char* r = arr + strlen(arr) - 1;
//	while (l < r)
//	{
//		char tmp = *l;
//		*l = *r;
//		*r = tmp;
//		l++;
//		r--;
//	}
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	
//	//reverseString(arr);
//	
//	reverseString1(arr);
//	
//	printf("%s\n", arr);
//	return 0;
//}



//#include <stdio.h>
//
//void fun(int a[], int n, int flag)
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			if (flag)
//			{
//				if (a[i] < a[j])
//				{
//					int tmp = a[i];
//					a[i] = a[j];
//					a[j] = tmp;
//				}
//			}
//			else
//			{
//				if (a[i] > a[j])
//				{
//					int tmp = a[i];
//					a[i] = a[j];
//					a[j] = tmp;
//				}
//			}
//		}
//	}
//}
//
//int main()
//{
//	int c[10] = { 7,9,10,8,3,5,1,6,2,4 };
//	fun(c, 10, 1);
//	fun(c + 4, 6, 0);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", c[i]);
//	}
//	return 0;
//}


//void fun(int a[][4], int b[])
//{
//	for (int i = 0; i < 4; i++)
//	{
//		b[i] = a[i][i];
//	}
//}
//
//int main()
//{
//	int x[][4] = { {1,2,3}, {4}, {5,6,7,8}, {9,10} };
//	int y[4];
//	int i = 0;
//	fun(x, y);
//	for (int i = 0; i < 4; i++)
//	{
//		printf("%d ", y[i]);
//	}
//}
