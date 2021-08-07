#define _CRT_SECURE_NO_WARNINGS 1

//解引用
unsigned long pulArray[] = { 6,7,8,9,10 };
unsigned long* pulPtr;
pulPtr = pulArray;
*(pulPtr + 3) += 3;
printf("%d, %d\n", *pulPtr, *(pulPtr + 3));
//把pulArray首元素的地址给pulPtr
//pulPtr + 3解引用 指向第四个元素9 给9加三
//6 12



//结构体
struct S
{
	int a;
	int b;
};
int main()
{
	struct S a, * p = &a;
	a.a = 99;
	printf("%d\n", __________);
	return 0;
}
//struct *p = &a;
//a.a =99;
//结构体类型变量需要访问其成员时，用.运算符，如果是指向结构体变量的指针访问时，
//需要用->,或者先对指针解引用，取到指向的结构体类型的变量，再通过.访问，但是要注意优先级
// *p.a 错误 因为.的优先级更高



//字符串逆序
//将一个字符串str的内容颠倒过来，并输出。str的长度不超过100个字符。
//输入一个字符串，可以有空格

//下标
#include <stdio.h>

void reverse(char* str)
{
	unsigned int len = strlen(str);
	int left = 0;
	int right = len - 1;

	while (left < right)
	{
		int tmp = str[left];
		str[left] = str[right];
		str[right] = tmp;
		left++;
		right--;
	}
}

int main()
{
	char arr[100] = { 0 };

	gets(arr);

	reverse(arr);

	printf("%s\n", arr);

	return 0;
}

