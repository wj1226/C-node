#define _CRT_SECURE_NO_WARNINGS 1

// 经典笔试题

// 1、
#include <stdio.h>
#include <string.h>

void GetMemory(char* p)
{
	p = (char*)malloc(100);
}

void Test(void)
{
	char* str = NULL;
	GetMemory(str);

	strcpy(str, "hello world");
	printf(str);
}

int main()
{
	Test();
	return 0;
}
// 程序会崩溃
/* 1. str传给p的时候，是值传递，p是str的临时拷贝，所以当malloc开辟的空间起始地址放在p中时，不会影响str，str仍是NULL
2. 当str是NULL，strcpy想把hello world拷贝到str指向的空间时，程序就会崩溃，因为NULL指针指向的空间时不能直接访问的
3. 存在内存泄漏，出函数销毁，无法回收空间 */

// 修改：
// 版本1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void GetMemory(char** p)
{
	*p = (char*)malloc(100);
}

void Test(void)
{
	char* str = NULL;
	GetMemory(&str); // char**

	strcpy(str, "hello world");
	printf(str);
	// 释放
	free(str);
	str = NULL;
}

int main()
{
	Test();
	return 0;
}

// 版本2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* GetMemory(char* p)
{
	p = (char*)malloc(100);

	return p;
}

void Test(void)
{
	char* str = NULL;

	str = GetMemory(str);

	strcpy(str, "hello world");

	printf(str);

	free(str);
	str = NULL;
}

int main()
{
	Test();
	return 0;
}


// 2、
#include <stdio.h>

char* GetMemory(void)
{
	char p[] = "hello world";

	return p;
}

void Test(void)
{
	char* str = NULL;

	str = GetMemory();

	printf(str);
}

int main()
{
	Test();
	return 0;
}
// 程序运行打印随机值
// 返回栈空间地址问题
#include <stdio.h>

int* test()
{
	int n = 10;

	return &n;
}

int main()
{
	int* p = test();

	printf("%d\n", *p);
	// 如果没有被覆盖,有可能输出10

	return 0;
}


// 3、
#include <stdio.h>

void GetMemory(char** p, int num)
{
	*p = (char*)malloc(num);
}

void Test(void)
{
	char* str = NULL;
	GetMemory(&str, 100);

	strcpy(str, "hello");
	printf(str);

}

int main()
{
	Test();
	return 0;
}
//内存泄漏，没有free
//free(str);
//str = NULL;

// 改正：
#include <stdio.h>
#include <stdlib.h>

void GetMemory(char** p, int num)
{
	*p = (char*)malloc(num);
}

void Test(void)
{
	char* str = NULL;
	GetMemory(&str, 100);

	strcpy(str, "hello");
	printf(str);

	free(str);
	str = NULL;
}

int main()
{
	Test();
	return 0;
}


// 4、
#include <stdio.h>
#include <stdlib.h>

void Test(void)
{
	char* str = (char*)malloc(100);

	strcpy(str, "hello");
	free(str);

	if (str != NULL)
	{
		strcpy(str, "world");
		printf(str);
	}
}

int main()
{
	Test();
	return 0;
}
// 输出world，但程序有错误
// free后没有置空

// 改正：
#include <stdio.h>
#include <stdlib.h>

void Test(void)
{
	char* str = (char*)malloc(100);

	strcpy(str, "hello");
	free(str);
	str = NULL;

	if (str != NULL)
	{
		strcpy(str, "world");
		printf(str);
	}
}

int main()
{
	Test();
	return 0;
}


// C/C++程序的内存开辟


// 柔性数组
// C99 中，结构中的最后一个元素允许是未知大小的数组，这就叫做『柔性数组』成员。

// 数组大小不确定，可大可小
typedef struct st_type
{
	int i;
	int a[0];//柔性数组成员
}type_a;
// 有些编译器会报错无法编译可以改成：
typedef struct st_type
{
	int i;
	int a[];//柔性数组成员
}type_a;


//柔性数组的特点：
/* 结构中的柔性数组成员前面必须至少一个其他成员
sizeof 返回的这种结构大小不包括柔性数组的内存
包含柔性数组成员的结构体的使用，要配合malloc这种动态内存分配函数使用*/

#include <stdio.h>

typedef struct st_type
{
	int i;
	int a[];//柔性数组成员
}type_a;

int main()
{
	printf("%d\n", sizeof(struct st_type)); // 4
	return 0;
}


// 
struct st_type
{
	int i;
	int a[];
};

int main()
{
	malloc(sizeof(struct st_type) + 10 * sizeof(int));

	return 0;
}


// 使用
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

struct st_type
{
	int i;
	int a[];
};

int main()
{
	struct st_type* ps = (struct st_type*)malloc(sizeof(struct st_type) + 10 * sizeof(int));
	// 4byte - i
	// 40byte - a

	if (ps == NULL)
	{
		printf("%s\n", strerror(errno));
		return -1;
	}
	// 开辟成功                                         
	ps->i = 100;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		ps->a[i] = i;
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d ", ps->a[i]);
	}

	// a数组的空间不够了，调为20个整型数据
	struct st_type* ptr = (struct st_type*)realloc(ps, sizeof(struct st_type) + 20 * sizeof(int));
	if (ptr == NULL)
	{
		printf("扩容空间失败");
		return -1;
	}
	else
	{
		ps = ptr;
	}

	// 使用...

	// 释放
	free(ps);
	ps = NULL;

	return 0;
}


// 方法二...
struct st_type
{
	int i; // 4
	int* a; // 4
};

int main()
{
	struct st_type* ps = (struct st_type*)malloc(sizeof(struct st_type)); // 开辟8字节空间
	ps->i = 100;
	ps->a = (int*)malloc(10 * sizeof(int));

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		ps->a[i] = i;
	}
	for (i = 0; i < 10; i++)

	{
		printf("%d ", ps->a[i]);
	}

	// 调整ps->a 空间
	int* ptr = (int*)realloc(ps->a, 20 * sizeof(int));
	if (ptr == NULL)
	{
		printf("扩容失败\n");
		return -1;
	}
	else
	{
		ps->a = ptr;
	}

	// 使用...

	// 释放
	free(ps->a);
	ps->a = NULL;
	free(ps);
	ps = NULL;

	return 0;
}




// 柔性数组的实现有两个好处：
// 1. 方便内存释放
/* 如果我们的代码是在一个给别人用的函数中，你在里面做了二次内存分配，并把整个结构体返回给用户。用
户调用free可以释放结构体，但是用户并不知道这个结构体内的成员也需要free，所以你不能指望用户来发
现这个事。所以，如果我们把结构体的内存以及其成员要的内存一次性分配好了，并返回给用户一个结构体
指针，用户做一次free就可以把所有的内存也给释放掉 */
// 2. 有利于访问速度
/* 连续的内存有益于提高访问速度，也有益于减少内存碎片。（其实也没高多少，反正要用做偏移量的加法来寻址） */
// 局部性原理：  内存-高速缓存-寄存器 

// C语言结构体里的数组和指针
// https://coolshell.cn/articles/11377.html
