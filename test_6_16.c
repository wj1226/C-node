#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// 指针
int main()
{
	int a = 10; // 向内存申请4个字节空间，里面存放10
	printf("%p\n", &a); // & - 取地址操作符 单目
	// %p - 按地址的方式打印

	int* pa = &a;
	// pa 是一个存放地址的变量，称为指针变量
	// int* 指针变量的类型

	char ch = 'w';
	char* pa = &ch;

	return 0;
}


int main()
{
	int a = 10;
	int* pa = &a;
	*pa = 20; // * - 解引用操作符
	printf("%d\n", a);
	return 0;
}


int main()
{
	char ch = 'w';
	char* pc = &ch;
	*pc = 'b';
	printf("%c\n", ch);
	return 0;
}


// 指针变量的大小
int main()
{
	printf("%d\n", sizeof(char*));
	printf("%d\n", sizeof(short*));
	printf("%d\n", sizeof(int*));
	printf("%d\n", sizeof(long*));
	printf("%d\n", sizeof(float*));
	printf("%d\n", sizeof(double*));

	return 0;
}


// 结构体
struct Student
{
	char name[20];
	int age;
	char sex[5];
	char id[12];
};

int main()
{
	struct Student s1 = { "张三", 20, "男", "1905468128" };
	struct Student s1 = { "李四", 19, "女", "1904927125" };

	return 0;
}


// 打印
struct Book
{
	char name[20];
	int price;
	char author;
};

int main()
{
	struct Book b1 = { "百年孤独", 55, "马尔克斯" };

	struct Book* pb = &b1;
	printf("%s %d %s\n", (*pb).name, (*pb).price, (*pb).author);
	printf("%s %d %s\n", pb->name, pb->price, pb->author);

	// . 结构体变量.成员名
	// -> 结构体->成员名
	return 0;
}