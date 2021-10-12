#define _CRT_SECURE_NO_WARNINGS 1

// 一、预处理详解
// 1、预定义符号
#include <stdio.h>

int main()
{
	printf("%s\n", __FILE__); // 当前源文件的路径
	printf("%d\n", __LINE__); // 当前代码行号
	printf("%s\n", __DATE__); // 文件被编译的日期
	printf("%s\n", __TIME__); // 文件被编译的时间

	// 如果编译器遵循ANSI C，其值为1，否则未定义
	printf("%d\n", __STDC__); // VS不支持ANSI C标准，所以__STDC__是未定义的

	return 0;
}


// 2、#define
// 2.1、#define 定义标识符常量
#include <stdio.h>

#define MAX 100
#define reg register
#define STR "HEHE"

int main()
{
	int m = MAX; // 预处理阶段就已经替换
	printf("%d\n", m);

	reg int num = 100;

	printf("%s\n", STR);

	return 0;
}


// 2.2、#define 定义宏
// #define 机制包括了一个规定，允许把参数替换到文本中，这种实现通常称为宏或定义宏
#include <stdio.h>

#define SQUARE1(X) X*X
#define SQUARE2(X) ( (X) * (X) )
//        宏名 参数 宏体

int main()
{
	int a = 5;
	int ret = SQUARE1(a); // 预处理阶段替换 --> int ret = a*a;
	printf("%d\n", ret);

	ret = SQUARE2(a); // --> int ret = ( (a) * (a) );
	printf("%d\n", ret);

	return 0;
}
// 用于对数值表达式进行求值的宏定义都应该用这种方式加上括号，避免在使用宏时由于
// 参数中的操作符或邻近操作符之间不可预料的相互作用

// 注意： 参数列表的左括号必须与name紧邻。 如果两者之间有任何空白存在，参数列表就会被解释为stuff的一部分。
// #define SQUARE1 (X) X*X // (X) X*X是一部分


// 2.3、#define INT int // 预处理替换
//typedef int INT_S // 对类型重命名 INT_S就是类型

// 例题：
#define ptr_t int*
typedef int* ptr_t2;

int main()
{
	ptr_t p1, p2;
	//预处理后替换为
	int *p1, p2;//p1是指针，p2是整形的
	ptr_t2 p3, p4;//p3和p4都是指针类型

	return 0;
}



// 2.4、#define 替换规则
/* 1. 在调用宏时，首先对参数进行检查，看看是否包含任何由#define定义的符号。如果是，它们首先被替换。
2. 替换文本随后被插入到程序中原来文本的位置。对于宏，参数名被他们的值替换。
3. 最后，再次对结果文件进行扫描，看看它是否包含任何由#define定义的符号。如果是，就重复上述处理过程。 */
#define MAX 100
#define ADD(X, Y) ( (X) + (Y) )

int main()
{
	int sum = ADD(MAX, 10);
	// int sum = ADD(100, 10)
	// int sum = ( (100) + (10) )

	return 0;
}
//注意：
//1. 宏参数和#define 定义中可以出现其他#define定义的变量。但是对于宏，不能出现递归。
//2. 当预处理器搜索#define定义的符号的时候，字符串常量的内容并不被搜索。
//int sum2 = ADD(ADD(2, 3), 1); // ok


// 2.5、#和##
#include <stdio.h>

// 相邻的两个字符串会合成一个
int main()
{
	printf("hello world\n");
	printf("hello ""world\n"); 
}


#include <stdio.h>

#define PRINT(n) printf("the value of "#n" is %d\n", n); // 替换 转化为对应得字符串 插入到字符串中

int main()
{
	int a = 10;
	PRINT(a); // printf("the calue of ""a"" is %d\n", a);
	int b = 20;
	PRINT(b); // printf("the calue of ""b"" is %d\n", b); // 三个字符串合成一个

	return 0;
}


// 2.6、##的作用
// #可以把位于它两边的符号合成一个符号。 
// 它允许宏定义从分离的文本片段创建标识符。
#include <stdio.h>

#define CAT(X, Y) X##Y

int main()
{
	int class102 = 100;
	printf("%d\n", CAT(class, 102)); // 100

	return 0;
}


// 2.7、带副作用的宏参数
int main()
{
	int a = 10;
	int b = a + 1;  // b得到11 且a不变
	int c = ++a; // b得到11 但a变了 这个表达式是有副作用的
}


// 两个数求较大值，宏的实现：
#include <stdio.h>

#define MAX(X, Y) ( (X)>(Y)?(X):(Y) )

int main()
{
	int a = 5;
	int b = 8;
	int m = MAX(a++, b++); 
	// 宏的参数不计算直接替换 替换进去后参与运算，而函数的参数时计算后传的
	// int m = ( (a++)>(b++)?(a++):(b++) );
	
	printf("%d\n", m); // 9

	// 5>8?(a++):(b++) 先使用，但a和b的值变成了6和9。因为5>8，所以a++不算，a是6。b++，先使用后++，b是10。
	printf("%d\n", a); // 6
	printf("%d\n", b); // 10

	return 0;
}


// 2.8、宏和函数对比
#include <stdio.h>

#define MAX(X, Y) ( (X)>(Y)?(X):(Y) )

int Max(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	int a = 5;
	int b = 8;

	int max1 = MAX(a++, b++);
	// int max1 = ((a++) > (b++) ? (a++) : (b++));

	int max2 = Max(a, b);

	printf("%d\n", max1);
	printf("%d\n", max2);

	return 0;
}

