#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// 分支语句和循环语句

// if语句
int main()
{
	// 语句：一个分号隔开就是一条语句
	; // 空语句
	return 0;
}


int main()
{
	int age = 25;

	if (age < 18)
		printf("青少年\n");
	else if (age >= 18 && age < 30)
		printf("青年\n");
	else if (age >= 30 && age < 50)
		printf("中年\n");
	else if (age >= 50 && age < 80)
		printf("老年\n");
	else
		printf("老寿星\n");

	return 0;
}


// 0为假 非0为真

// 条件成立，要执行多条语句，使用代码块{}


// 悬空else
int main()
{
	int a = 0;
	int b = 2;
	// 不打印
	if (a == 1)
		if (b == 2)
			printf("hehe\n");
		else
			printf("haha\n");
	return 0;
}


// 书写规范
int main()
{
	int num = 3;
	// 常量和变量比较相等的时候
	// 常量放在左边更好一些
	if (5 == num)
	{
		printf("hehe\n");
	}
	return 0;
}


// 判断一个数是否为奇数
int main()
{
	int num = 0;
	scanf("%d", &num);
	if (num % 2 == 1)
	{
		printf("%d是奇数\n", num);
	}
	else
	{
		printf("%d不是奇数\n", num);

	}
	return 0;
}


// 输出1-100的奇数
int main()
{
	int i = 0;
	while (i <= 100)
	{
		if (i % 2 == 1)
			printf("%d ", i);
		i++;
	}
	return 0;
}


// 数字方法
int main()
{
	int i = 1;
	while (i <= 100)
	{
		printf("%d ", i);
		i += 2;
	}
	return 0;
}


// switch语句
// switch后跟整型表达式
// case后整形常量表达式。不能是变量，可以是字符'a'
int main()
{
	int day = 0;
	scanf("%d", &day);

	switch (day)
	{
	case 1:
		printf("星期1\n");
		break; // break 停止
	case 2:
		printf("星期2\n");
		break;
	}
	return 0;
}


int main()
{
	int day = 0;
	scanf("%d", &day);

	switch (day)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("工作日\n");
		break;
	case 6:
	case 7:
		printf("休息日\n");
		break;
	// default 没有顺序
	default:
		printf("输入错误，请输入1-7的数字\n");
		break;
	}
	return 0;
}


// 练习
int main()
{
	int n = 1;
	int m = 2;
	switch (n)
	{
	case 1:
		m++;
	case 2:
		n++;
	case 3:
		switch (n)
		{
		// switch允许嵌套使用
		case 1:
			n++; // 
		case 2:
			m++;
			break;
		}
	case 4:
		m++;
		break;
	default:
		break;
	}
	printf("m = %d, n = %d\n", m, n); // 5 3
	return 0;
}


// 循环语句
// while
int main()
{
	while (1)
	// 死循环 恒为真
	{
		printf("hehe\n");
	}
	return 0;
}


// while打印1-10
int main()
{
	int i = 1;
	while (i <= 10)
	{
		printf("%d ", i);
		i++;
	}
	return 0;
}


int main()
{
	int i = 1;
	while (i <= 10)
	{
		if (5 == i)
			break;
		printf("%d", i);
		i++;
	}
	// 1 2 3 4
	// braek是永久的终止循环的
	return 0;
}


int main()
{
	int i = 1;
	while (i <= 10)
	{
		if (5 == i)
			continue;
		printf("%d", i);
		i++;
	}
	// 1 2 3 4 死循环
	// continue作用：
	// 跳过本次循环continue后边的代码，直接来到while循环的判断部分
	return 0;
}


int main()
{
	int i = 1;
	while (i <= 10)
	{
		i++;
		if (5 == i)
			continue;
		printf("%d", i); // 2 3 4 6 7 8 9 10 11
	}
	return 0;
}


// getchar - 从键盘获取字符
// putchar - 把字符打印到屏幕
int main()
{
	int ch = 0;

	ch = getchar();
	putchar(ch);

	return 0;
}


int main()
{
	int ch = 0;
	// EOF - end of file - 文件结束的标志
	// ctrl+z 停止

	// getchar读取失败时会返回EOF
	// 1. 返回的字符，本质上是字符也是ASCII码值，是整数
	// 2. getchar函数不仅仅是返回正常
	while ((ch = getchar()) != EOF)
	{
		putchar(ch);
	}
	return 0;
}


int main()
{
	int ch = 0;
	char password[20] = { 0 };
	printf("请输入密码>:");
	scanf("%s", password);
	// 清理
 	// getchat(); // 不可取
	while ((ch = getchar()) != '\n');

	printf("请确认密码(Y/N)>:");
	ch = getchar();
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


int main()
{
	int ch = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch < '0' || ch > '9')
		// 0-47和58-127的ASCII码值不打印
		// 专门打印数字
			continue;
		putchar(ch);
	}
	return 0;
}