#define _CRT_SECURE_NO_WARNINGS 1

// 1、修改默认对齐数

// 用预处理指令#pragma设置默认对齐数 并取消设置，还原默认
//#include <stdio.h>
//
//// 紧挨着放 没有空间浪费 效率低
//#pragma pack(1)
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
//#pragma pack()
//
//int main()
//{
//	struct S1 s[] = { 0 };
//	printf("%d\n", sizeof(s)); // 6
//
//	return 0;
//}


// 2、宏offsetof（传参时可以传类型）
// 计算一个结构体成员相对于结构体在内存中存储的起始位置的偏移量
// size_t offsetof( structName, memberName );
//#include <stdio.h>
//#include <stddef.h>
//
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
//
//int main()
//{
//	printf("%d\n", offsetof(struct S1, c1)); // 0
//	printf("%d\n", offsetof(struct S1, i)); // 4
//	printf("%d\n", offsetof(struct S1, c2)); // 8
//
//	return 0;
//}


// 3、结构体传参
//#include <stdio.h>
//
//struct S
//{
//	int data[1000];
//	int num;
//};

// 结构体传参
//void print1(struct S tmp)
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", tmp.data[i]);
//	}
//	printf("\nnum = %d\n", tmp.num);
//}

// 结构体地址传参
//void print2(struct S* ps)
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", ps->data[i]);
//	}
//	printf("\nnum = %d\n", ps->num);
//}
//
//int main()
//{
//	struct S s = { {1,2,3,4,5,6,7,8,9,10}, 100 };
//	
//	print1(s); // 传结构体
//	print2(&s); // 传地址
//
//	return 0;
//}
/* 函数传参的时候，参数是需要压栈，会有时间和空间上的系统开销。
如果传递一个结构体对象的时候，结构体过大，参数压栈的的系统开销比较大，所以会导致性能的下降。 */


// 二、位段
// 结构体讲完就得讲讲结构体实现 位段 的能力。

// 位段是可以节省空间的
// 位段 - 二进制位
//#include <stdio.h>
//
//struct A
//{
//	int _a : 2; // _a - 2个bit为位
//	int _b : 5; // _b - 5个bit为位
//	int _c : 10; 
//	int _d : 30;
//};
//
//int main()
//{
//	printf("%d\n", sizeof(struct A)); // 8
//	return 0;
//}


// 位段的内存分配
/* 1. 位段的成员可以是 int unsigned int signed int 或者是 char （属于整形家族）类型
2. 位段的空间上是按照需要以4个字节（ int ）或者1个字节（ char ）的方式来开辟的。
3. 位段涉及很多不确定因素，位段是不跨平台的，注重可移植的程序应该避免使用位段。 */

//一个例子
//struct S
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//
//int main()
//{
//	struct S s = { 0 };
//	s.a = 10; // 1010 - 010
//	s.b = 12; // 00001100 - 1100
//	s.c = 3; // 00000011 - 00011
//	s.d = 4; // 00000100 - 0100
//}
//空间是如何开辟的？

// 推测：
// char-> 先开辟1字节 00000000
// a-3bit    010
// b-4bit    1100
// 剩下的空间不够用 再开辟1字节
// c-5bit    00011
// 剩下的空间不够用 再开辟1字节
// d-4bit    0100
// 左<-右   高
// 0(1100)(010)  000(00011)  0000(0100)
// 62 03 04


// 位段的跨平台问题
/* 1. int 位段被当成有符号数还是无符号数是不确定的。
2. 位段中最大位的数目不能确定。（16位机器最大16，32位机器最大32，写成27，在16位机器会出问题。
3. 位段中的成员在内存中从左向右分配，还是从右向左分配标准尚未定义。
4. 当一个结构包含两个位段，第二个位段成员比较大，无法容纳于第一个位段剩余的位时，是舍弃剩余的位还是利用，这是不确定的。 */

// 总结：
// 跟结构相比，位段可以达到同样的效果，但是可以很好的节省空间，但是有跨平台的问题存在。



// 三、枚举
//#include <stdio.h>
//// enum Color枚举类型。{}中的内容是枚举类型的可能取值，也叫 枚举常量
//enum Color
//{
//	RED = 2, // 赋初值
//	GREEN,
//	BLUE,
//};
//
//int main()
//{
//	enum  Color c = GREEN; // 枚举类型赋可能取值
//
//	if (c == GREEN)
//	{
//		printf("绿色\n");
//	}
//
//	return 0;
//}


// 枚举的优点
/* 我们可以使用 #define 定义常量，为什么非要使用枚举
1. 增加代码的可读性和可维护性
2. 和#define定义的标识符比较枚举有类型检查，更加严谨。
3. 防止了命名污染（封装）
4. 便于调试
5. 使用方便，一次可以定义多个常量*/

// 例 实现计算器清晰明了
//enum Option
//{
//	EXIT, // 0
//	ADD, // 1
//	SUB,
//	MUL,
//	DIV,
//};
//
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择:>\n");
//		switch (input)
//		{
//		case ADD:
//			break;
//		case SUB:
//			break;
//		case MUL:
//			break;
//		case DIV:
//			break;
//		case EXIT:
//			break;
//		}
//	} while (input);
//	
//	return 0;
//}


// 联合体（共用体）
// 联合类型的定义
// 联合也是一种特殊的自定义类型 这种类型定义的变量也包含一系列的成员，特征是这些成员公用同一块空间（所以联合也叫共用体）
//#include <stdio.h>
//
////联合类型的声明
//union Un
//{
//	char c;
//	int i;
//};
//
//int main()
//{
//	//联合变量的定义
//	union Un u = { 0 };
//
//	// 地址一样
//	printf("%p\n", &u);
//	printf("%p\n", &(u.c));
//	printf("%p\n", &(u.i));
//
//	return 0;
//}

// 联合的特点
// 联合的成员是共用同一块内存空间的，这样一个联合变量的大小，至少是最大成员的大小（因为联合至少得有能力保存最大的那个成员）


// 判断当前计算机的大小端存储
//#include <stdio.h>
//
// 1
//int main()
//{
//	int a = 1;//0x 00 00 00 01
//	//低---------------------> 高
//	//01 00 00 00 - 小端存储
//	//00 00 00 01 - 大端存储
//
//	char* pc = (char*)&a;
//	if (*pc == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//}

// 2
//int check_sys()
//{
//	union U
//	{
//		char c;
//		int i;
//	}u;
//	u.i = 1;
//	return u.c;
//}
//
//int main()
//{
//	if (check_sys() == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//
//	return 0;
//}


// 联合大小的计算
/* 联合的大小至少是最大成员的大小。
当最大成员大小不是最大对齐数的整数倍的时候，就要对齐到最大对齐数的整数倍。 */

//例：计算以下代码结果
//union Un1
//{
//	char c[5]; // 5    1
//	int i; // 4  8     4 
//	// 联合体的总大小必须是4的倍数 在c后浪费3个字节 结果是8
//};
//union Un2
//{
//	short c[7]; // 14    2
//	int i; // 4  8       4
//	// 14不是4的倍数 结果是16
//};
//
//int main()
//{
//	printf("%d\n", sizeof(union Un1)); // 8
//	printf("%d\n", sizeof(union Un2)); // 16
//}


// 通讯录程序
