#include <stdio.h>

// 函数的声明和定义

// 函数的声明一般出现在函数的使用之前，要满足先声明后使用

#include "add.h"

int main()
{
	int a = 10;
	int b = 20;

	int ret = Add(a, b);

	printf("%d\n", ret);

	return 0;
}

// 分快去写的好处:
// 1. 多人协作
// 2. 封装和隐藏
// add.c和add.h 编译生成一个add.lib文件（点头文件右击属性- 常规- 配置类型改为静态库.lib  在debug里生成一个add.lib文件）
// add.h 和add.lib
// 在test.c里加上#pragma comment(lib, "add.lib")导入静态库就可以使用


// 函数的声明放在.h文件里声明
// 函数的实现在对应的.c文件里


// 防止头文件被重复多次引用
// #ifndef __ADD_H__
// #define __ADD_H__
// #endif
// 等价于#pragma once




// 函数递归
// 一个过程或函数在其定义或说明过程中，有直接或间接调用自身的一种方法，多次重复计算，减少了程序的代码量
// 递归的主要思考方式：把大事化小

// 练习1
// 接受一个整型值（无符号），按照顺序打印它的每一位
void print(unsigned int n)
{
	if (n > 9)
	{
		print(n / 10); // 123
	}
	printf("%d ", n % 10);
}

int main()
{
	unsigned int num = 0;
	scanf_s("%u", &num);

	print(num);
	
	return 0;
}
// 1. 1234>9   1234/10=123 调用print函数
// 2. 123>9    123/10=12   调用print函数
// 3. 12>9     12/10=1     调用print函数
// 4. 1<9  执行printf打印  n%10=1  打印  返回（函数从哪里调用就返回哪里）
// 5. 往下执行printf打印 此时n是12    n%12=2    打印2 
// 6. 往下执行printf打印 此时n是123   n%123=3   打印3
// 7. 往下执行printf打印 此时n是1234  n%1234=4  打印4 
// 8. 调用完 返回main中print 往下执行 return 0 
// 1_2_3_4_



// 递归的两个必要条件：
// 存在限制条件，当满足这个限制条件时，递归不再继续
// 每次递归调用之后，越来越接近这个限制条件。

// 如果没有判断条件 死递归
// 为main print函数各自开辟的空间 - 函数栈帧
// ....................................................................


// 练习2
// 编写函数不允许创建临时变量，求字符串的长度
int main()
{
	char arr[] = "abcdef";
	int len = strlen(arr);

	printf("%d\n", len); // 6

	return 0;
}


// 有临时变量count
my_strlen(char* s)
{
	int count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return count;
}

int main()
{
	char arr[] = "abcdef";
	// 数组名arr是数组首元素的地址 数组每个元素都是char类型 数组首元素也是char类型 数组首元素的地址是char*类型 - char*

	int len = my_strlen(arr); // 数组名传过去

	printf("%d\n", len);

	return 0;
}


// 用递归求
my_strlen(char* s)
{
	if (*s != '\0')
	{
		return 1 + my_strlen(s + 1);
	}
	else
	{
		return 0;
	}
}

int main()
{
	char arr[] = "abcdef";
	// 数组名arr是数组首元素的地址 数组每个元素都是char类型 数组首元素也是char类型 数组首元素的地址是char*类型 - char*

	int len = my_strlen(arr); // 数组名传过去

	printf("%d\n", len);

	return 0;
}
// 'a' != '\0'  进入if  strlen递归  s+1  bcdef\0
// 'b' != '\0'  进入if  strlen递归  s+1  cdef\0
// 'c' != '\0'  进入if  strlen递归  s+1  def\0
// 'd' != '\0'  进入if  strlen递归  s+1  ef\0
// 'e' != '\0'  进入if  strlen递归  s+1  f\0
// 'f' != '\0'  进入if  strlen递归  s+1  \0
// '\0' = '\0'  执行else  return 0  返回
// return 1 + 0 = 1   返回1
// 1+1=2  返回2
// 1+2=3  返回3
// 1+4=5  返回5
// 1+5=6  返回6
// 返回main my_strlen  往下执行
// 往下执行 printf打印6
// 6



// 字符指针+1  - 向后跳1个字节
// char *p;
// p+1  ->  向后跳1个字节
//
// 整形指针+1  - 向后跳4个字节
// int *p;
// p+1  -> 向后跳4个字节
//
// 指针加一都是指向下一个元素地址，指针类型不同，跳过的字节也不同





// 递归与迭代

// 练习3
// 求n的阶乘（不考虑溢出）

// 用循环 
int Fac(int n)
{
	int i = 0;
	int ret = 1;
	for (i = 1; i <= n; i++)
	{
		ret *= i;
	}
	return ret;
}

int main()
{
	int n = 0;
	scanf_s("%d", &n);

	int ret = Fac(n);

	printf("%d\n", ret);

	return 0;
}


// 求n的阶乘递归公式：
// n<=1时 Fac(n) = 1
// n>1时  Fac(n) = n*fac(n-1)

// 用递归
int Fac(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return n * Fac(n - 1);
	}
}

int main()
{
	int n = 0;
	scanf_s("%d", &n);

	int ret = Fac(n);

	printf("%d\n", ret);

	return 0;
}
// 例求3的阶乘  调用Fac函数
// 3>1  else  调用Fac(2)
// 2>1  else  调用Fac(1)
// 1<=1  if  return 0  返回1
// 2*1=2  返回2
// 3*2=6  返回6
// 6



// 练习4
// 求第n个斐波那契数

// 1 1 2 3 5 8 13 21 34 55 ...
// 前2个数字之和等于第3个数字

// 求第n个斐波那契数递归公式：
// Fib(n)
// 当n<=2时  Fib(n) = 1
// 当n>2时   Fib(n) = Fib(n-1) + Fib(n-2)

int count = 0;

int Fib(int n)
{
	// 第三个斐波那契数被重复计算多少次
	if (n == 3)
	{
		count++;
	}

	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return Fib(n - 1) + Fib(n - 2);
	}
}

int main()
{
	int n = 0;
	scanf_s("%d", &n);

	int ret = Fib(n);

	printf("%d\n", ret);

	printf("count = %d\n", count);

	return 0;
}
// 求40
// count = 39088169



// 迭代（循环）
// 优化 简便 提高效率
int Fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;

	while (n > 2)
	{
		// 当n=3时 开始计算
		c = a + b;
		a = b;
		b = c;
		n--;
	}

	return c;
}

int main()
{
	int n = 0;
	scanf_s("%d", &n);

	int ret = Fib(n);

	printf("%d\n", ret);

	return 0;
}
// a = 1
// b = 1
// c = a + b
// 求完3
// 把b放进a 把c放进a



// 什么时候用递归：
// 1. 当解决一个问题递归和非递归都可以使用，且没有名下那问题，那就可以使用递归
// 2. 当解决一个问题写起来很简单，非递归比较复杂，且递归没有明显问题，那就用递归
// 3. 如果说用递归解决问题，写起来简单，但是有明显问题，那就不能使用递归，得写出非递归方式来解决



// 函数递归几个经典题目：
// 1. 汉纳塔问题
// 2. 青蛙跳台问题
