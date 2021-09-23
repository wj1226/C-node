#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// 1. 进制转换

// 输入一个正整数n(1 ≤ n ≤ 109)
// 输出描述：
// 输出一行，为正整数n表示为六进制的结果
int main()
{
	int num = 0;
	int arr[50] = { 0 };
	//输入
	scanf("%d", &num);
	//转换
	int i = 0;
	while (num)
	{
		arr[i] = num % 6; // %6/6得到最低位 倒着打印出来
		i++;
		num = num / 6;
	}
	//输出
	for (i--; i >= 0; i--) //循环停下来时i++ 指向下一个 先i-- 倒着打印 调整也是i--
	{
		printf("%d", arr[i]);
	}
	return 0;
}



// 2. n个人在等电梯。电梯每次可以乘坐12人，每次上下需要的时间为4分钟（上需要2分钟，下需要2分钟）。
// 输入包含一个整数n (0 ≤ n ≤ 109)
// 输出一个整数，即小乐乐到达楼上需要的时间。
int main()
{
	int n = 0;
	int t = 0;
	//输入
	scanf("%d", &n);
	//计算
	int t = n / 12 * 4 + 2;
	//输出
	printf("%d\n", t);

	return 0;
}



// 3. 输出一个正整数，为n和m的最大公约数与最小公倍数之和。
// 超时 效率低
int main()
{
	long n = 0;
	long m = 0;
	//输入
	scanf("%d %d", &n, &m);
	//计算
	//1. 计算最大公约数
	long long max = (m > n) ? (n) : (m);
	while (1)
	{
		if ((m % max == 0) && (n % max == 0))
		{
			break;
		}
		max--;
	}
	//2. 计算最小公倍数
	long long min = (m > n) ? (m) : (n); // 最小公倍数从两数中较大开始
	while (1)
	{
		if ((min % m == 0) && (min % n == 0))
		{
			break;
		}
		min++;
	}
	//3. 求和
	long long sum = max + min;
	//打印
	printf("%lld", sum);

	return 0;
}


//辗转相除法求最大公约数 最小公倍数=
int main()
{
	long long n = 0;
	long long m = 0;

	scanf("%d %d", &n, &m);

	long long n2 = n;
	long long m2 = m;

	long long c = 0;
	while (c = m2 % n2)
	{
		m2 = n2;
		n2 = c;
	}

	long long min = m * n / n2;

	long long sum = min + n2;

	printf("%lld", sum);

	return 0;
}



// 4. 从键盘任意输入一个字符，编程判断是否是字母（包括大小写）。
// 多组输入，每行输入包括一个字符。
// 输出该字符是字母（YES）或不是（NO）。
int main()
{
	// 多组输入
	int ch = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch >= 'A' && ch <= 'Z' || (ch >= 'a' && ch <= 'x'))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
		getchar(); // 处理\n
	}

	return 0;
}



// 5. 多组输入，一个整数（3~20）
// 输入4 输出：
// ****
// *  *
// *  *
// ****

// 中间都有
#include <stdio.h>

int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		int i = 0;
		for (i = 0; i < n; i++)
		{
			int j = 0;
			for (j = 0; j < n; j++)
			{
				printf("* ");
			}
			printf("\n");
		}
	}

	return 0;
}

// 空
int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		int i = 0;
		for (i = 1; i <= n; i++) // i=0 i<n
		{
			// 打印一行
			int j = 0;
			for (j = 1; j <= n; j++)
			{
				// 如果判断条件是从0开始 这里的下标就是i==1和i==n-1
				if (i == 1 || i == n || j == 1 || j == n)
				{
					printf("* ");
				}
				else
				{
					printf("  ");
				}
			}
			printf("\n");
		}
	}

	return 0;
}



// 6. 输入7个整数（0-100）
// 一行，输出去掉最高分和最低分的平均成绩，小数点后保留2位，每行输出后换行。
int main()
{
	int i = 0;
	int sc = 0;
	int sum = 0;
	int max = 0; // 假设0就是最高分
	int min = 100; // 假设100就是最低分

	for (i = 0; i < 7; i++)
	{
		scanf("%d", &sc);
		sum += sc;
		if (sc > max)
			max = sc;
		if (sc < min)
			min = sc;
	}

	double avg = (sum - max - min) / 5.0;

	printf("%.2lf\n", avg); // .2 保留两位小数点

	return 0;
}



// 7. 每一行输入三个a，b，c(0<a,b,c<1000)，作为三角形的三个边，用空格分隔。
// 针对每组输入数据，输出占一行，如果能构成三角形，等边三角形则输出“Equilateral triangle!”，
// 等腰三角形则输出“Isosceles triangle!”，其余的三角形则输出“Ordinary triangle!”，反之输出“Not a triangle!”。
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;

	//while (~scanf("%d %d %d", &a, &b, &c))
	// EOF是-1 -1补码是全1 按位取法是全0 不等于EOF就不会为0

	while (scanf("%d %d %d", &a, &b, &c) != EOF)
	{
		if ((a + b > c) && (a + c > b) && (b + c > a))
		{
			// 判断边
			if (a == b && b == c)
			{
				printf("Equilateral triangle!\n");
			}
			else if ((a == b && a != c) || (a == c && a != b) || (b == c && b != a))
			{
				printf("Isosceles triangle!\n");
			}
			else
			{
				printf("Ordinary triangle!\n");
			}
		}
		else
		{
			printf("Not a triangle!\n");
		}
	}

	return 0;
}



