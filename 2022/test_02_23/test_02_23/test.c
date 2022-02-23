#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void move_Parity(int* arr, int sz)
{
	int left = 0;
	int right = sz - 1;

	while (left < right)
	{
		//从前向后找到一个偶数
		while ((left < right) && arr[left] % 2 == 1)
		{
			left++;
		}
		//从后向前找到一个奇数
		while ((left < right) && arr[right] % 2 == 0)
		{
			right--;
		}
		//交换
		if (left < right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
}

void Print(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	//全是偶数 全是奇数
	//奇偶交替
	int arr[] = { 1,23,3,47,5,6,7,8,92,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	move_Parity(arr, sz);

	Print(arr, sz);

	return 0;
}