// 以上求较大值，宏与函数的实现，为什么不用函数来完成这个任务？ 原因有二：
/* 1. 函数是需要调用的，调用函数和从函数返回都是有时间开销的（函数栈帧），
而宏在预处理阶段就完成替换，宏比函数在程序的规模和速度方面更胜一筹。
2. 函数的参数必须声明为特定的类型。所以函数只能在类型合适的表达式上使用。反之这个宏怎可
以适用于整形、长整型、浮点型等可以用于>来比较的类型。宏是类型无关的。*/

// 宏相比函数也有劣势的地方：
/* 1. 每次使用宏的时候，一份宏定义的代码将插入到程序中。如果宏体很大，可能大幅度增加程序的长度。
2. 宏是没法调试的，因为已经替换。
3. 宏由于类型无关，没有类型限制，也就不够严谨。
4. 宏可能会带来运算符优先级的问题，导致程容易出现错。宏的参数里如果有表达式，需要加括号。 */

// 宏有时候可以做函数做不到的事情。比如：宏的参数可以出现类型，但是函数做不到。
#define MALLOC(num, type) \
	(type*)malloc(num*sizeof(type))
// \ - 续行符

int main()
{
	int* p = MALLOC(100, int);
	// int* p = (int*)malloc(100 * sizeof(int));
}


// 2.9、命名约定
// 宏的名字一般都是大写-MAX  函数的名字一般不全大写-Max


// 2.10、预处理指令 #undef 
#define MAX 100

int main()
{
	int m = MAX;
#undef MAX
	// 这条指令用于移除一个宏定义
	// 如果现存的一个名字需要被重新定义，那么它的旧名字首先要被移除
	int a = MAX; // 未定义标识符MAX
}


// 二、命令行定义
// 在命令行的时候赋初值
/* 许多C 的编译器提供了一种能力，允许在命令行中定义符号。用于启动编译过程。 例如：当我们根据同一个源文件要
编译出不同的一个程序的不同版本的时候，这个特性有点用处。（假定某个程序中声明了一个某个长度的数组，如果
机器内存有限，我们需要一个很小的数组，但是另外一个机器内存大写，我们需要一个数组能够大写。） */


// 三、条件编译
// 满足条件，代码参与编译，不满足条件，代码不参与编译
int main()
{
#if 1
	printf("hehe\n");
#endif

	return 0;
}

// 在预处理中，条件为假，语句printf("hehe\n");不参与编译
int main()
{
#if 0
	printf("hehe\n");
#endif

	return 0;
}


// 常见的条件编译指令：
/* 1.
#if 常量表达式
//...
#endif
//常量表达式由预处理器求值。 */
#define M 2
int main()
{
#if M==2
	printf("hehe\n");
#endif

	return 0;
}

//？？？？？？？？？？？？？？？？？？？？？？？？
int main()
{
	int a = 2;
#if a==2 // err 不能有变量
	printf("hehe\n");
#endif

	return 0;
}


// 2. 多个分支的条件编译
/* #if 常量表达式
//...
#elif 常量表达式
//...
#else
//...
#endif */
#define M 100
int main()
{
#if M==100
	printf("hehe\n");
#elif M==200
	printf("haha\n");
#else
	printf("hello\n");
#endif

	return 0;
}


// 3.判断是否被定义
#define MAX 0

int main()
{
#if defined(MAX) // 判断MAX是否被定义
	printf("hehe:MAX\n");
#endif

// 写法同下：
#ifdef MAX
	printf("hehe:MAX\n");
#endif

	return 0;
}

// 判断没有定义：
int main()
{
#if !defined(MAX)
	printf("haha:MAX\n");
#endif

	// 写法同下：
#ifndef MAX
	printf("haha:MAX\n");
#endif

	return 0;
}


// 4.嵌套指令
int main()
{
//
#if defined(OS_UNIX)
		#ifdef OPTION1 //
				unix_version_option1();
		#endif

		#ifdef OPTION2 //
			unix_version_option2();
		#endif
//
#elif defined(OS_MSDOS)
		#ifdef OPTION2 //
			msdos_version_option2();
		#endif
//
#endif
}


// 四、文件包含

// 1、头文件被包含的方式

// 本地文件包含"" --> #include "add.h"
// 1. 首先在当前工程的目录下查找
// 2. 如果第一步找不到，就去库函数的目录下查找，如果找不到就提示编译错误

// 库文件包含 --> #include <stdio.h>
// 直接在库函数的目录下查找，如果找不到就提示编译错误

/* 这样是不是可以说，对于库文件也可以使用 “” 的形式包含？ 答案是肯定的，可以。
但是这样做查找的效率就低些，当然这样也不容易区分是库文件还是本地文件了 */

//#include "C:\\Users\\XXXXX\\Desktop\\add.h" 可以根据路径


// 2、嵌套文件包含
// 文件内容的重复。如何解决？：条件编译
#include "test.h"
#include "test.h"
#include "test.h"

int main()
{
	return 0;
}
/* 每个头文件的开头写：
#ifndef __TEST_H__
#define __TEST_H__
//头文件的内容
#endif __TEST_H__
或者：
#pragma once */

/*
《高质量C / C++编程指南》
1. 头文件中的 ifndef / define / endif是干什么用的 ?
2. #include <filename.h> 和 #include "filename.h"有什么区别 ?
*/


// 五、其他预处理指令
#undef
#ifdef
#ifndef
#pragma pack()
#elif
#else
#endif
#pragma
#error
#line
...
