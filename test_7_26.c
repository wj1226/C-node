// 分支与循环getchar

// 代码是什么意思
// 代码1

#include <stdio.h>

// getchar - 函数 - 从键盘读取字符的（单个字符）

// getchar 是读取字符 
// 为甚么返回类型是int？
// 1. getchar 既然返回的是字符 其实返回的是找私服的ASCII码值 因为ASCII是整数 所以返回int
// 2. getchar 在读取结束或失败的时候 会返回EOF
//    EOF - end of file  ->  -1
//    -1是整数 而ASCII码范围没有整数

// 结束代码 -> Ctrl+Z 回车
int main()
{
	int ch = 0;

	while ((ch = getchar()) != EOF)
	{
		putchar(ch);
	}

	return 0;
}



// 2. getchar读取密码
int main()
{
	char password[20] = { 0 };

	printf("请输入密码:>");
	scanf_s("%s", password, 20);

	printf("请确认密码(Y/N):>");
	int ch = getchar();

	if (ch == 'Y')
	{
		printf("确认成功\n");
	}
	else
	{
		printf("确认失败\n");
	}

	return 0;
}
// 请确认密码(Y/N):>确认失败
// 
// 输入函数scanf和getchar 首先在缓冲区里看 如果有 就不用键盘输入
// 缓冲区是空的 键盘输入字符到缓冲区 此时缓冲区有abcdef\n
// scanf读取 abcdef
// getchar 读取\n 

// 把缓冲区的\n清理掉(只能清除一个\n)
int main()
{
	char password[20] = { 0 };

	printf("请输入密码:>");
	scanf_s("%s", password, 20);

	// 把缓冲区的\n清理掉
	getchar();

	printf("请确认密码(Y/N):>");
	int ch = getchar();

	if (ch == 'Y')
	{
		printf("确认成功\n");
	}
	else
	{
		printf("确认失败\n");
	}

	return 0;
}


// 如果输入abcdef fiok 还是“请确认密码(Y/N):>确认失败”
// 因为scanf只读取到abcdef
int main()
{
	char password[20] = { 0 };

	printf("请输入密码:>");
	scanf_s("%s", password, 20);

	// 把缓冲中的内容
	int tmp = 0;
	while (tmp = getchar() != '\n')
	{
		;
	}

	printf("请确认密码(Y/N):>");
	int ch = getchar();

	if (ch == 'Y')
	{
		printf("确认成功\n");
	}
	else
	{
		printf("确认失败\n");
	}

	return 0;
}

// gets - 直接读一行



// 只打印数字
int main()
{
	int ch = 0;

	while ((ch = getchar()) != EOF)
	{
		if (ch < '0' || ch>'9')
			continue;
		putchar(ch);
	}

	return 0;
}




// 作业
// 1. 能把函数处理结果的二个数据返回给主调函数

// return 2个值（err） 

// 一个函数只能返回一个结果 return a,b 结果是20 -> 逗号表达式
int test()
{
	int a = 10;
	int b = 20;
	return a, b; // err
}

int main()
{
	int ret = test();
	printf("%d\n", ret);

	return 0;
}



// 形参用数组
void test(int arr[])
{
	int a = 10;
	int b = 20;

	arr[0] = a;
	arr[1] = b;
}

int main()
{
	int arr[2] = { 0 };
	test(arr);
	
	printf("%d %d\n", arr[0], arr[1]);

	return 0;
}



// 形参用2个指针
void test(int* px, int* py)
{
	int a = 10;
	int b = 20;
	*px = a;
	*py = b;
}

int main()
{
	int x = 0;
	int y = 0;

	test(&x, &y);

	printf("%d %d\n", x, y);

	return 0;
}



// 用2个全局变量
int x = 0;
int y = 0;

void test()
{
	int a = 10;
	int b = 20;

	x = a;
	y = b;
}

int main()
{

	test();

	printf("%d %d\n", x, y);

	return 0;
}



// 2
// 高内聚低耦合：自己把自己的事情做好，尽量不和别人产生关联


// 在一个函数内复合语句中定义的变量在本函数范围内有效（复合语句指函数中的成对括号构成的代码）
void test()
{
	{
		int a = 10;
	}
	printf("a=%d\n", a); // err
}

int main()
{
	return 0;
}




// 3.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
void print_table(int n)
{
	int i = 0;

	for (i = 1; i <= n; i++)
	{
		int j = 0;

		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%-2d ", i, j, i * j);
		}
		printf("\n");
	}
}

int main()
{
	int n = 0;
	scanf_s("%d", &n);

	print_table(n);

	return 0;
}




// 4.字符串逆序（1.递归实现 2.不能使用C函数库中的字符串操作函数）

// 用函数循环
 #include <string.h>

void  reverse_string(char* str)
{
	// 用指针
	// char* left = str;
	// char* right = str + len - 1;

	// 用下标
	int len = strlen(str);

	int left = 0;
	int right = len - 1;

	while (left < right)
	{
		char tmp = str[left];
		str[left] = str[right];
		str[right] = tmp;
		left++;
		right--;
	}
}

int main()
{
	char arr[20] = "abcdef";

	reverse_string(arr);

	printf("%s\n", arr); // fedcba

	return 0;
}



// 递归版本
int my_strlen(char* str)
{
	// 不能使用库函数 用my_strlen函数计数器求字符串
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

void  reverse_string(char* str) // char str[]
{
	int len = my_strlen(str); // 求字符串长度
	char tmp = str[0]; // *str  把a 放进tmp
	str[0] = str[len - 1]; // 把f 放进a
	str[len - 1] = '\0'; // 将\0 放进f

	if (my_strlen(str + 1) >= 2)
		reverse_string(str + 1);
	str[len - 1] = tmp; // 出递归 把tmp 放进\0
}

int main()
{
	char arr[20] = "abcdef";

	reverse_string(arr);

	printf("%s\n", arr);

	return 0;
}




// 5.计算一个数的每位之和（递归实现 非负整数）
int DigitSum(unsigned int n)
{
	if (n > 9)
	{
		return DigitSum(n / 10) + n % 10;
	}
	else
	{
		return n;
	}
}

int main()
{
	unsigned int num = 1729;

	int ret = DigitSum(num);
	
	printf("%d\n", ret);

	return 0;
}




// 6.递归实现n的k次方
// Pow(n, k)  当k>0 -> n*Pow(n, k-1)
// 当k=0 -> 1  当k<0 -> 1.0/n^-k -> 1.0/Pow(n, -k)
double Pow(int n, int k)
{
	if (k > 0)
		return n * Pow(n, k - 1);
	else if (k == 0)
		return 1.0;
	else
		return 1.0 / Pow(n, -k);
}

int main()
{
	int n = 2;
	int k = -3;
	double ret = Pow(n, k);

	printf("%lf\n", ret);

	return 0;
}