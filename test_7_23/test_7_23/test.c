#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// 函数
// 一个大型程序中的某部分代码 由一个或多个语句块组成 负责完成某项特定任务 具有独立性
// 一般会有输入参数和返回值 提供对过程的分装和细节的隐藏

// C语言中函数的分类:库函数 自定义函数
// 
// 如何学会使用库函数
// http://www.cplusplus.com/reference/
//
// strcpy
#include <string.h>

int main()
{
	char arr1[20] = { 0 }; // 目标空间
	char arr2[] = "hello";

	strcpy(arr1, arr2);

	printf("%s\n", arr1);

	return 0;
}


int main()
{
	char arr1[20] = "xxxxxxxxx"; // 目标空间
	char arr2[] = "hello";

	char* ret = strcpy(arr1, arr2);

	printf("%s\n", arr1); // hello 
	printf("%s\n", ret); // hello
	// \0 字符串的结束标志

	return 0;
}



// memset
int main()
{
	char arr[] = "hello bit";
	char* ret = (char*)memset(arr, 'x', 5);

	printf("%s\n", ret); // xxxxx bit

	return 0;
}


int main()
{
	int arr[10] = { 0 };
	//memset( arr,1,5 * sizeof(int) ); // 把前5个整形 20个字节设计成1
	// memset以字节为单位初始化

	return 0;
}



// 自定义函数
// 与库函数一样 有函数名，返回值，函数参数
// 不一样的是这些都是我们自己来设计 有很大的发挥空间

// 函数的组成
//  ret_type fun_name(paral, *)
//  {
//  	statement; // 语句项
//  }
//  返回类型 函数名 函数参数

// 1.写一个函数可以找出两个整数的最大值
int get_max(int x, int y) // 形式参数
{
	return (x > y ? x : y);
}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);

	int max = get_max(a, b); // 实际参数
	printf("max = %d\n", max);

	return 0;
}


// 写一个函数可以交换两个整形变量的内容
// 无函数
int main()
{
	int a = 10;
	int b = 20;
	int c = 0;

	printf("交换前：a=%d b=%d\n", a, b);
	c = a;
	a = b;
	b = c;
	printf("交换后：a=%d b=%d\n", a, b);

	return 0;
}


// 函数
// err
void Swap(int x, int y)
{
	int z = 0;
	z = x;
	x = y;
	y = z;
}

int main()
{
	int a = 10;
	int b = 20;
	int c = 0;

	printf("交换前：a=%d b=%d\n", a, b);
	Swap(a, b);
	// 实参a和b 穿给形参x,y时，形参将是实参的一份临时拷贝
	// 改变实参变量x,y不会影响实参a,b
	printf("交换后：a=%d b=%d\n", a, b);

	return 0;
}


void Swap(int* px, int* py)
{
	int z = 0;

	z = *px;
	*px = *py;
	*py = z;
}

int main()
{
	int a = 10;
	int b = 20;
	int c = 0;

	printf("交换前：a=%d b=%d\n", a, b);
	// 函数
	Swap(&a, &b);

	printf("交换后：a=%d b=%d\n", a, b);

	return 0;
}




// 函数参数
//
// 实际参数 
// 实参可以是：常量 变量 表达式 函数
int get_max(int x, int y)
{
	return (x > y ? x : y);
}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);

	int max = get_max(a, get_max(3, 5));
	//int max = get_max(b, 20-1);

	printf("max = %d\n", max);

	return 0;
}


// 形式参数
// 只有在函数调用的过程中才会分配空间 调用完成后销毁 因此形式参数只在函数内有效




// 函数调用
// 传值调用 传址调用

void Swap1(int x, int y)
{
	int z = 0;
	z = x;
	x = y;
	y = z;
}

void Swap2(int* px, int* py)
{
	int z = 0;

	z = *px;
	*px = *py;
	*py = z;
}

