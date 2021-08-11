#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//一、数组参数、指针参数

//1、一维数组传参
void test(int arr[])
void test(int* p)
{}
int main()
{
	int arr[10] = { 0 };
	test(arr);
	return 0;
}


//
void test(int** p)
{}
int main()
{
	int* arr[10] = { 0 }; //10个元素 每个元素是int*类型 首元素地址就是int*的地址 用二级指针接收
	test(arr);
	return 0;
}


//2、二维数组传参
void test(int arr[3][5]) {}
void test(int arr[][5]) {} //不能省略列 可以省略行

//用指针方式传
//二维数组传首元素的时候，指的是第一行 
//用指向数组的是指针接收
void test(int(*p)[5]) {} //*p指针 5个元素 每个元素是int

int main()
{
	int arr[3][5] = { 0 };
	test(arr);
	return 0;
}


//3、一级指针传参
void print(int* ptr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(ptr + i));
	}
}

int main()
{
	int arr[] = { 1,2,3,4,4,5,6,7,8,9,10 };
	int* p = arr;
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(p, sz);

	return 0;
}


//int* p可以是什么传的
void test(int* p)
{}
int main()
{
	int a = 10;
	int* p1 = &a;
	int arr[10] = { 0 };

	test(&a);
	test(arr);
	test(p1);

	return 0;
}


//4、二级指针传参
void test(int** ppa)
{}
int main()
{
	int a = 10;

	int* pa = &a;
	int** ppa = &pa;

	test(ppa);
	test(&pa);

	int* arr[5];
	test(arr); //指针数组的地址

	return 0;
}



//二、函数指针

//函数指针变量 - 存放函数的地址
int Add(int x, int y)
{
	return x + y;
}

int main()
{
	printf("%p\n", &Add);
	//函数名 == &函数名
	printf("%p\n", Add);

	return 0;
}


//类型 变量
int Add(int x, int y)
{
	return x + y;
}

int main()
{
	int (*pf)(int, int) = &Add; //pf是用来存放函数的地址- pf就是函数指针变量
	//*pf指针存放地址 指向Add，参数类型是int 返回类型也是int

	int arr[10] = { 0 };
	int(*parr)[10] = &arr; //parr是数组指针变量

	//类型
	int a = 10; //int
	int arr[10] = { 0 }; //int [10]
	int(*parr)[10] = &arr; //int(*)[10]
	int (*pf)(int, int) = &Add; //int(*)(int, int)

	return 0;
}


//调用
int Add(int x, int y)
{
	return x + y;
}

//1
int main()
{
	int (*pf)(int, int) = &Add;
	int ret = Add(2, 3);
	printf("%d\n", ret); //5

	ret = (*pf)(4, 5);
	printf("%d\n", ret); //9

	return 0;
}

//2
int main()
{
	int (*pf)(int, int) = Add;
	int ret = Add(2, 3);
	printf("%d\n", ret); //5

	//ret = (*pf)(4, 5);
	ret = pf(4, 5); //*可省略
	printf("%d\n", ret); //9

	return 0;
}


//有趣的代码
//1
int main()
{
	(*(void (*)()) 0) ();
	//void (*ptr)();
	//0强制类型转换成函数指针类型void(*)() 把0当做地址 指向了无参无返回值的函数，然后解引用调用这个函数
	//代码是一次函数调用
	//1. 代码中把0强制类型转换成类型为void(*)()的一个函数的地址
	//2. 解引用0地址 就是取0地址的这个函数 被调用的函数是无参 返回类型是void
	return 0;
}
//《C陷阱与缺陷》

//2
int main()
{
	void(*signal(int, void(*)(int)))(int);
	//此代码是一次函数声明
	//声明的函数名是signal
	//signal函数有2个参数，第一个：int类型 第二个：void(*)(int)的函数指针类型
	//signal函数的返回类型依然是：void(*)(int)的函数指针类型

	return 0;
}

