#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int main()
{
	int a = 350, b;
	char c;
	c = a; b = c;
	printf("%d\t%d\t%x\t%x", a, c, b, b);
	// 305     94      5e      5e

	return 0;
}

//void reverse(int* arr, int sz)
//{
//	int* left = arr;
//	int* right = arr + sz - 1;
//	while (left < right)
//	{
//		int tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//void reverse1(int arr[], int sz)
//{
//
//}
//
//void print(int* arr, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	reverse(arr, sz);
//
//	print(arr, sz);
//
//	return 0;
//}