int main()
{
	int a = 10;
	int b = 20;

	Swap1(a, b); // 传值调用
	// 形参是实参的一份临时拷贝，对形参的修改不会影响实参

	Swap2(&a, &b); // 传址调用
	// 把函数外部创建变量的内存地址传递给函数参数的一种调用函数的方式
	// 可以让函数和函数外的变量建立真正的联系，也就是函数内部可以直接操作函数外部的变量

	return 0;
}




// 练习

// 1. 写一个函数判断一个数是不是素数
#include <math.h>

int is_prime(int n)
{
	// 试除法
	// 2 ~ n-1
	// 2~sqrt(n)
	int j = 0;
	for (j = 2; j <= sqrt(n); j++)
	{
		if (n % j == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int i = 0;
	int cnt = 0;
	for (i = 100; i <= 200; i++)
	{
		if (is_prime(i) == 1)
		{
			printf("%d ", i);
			cnt++;
		}
	}
	printf("\ncnt = %d\n", cnt);

	return 0;
}


// 2. 写一个函数判断是不是闰年
int is_leap_year(int y)
{
	if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))
	{
		return 1;
	}
	else
		return 0;
}

int main()
{
	int y = 0;
	for (y = 1000; y <= 2000; y++)
	{
		if (is_leap_year(y) == 1)
		{
			printf("%d ", y);
		}
	}
}


// 3. 写一个函数 实现一个整数有序数组的二分查找
int binary_search(int arr[], int k, int sz)
{
	int left = 0;
	int right = sz - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (arr[mid] < k)
			left = mid + 1;
		else if (arr[mid] > k)
			right = mid - 1;
		else
			return mid;
	}

	// 找不到
	return -1; // 0有可能是下标
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int k = 7;
	int sz = sizeof(arr) / sizeof(arr[0]);

	int ret = binary_search(arr, k, sz); // TDD - 测试驱动开发

	if (ret == -1)
		printf("找不到\n");
	else
		printf("找到了，下标是：%d\n", ret);
	return 0;
}


// 限制范围 找3找不到
int binary_search(int arr[], int k, int left, int right)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (arr[mid] < k)
			left = mid + 1;
		else if (arr[mid] > k)
			right = mid - 1;
		else
			return mid;
	}

	return -1;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int k = 3;
	int sz = sizeof(arr) / sizeof(arr[0]);

	int ret = binary_search(arr, k, 5, 9);

	if (ret == -1)
		printf("找不到\n");
	else
		printf("找到了，下标是：%d\n", ret);
	return 0;
}


// 4. 写一个函数 每调用一次这个函数 就会将num的值增加一次
void Add(int* p)
{
	*p = *p + 1;
}

int main()
{
	int num = 0;

	Add(&num);
	printf("%d\n", num); // 1

	Add(&num);
	printf("%d\n", num); // 2

	Add(&num);
	printf("%d\n", num); // 3

	return 0;
}


int Add(int* n)
{
	return n + 1;
}

int main()
{
	int num = 0;

	num = Add(num);
	printf("%d\n", num); // 1

	num = Add(num);
	printf("%d\n", num); // 2

	num = Add(num);
	printf("%d\n", num); // 3

	return 0;
}




// 函数的嵌套调用和链式访问

// 函数可以嵌套调用，但不能嵌套定义
int main()
{
	// 函数嵌套定义 - err
	/*void test()
	{
		printf("hehe\n");
	}*/

	return 0;
}


// 链式访问：把一个函数的返回值作为另一个函数的参数
int main()
{
	int len = strlen("abc");

	printf("%d\n", len);

	printf("%d\n", strlen("abc")); // 链式访问

	return 0;
}


int main()
{
	char arr1[20] = "xxxxxxxxx";
	char arr2[] = "abc";

	// strcpy(arr1, arr2);

	printf("%s\n", strcpy(arr1, arr2));

	return 0;
}


// 打印什么
int main()
{
	printf("%d", printf("%d", printf("%d", 43)));
	// printf 函数返回的是打印在屏幕上的字符的个数
	// 如果发生错误 将返回负数
/*	printf("%d", printf("%d", 2)); // 43是2位数
	// 43
	printf("%d", 1);
	// 432
	// 4321
*/
	return 0;
}