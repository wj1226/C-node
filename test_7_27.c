// 数组
 
// 一、一维数组的创建和初始化
// 1. 数组的创建
// 数组是一组相同类型元素的集合

#include <stdio.h>

int main()
{
	int arr[20];

	return 0;
}

// 数组创建 []中要给一个常量才可以 不能使用变量


// 2. 数组初始化
int main()
{
	int arr1[20] = { 1, 2, 3 }; // 不完全初始化，剩余的默认初始化为0
	int arr2[] = { 1, 2, 3 }; // 没有指定大小 根据初始化内容确定

	char arr3[] = "abc"; // a b c \0  -- 4个字节
	char arr4[] = { 'a', 'b', 'c' }; // a b c
	char arr5[] = { 'a', 98, 'c' }; // a b c

	return 0;
}



// 不初始化
int arr[5]; // // 全局变量不初始化 默认放0

int main()
{
	int arr1[5];
	// 局部变量不初始化 放的是随机值

	return 0;
}



// 3. 一维数组的使用
// 对于数组的使用我们之前介绍了一个操作符： [] ，下标引用操作符。它其实就数组访问的操作符。

// 用下标打印1-10
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int i = 0; //做下标

	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}


// sizeof 计算数组的元素个数
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);

	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}

// 总结：
// 1. 数组是使用下标来访问的，下标是从0开始。
// 2. 数组的大小可以通过计算得到。


// float sc[5] = { 0.0f, 3.0f };
// 结构体数组业可以创建



// 4. 一维数组在内存中的存储
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);

	for (i = 0; i < sz; i++)
	{
		printf("%p\n", &arr[i]); // 连续递增4  一个int4个字节的地址 10个
		// 随着数组下标的增长，元素的地址，也在有规律的递增。 由此可以得出结论：数组在内存中是连续存放的
		// 数组随着下标的增长，地址是由低到高变化的
	}

	return 0;
}



// 整形指针加1是4个字节
int main()
{
	int a = 10;
	int* p = &a;

	printf("%p\n", p);
	printf("%p\n", p+1);

	return 0;
}