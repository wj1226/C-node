#include <stdio.h>

// 写代码将三个整数数按从大到小输出
// 输入：2 3 1
// 输出：3 2 1
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	// 输入
	scanf_s("%d %d %d", &a, &b, &c);

	// 调整
	int tmp = 0;

	if (a < b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}

	if (a < c)
	{
		tmp = a;
		a = c;
		c = tmp;
	}

	if (b < c)
	{
		tmp = b;
		b = c;
		c = tmp;
	}

	// 输出
	printf("%d %d %d", a, b, c);

	return 0;
}


// 写一个代码打印1 - 100之间所有3的倍数的数字
int main()
{
	int i = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
		{
			printf("%d ", i);
		}
	}

	printf("\n");

	for (i = 3; i <= 100; i += 3)
	{
		printf("%d ", i);
	}

	return 0;
}


// 给定两个数，求这两个数的最大公约数
// 1. 暴力求解
int main()
{
	int a = 0;
	int b = 0;
	scan_s("%d %d", &a, &b);

	// 求两个数的最大公约数
	// 假设a和b就是最大公约数
	int m = (a > b ? b : a);
	
	while (1)
	{
		if (a % m == 0 && b % m == 0)
		{
			printf("最大公约数是：%d\n", m);
			break;
		}
		m--;
	}

	return 0;
}


// 2. 辗转相除法
int main()
{
	int a = 0;
	int b = 0;
	scanf_s("%d %d", &a, &b);

	int r = 0;
	while (a % b)
	{
		r = a % b;
		a = b;
		b = r;
	}

	printf("%d\n", b);

	return 0;
}
 
// 最小公倍数：a * b / 最大公约数 