//简化
typedef void(*pfun_t)(int);

int main()
{
	pfun_t signal(int, pfun_t);

	return 0;
}



//三、函数指针数组

int* arr[10]; //整型指针的数组
//函数指针的数组 - 存放函数指针的数组

int Add(int x, int y) //int (*)(int, int)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int main()
{
	int (*pf1)(int, int) = Add;
	int (*pf2)(int, int) = Sub;

	//pfArr就是一个函数指针的数组
	int (*pfArr[2])(int, int) = { Add, Sub };

	return 0;
}



//实现加减乘除
int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

void menu()
{
	printf("**********************************\n");
	printf("*******  1. add    2. sub  *******\n");
	printf("*******  3. mul    4. div  *******\n");
	printf("*******  0. exit           *******\n");
	printf("**********************************\n");
}

int main()
{
	int input = 0;
	do
	{
		int x = 0;
		int y = 0;
		int ret = 0;
		menu();
		printf("请选择:>\n");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			printf("请输入2个操作数:>\n");
			scanf("%d %d", &x, &y);
			ret = Add(x, y);
			printf("ret=%d\n", ret);
			break;
		case 2:
			printf("请输入2个操作数:>\n");
			scanf("%d %d", &x, &y);
			ret = Sub(x, y);
			printf("ret=%d\n", ret);
			break;
		case 3:
			printf("请输入2个操作数:>\n");
			scanf("%d %d", &x, &y);
			ret = Mul(x, y);
			printf("ret=%d\n", ret);
			break;
		case 4:
			printf("请输入2个操作数:>\n");
			scanf("%d %d", &x, &y);
			ret = Div(x, y);
			printf("ret=%d\n", ret);
			break;
		case 0:
			printf("退出计算机\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}

	} while (input);

	return 0;
}

//优化 
int main()
{
	int input = 0;
	do
	{
		int x = 0;
		int y = 0;
		int ret = 0;
		menu();
		printf("请选择:>\n");
		scanf("%d", &input);
		//《C和指针》
		int (*pfArr[5])(int, int) = { 0, Add,Sub,Mul,Div };
		//0 1 2 3 4

		if (input == 0)
		{
			printf("退出计算器\n");
		}
		else if (input >= 1 && input <= 4)
		{
			printf("请输入2个操作数:>");
			scanf("%d %d", &x, &y);
			ret = pfArr[input](x, y);
			printf("%d\n", ret);
		}
		else
		{
			printf("选择错误\n");
		}

	} while (input);

	return 0;
}

//函数
void Calc(int(*pf)(int, int))
{
	int x = 0;
	int y = 0;
	int ret = 0;

	printf("请输入2个操作数:>\n");
	scanf("%d %d", &x, &y);
	ret = pf(x, y);
	printf("ret=%d\n", ret);
}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择:>\n");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			Calc(Add);
			break;
		case 2:
			Calc(Sub);
			break;
		case 3:
			Calc(Mul);
			break;
		case 4:
			Calc(Div);
			break;
		case 0:
			printf("退出计算机\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}

	} while (input);

	return 0;
}



//四、回调函数
/* 回调函数就是一个通过函数指针调用的函数。如果你把函数的指针（地址）作为参数传递给另一
个函数，当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。回调函数不是由该
函数的实现方直接调用，而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或
条件进行响应。 */



//五、指向函数指针数组的指针

int arr[10];
int(*p)[10] = &arr;
//p是一个指向 整型数组 的指针

int* arr[10]; //整型指针的数组
int* (*p)[10] = &arr; //整型指针数组的地址
//p是一个指向 整型指针数组 的指针

int Add(int x, int y)
{
	return x + y;
}
int (*pf)(int, int) = Add; //pf是函数指针
int (*pfArr[5])(int, int); //pfArr是一个函数指针的数组
int (*(*ppfArr)[5](int, int) = &pfArr;
//ppfArr是一个指向函数指针数组的指针
