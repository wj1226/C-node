#define _CRT_SECURE_NO_WARNINGS 1

// 动态内存分配

// 为什么存在动态内存分配
/* 1. 空间开辟大小是固定的
2. 数组在声明的时候，必须指定数组的长度，它所需要的内存在编译时分配 */

// 1. 堆区
// 2. malloc calloc realloc free

// malloc
// void* malloc(size_t t);
// 在堆区上申请size_t大小的空间 返回这块空间的起始位置

// 1、malloc、free
/* 这个函数向内存申请一块连续可用的空间，并返回指向这块空间的指针。
1. 如果开辟成功，则返回一个指向开辟好空间的指针。
2. 如果开辟失败，则返回一个NULL指针，因此malloc的返回值一定要做检查。
3. 返回值的类型是 void* ，所以malloc函数并不知道开辟空间的类型，具体在使用的时候使用者自己来决定。
4. 如果参数 size 为0，malloc的行为是标准是未定义的，取决于编译器。 */
/*  free函数用来释放动态开辟的内存。
1. 如果参数 ptr 指向的空间不是动态开辟的，那free函数的行为是未定义的。
2. 如果参数 ptr 是NULL指针，则函数什么事都不做。 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	// 1. 开辟空间
	int* p = (int*)malloc(40); // 申请40大小空间 把起始地址强转为int* 赋给p

	if (p == NULL)
	{
		return -1;
	}
	// 开辟成功了 可以使用
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*(p + i) = i;
	}

	// 2. 释放空间
	free(p);
	p = NULL; // 

	return 0;
}


// 2、calloc
// void* calloc (size_t num, size_t size);
// 与malloc有何区别
/* malloc函数只负责在堆区申请空间，并且返回起始地址，不初始化空间
calloc函数在堆区上申请空间，并且在返回起始地址之前把申请的每个字节初始化为0 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int* p = (int*)calloc(10, sizeof(int));
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
		return -1;
	}
	// 申请成功
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));
	}

	// 释放空间
	free(p);
	p = NULL;

	return 0;
}


// 3、realloc
// 让动态内存管理更加灵活
// void* realloc (void* ptr, size_t size);
/* ptr 是要调整的内存地址
size 调整之后新大小
返回值为调整之后的内存起始位置。
这个函数调整原内存空间大小的基础上，还会将原来内存中的数据移动到 新 的空间 */
// 两种情况：
// 1. 后面空间大小够用，直接在后面开辟
// 2. 空间不够，在堆空间上另找一个合适大小的连续空间来使用，这样函数返回的是一个新的内存地址
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int* p = (int*)calloc(10, sizeof(int));
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
		return -1;
	}
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*(p + i) = i;
	}

	// 空间不够大，增加空间至20int
	int* ptr = (int*)realloc(p, 20 * sizeof(int));
	if (ptr != NULL)
	{
		p = ptr;
	}
	else
	{
		return -1;
	}
	// 增加成功，使用
	for (i = 10; i < 20; i++)
	{
		*(p + i) = i;
	}
	for (i = 0; i < 20; i++)
	{
		printf("%d ", *(p + i));
	}

	free(p);
	p = NULL;

	return 0;
}


// 4、常见错误
// 1. 对malloc返回值判断
//int* p = (int*)malloc(20);
//*p = 0; // 有风险
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* p = (int*)malloc(20);

	if (p == NULL)
	{
		return -1;
	}
	*p = 0;

	return 0;
}

// 2. 对动态内存空间的越界访问
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* p = (int*)malloc(200);

	if (p == NULL)
	{
		return -1;
	}

	int i = 0;
	for (i = 0; i < 80; i++)
	{
		*(p + i) = 1;
	}

	for (i = 0; i < 80; i++)
	{
		printf("%d ", *(p + i));
	}

	free(p);
	p = NULL;

	return 0;
}

// 3、释放非动态内存空间
int main()
{
	int a = 10;
	int* p = &a;

	free(p); // err
	p = NULL;

	return 0;
}

// 4、使用free释放一块动态开辟内存的一部分
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* p = (int*)malloc(10 * sizeof(int));
	if (p == NULL)
	{
		return -1;
	}

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*p++ = 1;
	}

	free(p);
	p = NULL;

	return 0;
}
// 改变了p 不再指向起始位置 此时释放的不在 起始位置

// 5、对同一块动态内存多次释放
int main()
{
	int* p = (int*)malloc(40);
	if (p == NULL)
	{
		return -1;
	}

	free(p);
	free(p); // err
}

int main()
{
	int* p = (int*)malloc(40);
	if (p == NULL)
	{
		return -1;
	}

	free(p);
	p = NULL;

	free(p); // ok
}

// 6、动态开辟内存忘记释放（内存泄漏）

// 在堆区上申请空间，有2种回收方式，
// 1. free
// 2. 程序退出时，申请的空间回收
int main()
{
	int* p = (int*)malloc(40);
	if (p == NULL)
	{
		return -1;
	}
	// 没有释放

	return 0;
}


// 5、经典的笔试题