//指针
void reverse(char* str)
{
	unsigned int len = strlen(str);
	char* left = str;
	char* right = str + len - 1;

	while (left < right)
	{
		int tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

int main()
{
	char arr[100] = { 0 };

	gets(arr);

	reverse(arr);

	printf("%s\n", arr);

	return 0;
}



//打印菱形
int main()
{
	int line = 0;
	scanf("%d", &line); //7

	int i = 0;
	//上 - 7行
	for (i = 0; i < line; i++)
	{
		//打印一行
		//打印空格
		int j = 0;
		for (j = 0; j < line - 1 - i; j++)
		{
			printf(" ");
		}
		//打印*
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	//下 - 6行
	for (i = 0; i < line - 1; i++)
	{
		int j = 0;
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		//* 打印
		for (j = 0; j < (line - 1 - i) * 2 - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}



//喝汽水问题
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水
int main()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);
	//购买
	total += money;
	empty = money;

	//置换
	while (empty >= 2)
	{
		total += empty / 2;
		empty = empty / 2 +empty%2; //empty%2  换的时候剩下的一瓶
	}

	printf("%d\n", total);

	return 0;
}


int main()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);

	if (money >= 1)
		total = 2 * money - 1; //买一瓶 19元换38空瓶
	else
		total = 0;

	printf("%d\n", total);

	return 0;
}



/*调整奇数偶数顺序
输入一个整数数组，实现一个函数，
来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
所有偶数位于数组的后半部分。*/
//void move_Parity(int* arr, int sz)
//{
//	int* left = arr;
//	int* right = arr + sz - 1;
//
//	while (left < right)
//	{
//		while ((*left) % 2 != 0)
//		{
//			left++;
//		}
//		while ((*right) % 2 == 0)
//		{
//			right--;
//		}
//		if (left < right)
//		{
//			int tmp = *left;
//			*left = *right;
//			*right = tmp;
//		}
//	}
//}


void move_Parity(int* arr, int sz)
{
	int left = 0;
	int right = sz - 1;

	while (left < right)
	{
		//从前向后找到一个偶数
		while ((left<right) && arr[left] % 2 == 1)
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
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	move_Parity(arr, sz);

	Print(arr, sz);

	return 0;
}



//数据的存储

//数据类型
//基本的内置类型:

//C语言库函数是编译器的厂商提供的，如VS，gcc
//C语言标准规定了一些库函数：函数名，参数类型，返回值类型，函数功能
//size_t strlen(const char* str);

//类型的意义：
//1. 使用这个类型开辟内存空间的大小（大小决定了使用范围）。
//2. 如何看待内存空间的视角。

/*二、类型的基本归类：
整形家族：
char:
unsigned char
signed char
short:
unsigned short[int]
signed short[int]
int:
unsigned int
signed int
long:
unsigned long[int]
signed long[int]
long long */

//char a; 有无符号 取决于编译器
//short,int,long --都是有符号的，加上unsigned才是无符号


//unsigned signed区别
//char -- 1byte-- 8bit
int main()
{
	unsigned char c1 = 255; //无符号 最高位是有效位 -1是全1
	printf("%d\n", c1); //255
	//11111111 - 内存中放二进制的补码

	char c2 = 255; //char --signed char 最高位是符号位
	//11111111
	//11111110
	//10000001
	printf("%d\n", c2); //-1

	return 0;
}


//范围
//与符号的char -- -128~127  
//unsigned char -- 0~255


/*浮点数家族：
float
double */


/*构造类型（自定义类型）：
数组类型
结构体类型 struct
枚举类型 enum
联合类型 union*/

//数组类型 - 自定义类型
int main()
{
	int a = 10;
	int arr[10] = { 0 }; //arr-数组名
	//去了数组名就是类型 - int [10]

	printf("%d\n", sizeof(a)); //4
	printf("%d\n", sizeof(int)); //4
	
	printf("%d\n", sizeof(arr)); //40
	printf("%d\n", sizeof(int [10])); //40

	int arr2[5]; //数组类型：int [5]
	//数组元素个数不一样时，数组类型也会改变
	return 0;
}


/*指针类型
int* pi;
char* pc;
float* pf;
void* pv;*/


/*空类型：
void 表示空类型（无类型）
通常应用于函数的返回类型、函数的参数、指针类型。*/

void test(void) //函数调用不要传参
{
	printf("hehe\n");
}

int main()
{
	test();
	test(100);

	return 0;
}



//三、整形在内存中的存储
//原码、反码、补码

/*==对于整形来说：数据存放内存中其实存放的是补码。==
在计算机系统中，数值一律用补码来表示和存储。原因在于，使用补码，可以将符号位和数值域统一处理； 同
时，加法和减法也可以统一处理（CPU只有加法器）此外，补码与原码相互转换，其运算过程是相同的，不需
要额外的硬件电路。*/
//原反补 转换 可以用符号位不变，其他位按位取反，+1相互转换


//什么是大端小端：
/*int a = 0x11223344;
以字节存放
44 33 22 11 小端字节序存储 
低地址 ----高地址
11 22 33 44 大端字节序存储*/

/* 小端字节序存储：
把一个数字的低位字节的内容，存放在内存的低地址处
        把高位字节的内容存放在高地址处
大端字节序存储：
把一个数字的低位字节的内容，存放在内存的高地址处
        把高位字节的内容存放在低地址处 */


/*为什么有大端和小端：
为什么会有大小端模式之分呢？这是因为在计算机系统中，我们是以字节为单位的，每个地址单元都对应着一
个字节，一个字节为8bit。但是在C语言中除了8bit的char之外，还有16bit的short型，32bit的long型（要看具
体的编译器），另外，对于位数大于8位的处理器，例如16位或者32位的处理器，由于寄存器宽度大于一个字
节，那么必然存在着一个如果将多个字节安排的问题。因此就导致了大端存储模式和小端存储模式。
例如一个 16bit 的 short 型 x ，在内存中的地址为 0x0010 ， x 的值为 0x1122 ，那么 0x11 为高字节， 0x22
为低字节。对于大端模式，就将 0x11 放在低地址中，即 0x0010 中， 0x22 放在高地址中，即 0x0011 中。小
端模式，刚好相反。我们常用的 X86 结构是小端模式，而 KEIL C51 则为大端模式。很多的ARM，DSP都为小
端模式。有些ARM处理器还可以由硬件来选择是大端模式还是小端模式。*/