// 8
int main()
{
	int arr[] = { 1, 2, (3,4), 5 }; // 逗号表达式 1 2 4 5
	printf("%d\n", sizeof(arr));
	// 数组名表示整个数组 计算的是整个数组的大小 4个元素 每个元素是int 
	// 4*4 = 16
	return 0;
}


// sizeof计算的是内存占用空间的大小
// strlen求字符串长度 \0之前的字符


// 10.将数组A中的内容和数组B中的内容进行交换。（数组一样大）

// 数组传址解释
void test(int arr[], int sz) // 传的是地址
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		//printf("%d ", arr[i]); // arr[i] --->  *(arr+i)
		printf("%d ", *(arr + i));
	}
}

int main()
{
	int arr[10] = { 1, 2, 3, 4 ,5, 6, 7, 8, 9, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	test(arr, sz); // 数组传参过去的是数组的首元素的地址

	return 0;
}


void exchange(int a[], int b[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		int tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
	}
}

int main()
{
	int a[] = { 1, 3, 5, 7, 9 };
	int b[] = { 2, 4, 6, 8, 10 };
	int sz = sizeof(a) / sizeof(a[0]);
	exchange(a, b, sz);

	return 0;
}



#include <stdio.h>

int main()
{
	int arr1[10] = { 1, 2, 3, 4, 5 };
	int arr2[10] = { 6, 7, 8, 9, 10 };

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		int temp = 0;
		temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr2[i]);
	}

	return 0;
}



// 11. 创建一个整形数组，完成对数组的操作
//实现函数init() 初始化数组为全0
//实现print()  打印数组的每个元素
//实现reverse()  函数完成数组元素的逆置。
void Init(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		*(arr + i) = 0;
	}
}

void Print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

Reverse(int arr[], int sz)
{
	int l = 0; // 左下标
	int r = sz - 1; // 右下标

	while (l < r)
	{
		int tmp = arr[l];
		arr[l] = arr[r];
		arr[r] = tmp;
		l++;
		r--;
	}
}

int main()
{
	int arr[10];
	int sz = sizeof(arr) / sizeoff(arr[0]);
	Init(arr, sz); //初始化为全0   0-9
	Print(arr, sz); // 打印
	Reverse(arr, sz); // 逆置
	Print(arr, sz); // 逆置后再打印   9-0
	return 0;
}




// 下标引用、函数调用和结构成员
// []下标引用操作符
int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int i = 0;

	for (i = 0; i < 5; i++)
	{
		printf("%p ---- %p\n", &arr[i], arr + i);
		// &arr[i] 和 arr+i 打印的地址完全一样
		// arr+i - 就是数组arr中，下标为i的元素的地址
	}

	return 0;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int i = 0;
	//arr[4];  等价于*(arr+4)   
	// []是操作符 arr和4是两个操作数

	// arr[4] --- *(arr+4)
	// arr[4] ---> *(arr+4) ---> *(4+arr) ---> 4[arr]
	printf("%d\n", arr[4]);
	printf("%d\n", 4[arr]); // 可行 []仅仅是个操作符 

	return 0;
}


// 函数调用操作符 - ()

#include <string.h>

int main()
{
	// printf("%d", strlen("abc"));
	// strlen返回的是size_t --- unsigned int 无符号整型
	// %d打印的是有符号数 用%u
	printf("%u\n", strlen("abc"));

	return 0;
}


void test()
{
	printf("hehe\n");
}

int main()
{
	test();
	//  () - 函数调用操作符 接受一个或者多个操作数：第一个操作数是函数名，剩余的操作数就是传递给函数的参数

	return 0;
}


// . 结构体.成员名
// -> 结构体指针->成员名

// 自定义类型
// struct Book 结构体类型
// struct Book b 结构体变量
struct book // 结构体关键字 - struct
{
	char name[20];
	float price;
	char id[10];
};

void print1(struct book b)
{
	printf("书名：%s\n", b.name);
	printf("价格：%f\n", b.price);
	printf("书名：%s\n", b.id);
}

int main()
{
	struct book b = { "c语言程序设计", 55.5f, "c23479383" };
	print1(b);

	return 0;
}



// 改
int main()
{
	struct Book b = { "C语言程序设计", 55.5f, "C23479383" };
	Print1(b);

	b.price = 100.0f;// 可
	//b.name = "数据结构"; // err 
	//name是数组 数组名是常量的地址 应该放在地址所指向的空间里
	// 用==字符串拷贝 - strcpy==   库函数 头文件string.h
	strcpy(b.name, "数据结构");
	Print1(b);

	return 0;
}


// 传地址
struct Book
{
	char name[20];
	float price;
	char id[10];
};

void Print2(struct Book* pb) // 结构体指针接收
{
	printf("书名：%s\n", (*pb).name);
	printf("价格：%f\n", (*pb).price);
	printf("书名：%s\n", (*pb).id);
}

int main()
{
	struct Book b = { "C语言程序设计", 55.5f, "C23479383" };
	Print2(&b); // 传地址

	return 0;
}


// 结构体成员访问操作符
void Print2(struct Book* pb)
{
	// . 结构体.成员名
	//printf("书名：%s\n", (*pb).name);
	//printf("价格：%f\n", (*pb).price);
	//printf("书名：%s\n", (*pb).id);

	// -> 结构体指针->成员名
	printf("书名：%s\n", pb->name);
	printf("价格：%f\n", pb->price);
	printf("书名：%s\n", pb->id);

	// 左        右
	// 结构变量.成员名
	// 结构体指针->成员名

	// (*结构体指针).成员名   ---不常用
}



