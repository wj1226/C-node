#define _CRT_SECURE_NO_WARNINGS 1

// 1、模拟实现memmove
#include <stdio.h>
#include <assert.h>

void* my_memmove(void* dest, const void* src, size_t count)
{
	void* ret = dest;
	assert(dest && src);

	if (dest < src)
	{
		// 前->后
		while (count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		// 后->前
		while (count--)
		{
			*((char*)dest + count) = *((char*)src + count);
		}
	}

	return ret;
}

void print_arr(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	my_memmove(arr+2, arr, 16);
	//my_memmove(arr, arr+2, 16);

	int sz = sizeof(arr) / sizeof(arr[0]);
	print_arr(arr, sz);

	return 0;
}


// 2、memcmp - 比较内存里的数据
#include <stdio.h>

int main()
{
	int arr1[] = { 1,2,3,3,5 }; // 01 00 00 00 02 00 00 00 03 00 00 00 03 00 00 00 05 00 00 00
	int arr2[] = { 1,2,3,5,7 }; // 01 00 00 00 02 00 00 00 03 00 00 00 05 00 00 00 07 00 00 00

	int ret = memcmp(arr1, arr2, 13); // 返回小于0的数字

	return 0;
}


// 3、memset - memory set 内存设置
// 把每个字节初始化成1
#include <stdio.h>

int main()
{
	int arr[] = { 1,2,3,4,5,6,7 };

	memset(arr, 1, 24);

	return 0;
}


// 4、strerror - 返回错误码对应的错误信息

#include <stdio.h>
#include <string.h>

int main()
{
	printf("%s\n", strerror(0)); // No error
	printf("%s\n", strerror(1)); // Operation not permitted
	printf("%s\n", strerror(2)); // No such file or directory
	printf("%s\n", strerror(3)); // No such process

	return 0;
}


// C语言库函数调用失败的时候，会把错误码，存储到error变量中

// fopen - 打开文件
// 打开文件 以r（读）的方式 返回FILE*的指针变量
// 打开成功，放地址；打开失败，放NULL
int main()
{
	FILE* pf = fopen("test.txt", "r");

	// strerror - 可以返回C语言内置的错误码对应的错误信息

	if (pf == NULL)
	{
		printf("%s\n", strerror(errno)); // No such file or directory
	}
	else
	{
		printf("打开文件成功\n");
	}

	return 0;
}


// strerror - 把错误码转化成错误信息，需要自己打印
// perror - 可以直接打印 
int main()
{
	FILE* pf = fopen("test.txt", "r");

	if (pf == NULL)
	{
		perror("测试："); // 测试：: No such file or directory
	}
	else
	{
		printf("打开文件成功\n");
	}

	return 0;
}



// 二、自定义类型：结构体，枚举，联合
// C语言内置类型：char short int long float double
// 自定义类型/构造类型：结构体，枚举，联合

// 结构体
// 1、特殊的声明
// 在声明结构体的时候，可以不完全地声明

// 匿名结构体
struct
{
	int a;
	char c;
	double d;
}s1, s2; // correct

int main()
{
	struct s3; // err
	return 0;
}

// 匿名结构体类型
struct
{
	int a;
	char c;
	double d;
}s1, s2;

struct
{
	int a;
	char c;
	double d;
}*ps;

int main()
{
	ps = &s1; // “=”: 从“*”到“*”的类型不兼容
	// 编译器会把上面两个声明当成完全不同的两个类型， 是非法的

	return 0;
}


// 2、结构体自引用

// 数据结构：描述了数据在内存中存储的结构
// 线性数据结构：顺序表，链表

// 同类型节点找到同类型节点
// 错误写法：
struct Node
{
	int date;
	struct Node n; // 无线递归 err
};

// 正确写法：存地址
struct Node
{
	int date; // 数据域
	struct Node* next; // 指针域
};


// 以下代码错在哪里，如何改正
typedef struct
{
	int date;
	Node* next;
	
}Node;
// 对匿名结构体重命名，而在使用时还没有产生

// 解决方案
typedef struct Node
{
	int date;
	struct Node* next;

}Node;


// 3、结构体变量的定义和初始化
// 创建并初始化
struct Point
{
	int x;
	int y;
}p1 = { 5,6 }, p2; // 全局

struct Point p2 = { 1,2 }; // 全局

int main()
{
	struct Point p1 = { 3,4 }; // 局部
	// 程序运行到此创建
	// 全局变量在程序运行前就创建了

	return 0;
}

// 结构体嵌套初始化
struct Point
{
	int x;
	int y;
}p1 = { 5,6 }, p2;

struct Point p2 = { 1,2 };

struct S
{
	double d;
	struct Point p;
	char name[20];
};

int main()
{
	struct Point p1 = { 3,4 };

	struct S s = { 3.14, {1, 5}, {"zhangsan"}};

	return 0;
}


// 打印结构体
#include <stdio.h>

struct Point
{
	int x;
	int y;
}p1 = { 5,6 }, p2;

struct Point p2 = { 1,2 };

struct S
{
	double d;
	struct Point p;
	char name[20];
	int date[20];
};

int main()
{
	struct Point p1 = { 3,4 };

	struct S s = { 3.14, {1, 5}, {"zhangsan"}, {1,2,3} };

	printf("%lf\n", s.d); // 3.140000
	printf("%d %d\n", s.p.x, s.p.y); // 1 5
	printf("%s\n", s.name); // zhangsan
	int i = 0;
	for (i = 0; i < 20; i++)
	{
		printf("%d ", s.date[i]); // 1 2 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
	}

	return 0;
}


// 4、结构体内存对齐
// 为什么S1和S2类型的成员一模一样，但是S1和S2所占空间的大小有了一些区别？
#include <stdio.h>

struct S1
{
	char c1;
	int a;
	char c2;
};

struct S2
{
	char c1;
	char c2;
	int a;
};

int main()
{
	struct S1 s = { 'x', 100, 'y' };

	printf("%d\n", sizeof(struct S1)); // 12
	printf("%d\n", sizeof(struct S2)); // 8
	printf("%d\n", sizeof(s)); // 12

	return 0;
}

// 内存对齐

// 结构体内存对齐规则：
// 1. 结构体的第一个成员永远放在结构体起始位置偏移为0的位置
// 2. 结构体成员从第二个成员开始，总是放在偏移为一个==对起数==的整数倍处
//		对齐数 = 编译器默认的对齐数和变量自身大小的较小值
//		Linux - 没有默认对齐数（自身大小就是对齐数）
//		VS - 默认对齐数是8
// 3. 结构体的总大小必须是各个成员的对齐数中最大那个对齐数的整数倍

// 练习：
struct S3
{
	double d;
	char c;
	int i;
};
// 16

// 结构体嵌套如何求
#include <stdio.h>

struct S3
{
	double d;
	char c;
	int i;
};

struct S4
{
	char c1;
	struct S3 s3;
	double d;
};

int main()
{
	printf("%d\n", sizeof(struct S4));

	return 0;
}
// 规则4、如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，
// 结构体的整体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍。


// 为什么存在内存对齐?
/* 1. 平台原因(移植原因)： 不是所有的硬件平台都能访问任意地址上的任意数据的；某些硬件平台只能在某些地址
处取某些特定类型的数据，否则抛出硬件异常。
2. 性能原因： 数据结构(尤其是栈)应该尽可能地在自然边界上对齐。 原因在于，为了访问未对齐的内存，处理器
需要作两次内存访问；而对齐的内存访问仅需要一次访问 */

// 总体来说 
// 结构体的内存对齐是拿空间来换取时间的做法。

// 在设计结构体的时候，我们既要满足对齐，又要节省空间，如何做到：
// 让占用空间小的成员尽量集中在一起。
