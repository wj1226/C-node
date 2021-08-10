#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	const str1[] = { "hello bit." };
	const str2[] = { "hello bit." };
	const char* str3 = "hello bit.";
	const char* str4 = "hello bit.";

	if (str1 == str2) //数组名 比较两个字符串首元素地址
		printf("str1 and str2 are same\n");
	else
		printf("str1 and str2 are not same\n");

	if (str3 == str4)
		printf("str3 and str4 are same\n");
	else
		printf("str3 and str4 are same\n");
	//常量字符串 -不能修改的
	//str3 str4内容一样 指向同一字符串首地址

	return 0;
}
//《剑指offer》


//指针数组
char* arr[5]; //ar是存放字符指针的数组
int* arr2[4]; //arr2是存放整形指针的数组


//解引用打印数组元素
int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;

	int* arr[4] = { &a, &b, &c, &d };
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		printf("%d ", *(arr[i]));
	}

	return 0;
}


//
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 2,3,4,5,6 };
	int arr3[] = { 3,4,5,6,7 };

	int* parr[] = { arr1, arr2, arr3 };
	//数组名是首元素地址 arr1是int*类型

	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 5; j++)
		{
			printf("%d ", parr[i][j]); // p[i] == *(p+i)
			// parr[i][j] == *(parr[i]+j)
		}
		printf("\n");
	}

	return 0;
}


//字符指针初始化
int main()
{
	const char* arr[5] = { "abcdef", "bcd", "hehe", "haha", "hello" };
	//存放每个字符串的首元素地址
	//常量字符串 不能改 加const
	
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("%s\n", arr[i]);
	}
	return 0;
}



//==数组指针==     

//是指针
int* p; //整形指针 - 指向整形的指针

//取数组地址-放在数组指针里
int main()
{
	int a = 10;
	int* pi = &a; //整形的地址存放在整形指针中

	char ch = 'w';
	char* pc = &ch; //字符的地址存放在字符指针里

	int arr[10] = { 0 };
	int* p = arr; //数组首元素的地址

	//int* parr[10]; 这样写是数组
	int (*parr)[10] = &arr; //取出的是数组的地址，应该存放在数组指针里

	return 0;
}


int main()
{
	int arr[10] = { 0 };
	//arr; //数组名是首元素的地址
	//&arr[0]; //首元素的地址
	//
	//&arr; //取出数组的地址

	printf("%p\n", arr); //arr类型是int*
	printf("%p\n", &arr[0]); //int*
	printf("%p\n", &arr); //数组的地址类型：int(*)[10] 
	//int(*p)[10] = &arr;

	printf("%p\n", arr+1);
	printf("%p\n", &arr[0]+1);
	printf("%p\n", &arr+1);

	return 0;
}


//数组指针类型
int main()
{
	int* arr[10];
	int* (*p)[10] = &arr;

	return 0;
}


//数组指针的使用
//下标
void print1(int arr[], int sz)
{
	int i = 0; 
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

//指针
void printf2(int* arr, int sz)
{
	int i = 0; 
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(arr + i));
	}
}

//数组指针
void print3(int(*parr)[10], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", parr[0][i]); //从第一个元素向后找
		printf("%d ", *(parr +0)[i]);
		printf("%d ", *(parr)[i]); //(*parr) 相当于parr指向的数组的数组名
	}
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print1(arr, sz);
	print2(arr, sz);
	print3(&arr, sz); //一维数组不适合

	return 0;
}


//二维数组传参
void print1(int arr[3][5], int r, int c)
{
	int i = 0;
	for (i = 0; i < r; i++)
	{
		int j = 0; 
		for (j = 0; j < c; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void print2(int(*p)[5], int r, int c)
{
	int i = 0;
	for (i = 0; i < r; i++)
	{
		int j = 0;
		for (j = 0; j < c; j++)
		{
			//*(p + i)//加i找到行 加j找到元素 解引用
			//printf("%d ", *(*p + i) + j);
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int arr[3][5] = { 1,2,3,4,5, 2,3,4,5,6, 3,4,5,6,7 };
	print1(arr, 3, 5); //二维数组传参
	printf("\n");

	print2(arr, 3, 5); //首元素地址 指针接受
	//二维数组 三个元素 是一维数组 传的是一维数组的地址
	//首元素就是二维数组的第一行 1 2 3 4 5
	//*p指针 5个元素 每个元素是int类型

	return 0;
}


//判断
int arr[5]; //整型数组

int *parr1[10]; 
//parr1是一个数组，10个元素，每个元素是int*的，所以parr1是一个存放指针的数组

int (*parr2)[10]; 
//parr2是一个数组指针，该指针指向的数组有10个元素，每个元素是int的

int (*parr3[10])[5]; 
//parr3是一个数组，数组有10个元素，每个元素石神一个数组指针，
//该指针指向的数组有5个元素，每个元素是int
