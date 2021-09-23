#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// for循环
// 初始化 判断 调整

// 打印1-10
int main()
{
	int i = 0;
	for (i = 1; i <= 10; i++)
	{
		printf("%d ", i);
	}
	return 0;
}


// F10 - 单步执行（逐过程）
// F11 - 单步执行（逐语句） - 遇到自定函数，想进入函数，按F11


int main()
{
	int i = 0;
	for (i = 1; i <= 10; i++)
	{
		if (5 == i)
			continue;
		printf("%d ", i); // 1 2 2 4 6 7 8 9 10
	}
	return 0;
}
// for循环中的continue跳过continue后边的代码
// 去了调整部分，调整循环变量，不容易造成死循环

// whlie循环中，continue跳过continue后边的代码，直接去判断部分


// for语句的循环控制变量
// 1. 不可再for循环体内修改循环变量，防止for循环失去控制
int main()
{
	int i = 0;
	for (i = 1; i <= 10; i++)
	{
		if (i == 5)
			printf("%d ", i);
	}
	return 0;
}

// 2. 建议for语句的循环控制变量的取值采用“前闭后开区间”写法
int main()
{
	int arr[10] = { 0 };
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}


// for循环的一些变种
// 1. 初始化 判断 调整 三个部分都省略了
int main()
{
	int i = 0;
	for (;;)
	{
		printf("hehe\n"); // 死循环
		// 1. 可以省略
		// 2. 判断部分只要省略了，就意味着判断恒为“真”
		// 3. 尽量不要省略
	}
	return 0;
}


int main()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 10; i++)
	{
		for (; j < 10; j++)
		{
			printf("hehe\n");
		}
		// i=0 j=0 打印10个hehe 跳出 此时j=10 不进入 只打印10hehe
	}
	return 0;
}


// 一道笔试题
int main()
{
	int i = 0;
	int k = 0;
	for (i = 0, k = 0; k = 0; i++, k++)
		// 判断赋值为0 假
		k++;
	return 0;
}


// do...while循环
int main()
{
	int i = 1;

	do
	{
		printf("%d", i);
		i++;
	} while (i <= 10);

	return 0;
}


int main()
{
	int i = 1;

	do
	{
		if (i == 5)
			break;
		printf("%d ", i); // 1 2 3 4
		i++;
	} while (i <= 10);

	return 0;
}


int main()
{
	int i = 1;

	do
	{
		if (i == 5)
			continue;
		printf("%d ", i); // 1 2 3 4 死循环
		i++;
	} while (i <= 10);

	return 0;
}


// 练习
// 1. 计算n的阶乘
int main()
{
	int n = 0;
	scanf("%d", &n);

	int i = 0;
	int ret = 0;
	for (i = 1; i < n; i++)
	{
		ret = ret * i;
	}

	printf("%d", ret);

	return 0;
}


// 2. 计算1！+2！+3！+...+10!
int main()
{
	int i = 0;
	int ret = 1;
	int sum = 0;

	for (i = 1; i <= 10; i++)
	{
		ret = ret * i;
		sum = sum + ret;
	}

	printf("%d", sum);

	return 0;
}


// 3. 在一个有序数组中查找具体的某个数字n
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	// 在有序数组arr中找7
	// 找到了打印下标，找不到打印：找不到
	int i = 0;
	int k = 7;

	// 求数组的元素个数
	int sz = sizeof(arr) / sizeof(arr[0]);

	for (i = 0; i < sz; i++)
	{
		if (arr[i] == k)
		{
			printf("找到了，下标是：%d\n", i);
			break;
		}
	}

	if (i == sz)
	{
		printf("找到了\n");
	}

	return 0;
}


// 折半查找法/二分
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = sz - 1;
	int k = 7;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else
		{
			printf("找到了，下标是：%d\n", mid);
			break;
		}
	}

	if (left > right)
	{
		printf("找不到\n");
	}
	return 0;
}


// 4. 演示一段字符从两端移动 向中间汇聚
#include <stdlib.h>
#include <windows.h>
#include <string.h>

int main()
{
	char arr1[] = "hello world!!!";
	char arr2[] = "##############";
	int len = strlen(arr1);

	int left = 0;
	int right = len - 1;

	while (left <= right)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s\n", arr2);
		Sleep(1000); // 1000毫秒=1s
		system("cls");	// 清空屏幕
		// system是库函数，用来执行系统命令的
		left++;
		right--;
	}
	printf("%s\n", arr2);

	return 0;
}


// 5. 模拟用户登录情景 并且只能登录三次（三次正确提示登录成功，错误退出程序）
#include <string.h>

int main()
{
	int i = 0;
	char password[20] = { 0 };
	// 假设密码是 abcdef

	for (i = 0; i < 3; i++)
	{
		printf("请输入密码:>");
		scanf("%s", password);

		// 两个字符串比较，不能使用==
		if (strcmp(password, "abcdef") == 0)
		{
			printf("登录成功\n");
			break;
		}
		else
		{
			printf("密码错误!\n");
		}
	}

	if (i == 3)
	{
		printf("三次密码输入错误，退出程序\n");
	}

	return 0;
}


// C语言规定 变量要创建在当前代码块的前面


// goto语句
int main()
{
again:
	printf("hehe\n"); // 死循环
	goto again;

	return 0;
}


// goto可用于跳出深层嵌套循环


// 关机程序
// 程序运行起来倒计时关机，1分钟内输入“我是猪”，取消关机
int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 60");

again:
	printf("请注意，你的电脑在1分钟内关机，如果输入：我是猪，就取消关机\n");
	scanf("%s", input);

	if (strcmp(input, "我是猪") == 0)
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}

	return 0;
}


int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 60");

	while (1)
	{
		printf("请注意，你的电脑在1分钟内关机，如果输入：我是猪，就取消关机\n");
		scanf("%s", input);

		if (strcmp(input, "我是猪") == 0)
		{
			system("shutdown -a");
			break;
		}
	}

	return 0;
}