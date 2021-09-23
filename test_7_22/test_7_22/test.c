#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// 1
int main()
{
	int y = 0;
	for (y = 1000; y <= 2000; y++)
	{
		// 判断y是否为闰年
		// 1. 能被4整除 不能被100整除
		// 2. 能被400整除是闰年
		if (y % 4 == 0 && y % 100 != 0)
			printf("%d ", y);
		else if (y % 400 == 0)
			// else可省略
			printf("%d ", y);
	}
	return 0;
}


// 2 err 错误
int main()
{
	int y = 0;
	for (y = 1000; y <= 2000; y++)
	{
		if (y % 4 == 0)
		{
			if (y % 100 != 0)
				printf("%d ", y);
		}
		else if (y % 400 == 0)
			printf("%d ", y);
	}
	return 0;
}


// 3
int main()
{
	int y = 0;
	for (y = 1000; y <= 2000; y++)
	{
		if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))
			printf("%d ", y);
	}

	return 0;
}


// 打印1-100的素数
int main()
{
	int i = 0;
	int count = 0;
	for (i = 100; i <= 200; i++)
	{
		// 判断是否为素数
		// 素数就是质数 - 只能被1和它本身整除的数字
		// 拿2-i-1之间的数字试除i
		int j = 0;
		int flag = 1;
		for (j = 2; j < i; j++)
		{
			// 拿j试除i
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			printf("%d ", i); // 素数打印
			count++;
		}
	}
	printf("\ncount = %d\n", count);

	return 0;
}


// 用平方比较 i=a*b 则a和b中至少有一个数字<=sqrt(i)    开平方
#include <stdio.h>
#include <math.h>

int main()
{
	int i = 0;
	int count = 0;
	// sqrt - 开平方的数学库函数
	for (i = 100; i <= 200; i++)
	{
		int j = 0;
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (j > sqrt(i))
		{
			count++;
			printf("%d ", i);
		}
	}
	printf("\ncount = %d\n", count);
	return 0;
}
// 优化 for (i = 101; i <= 200; i+=2) 排除所有偶数 提高效率
// 《素数求解的n种境界》


// 作业二 1.计算1-100多少个数字9  -- 有多少个9而不是有9的数字
#include <stdio.h>

int main()
{
	int i = 0;
	int count = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 10 == 9)
			count++;
		if (i / 10 == 9)
			count++;
	}
	// 9 19 29 39... 99十个 90 91 92... 99十个 
	printf("count = %d\n", count);
	return 0;
}


// 2. 分数求和 计算1/1 - 1/2 + 1/3 - 1/4 +1/5... +1/99 -1/100 的值
#include <stdio.h>

int main()
{
	int i = 0;
	double sum = 0.0;
	int flag = 1;
	for (i = 1; i <= 100; i++)
	{
		sum += flag * (1.0 / i);
		flag = -flag;
	}
	printf("%lf\n", sum);
	return 0;
}


// 3. 打印10个数中的最大值
int main()
{
	int arr[10] = { 0 };
	int i = 0;

	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &arr[i]);
	}

	int max = arr[0]; // 假设第一个元素就是最大值
	// 拿剩下的九个数字和max比较
	for (i = 0; i < 10; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	printf("%d\n", max);

	return 0;
}


#include <stdio.h>

int main()
{
	int arr[] = { -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 };
	int max = arr[0]; // 不能等于0 避免负数比较 从第一个数开始 
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 1; i < sz; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	printf("max = %d\n", max);
	return 0;
}


// 4. 在屏幕上输出9*9乘法口诀表
#include <stdio.h>

int main()
{
	int i = 0;
	for (i = 1; i <= 9; i++)
	{
		// 打印一行
		int j = 1;
		for (j = 1; j <= i; j++)
		{
			// 打印一项
			printf("%d*%d=%-2d ", i, j, i * j); // -2左对齐
		}
		printf("\n");
	}
	return 0;
}