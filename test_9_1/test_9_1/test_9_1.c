#define _CRT_SECURE_NO_WARNINGS 1

// 回调函数
//int Add(int x, int y)
//{
//	return x + y;
//}
//void Calc(int (*pf)(int, int))
//{
//	int ret = pf(3, 5);
//	printf("%d\n", ret);
//}
//int main()
//{
//	Calc(Add);
//
//	return 0;
//}
/* 回调函数就是一个通过函数指针调用的函数。如果你把函数的指针（地址）作为参数传递给另一
个函数，当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。回调函数不是由该
函数的实现方直接调用，而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或
条件进行响应。 */




void qsort(void* base, 
			size_t num, // 待排序的元素个数
			size_t width, // 一个元素的大小，单位是字节
			int(* cmp)(const void* e1, const void* e2) 
			// cmp指向的是：排序时，用来比较2个元素的函数
);

// void* - 无具体类型的指针
// 能够接收任意类型的地址
// 缺点：不能进行运算，不能+-整数，不能解引用


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//排序整型和结构体
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

void print_arr(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

void test1()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	qsort(arr, sz, sizeof(arr[0]), cmp_int);

	print_arr(arr, sz);
}


struct Stu
{
	char name[20];
	int age;
};

int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}

int cmp_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

void test2()
{
	struct Stu s[3] = { {"张三", 15}, {"李四", 30}, {"王五", 10} };
	int sz = sizeof(s) / sizeof(s[0]);

	// 按照名字排序
	//qsort(s, sz, sizeof(s[0]), cmp_by_name);

	// 按照年龄排序
	qsort(s, sz, sizeof(s[0]), cmp_by_age);
}

int main()
{
	// 测试排序整型
	//test1();

	// 测试排序结构体数据
	test2();

	return 0;
}




// 用冒泡函数模拟实现qsort，排序整型和结构体
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

void print_arr(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

void Swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++; //以字节交换
		buf2++;
	}
}

// 使用回调函数实现一个通用的冒泡排序函数
void BubbleSort(void* base, size_t num, size_t width, int (*cmp)(const void* e1, const void* e2))
{
	size_t i = 0;
	// 趟数
	for (i = 0; i < num - 1; i++)
	{
		size_t j = 0;
		for (j = 0; j < num - 1 - i; j++)
		{
			// 比较
			if (cmp((char*)base+j*width, (char*)base+(j+1)*width) > 0)
			{
				// 交换
				Swap((char*)base+j*width, (char*)base+(j+1)*width, width);
			}
		}
	}
}

// 测试自定义的BubbleSort();
void test3()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	
	BubbleSort(arr, sz, sizeof(arr[0]), cmp_int);

	print_arr(arr, sz);
}


// 测试自定义的BubbleSort() 排序结构体
struct Stu
{
	char name[20];
	int age;
};

int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}

void test4()
{
	struct Stu s[3] = { {"张三", 15}, {"李四", 30}, {"王五", 10} };
	int sz = sizeof(s) / sizeof(s[0]);

	// 按照名字排序
	qsort(s, sz, sizeof(s[0]), cmp_by_name);

	// 按照年龄排序
	//qsort(s, sz, sizeof(s[0]), cmp_by_age);
}

int main()
{
	//test3();

	test4();

	return 0;
}




// 指针和数组笔试题解析

// 一维数组
int main()
{
	int a[] = { 1,2,3,4 };

	printf("%d\n", sizeof(a)); // 数组名a单独放在sizeof内部，数组名表示整个数组，计算的是整个数组的大小
	printf("%d\n", sizeof(a + 0)); // a表示首元素的地址，a+0还是首元素的地址，地址的大小就是4/8字节
	printf("%d\n", sizeof(*a)); // a表示首元素的地址，*a就是首元素 --> a[0]，大小就是4
	// *a <==> *(a+0) <==> a[0]
	
	printf("%d\n", sizeof(a + 1)); // a表示首元素的地址，a+1是第二个元素的地址，大小就是4/8
	printf("%d\n", sizeof(a[1])); // a[1] 就是第二个元素，4
	printf("%d\n", sizeof(&a)); // &a - 数组的地址 - 4/8 - int(*)[4]

	printf("%d\n", sizeof(*&a)); // *&a - &a是数组的地址，对数组的地址解引用拿到的是的数组，所以大小是16
	// printf("%d\n", sizeof(&a)); // 16
	
	printf("%d\n", sizeof(&a + 1)); // &a是数组的地址，&a+1是数组的的地址+1，跳过整个数组，虽然跳过了数组，还是地址 4/8
	printf("%d\n", sizeof(&a[0])); // 首元素地址 4/8
	printf("%d\n", sizeof(&a[0] + 1)); // 第二个元素的地址 4/8

	return 0;
}
// 1. sizeof(数组名)，这里的数组名表示整个数组，计算的是整个数组的大小。（大小是字节）
// 2. & 数组名，这里的数组名表示整个数组，取出的是整个数组的地址。
// 3. 除此之外所有的数组名都表示首元素的地址。
