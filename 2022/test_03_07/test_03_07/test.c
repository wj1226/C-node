#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

void Fib(int n)
{
	int f1 = 1;
	int f2 = 1;
	int f3 = 1;
	while (n > 2)
	{
		printf("%d ", f3);
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
		n--;
	}
}

int main()
{
	int n = 10;
	Fib(n);
	return 0;
}

//int main()
//{
//	char des[] = "xxxxxxxxxxxxx";
//	//char src[] = "abc";
//	//strcpy(des, src);
//
//	char* ret = (char*)memset(des, 'a', 5);
//	printf("%s\n", ret);
//}

//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//
//	while (1)
//	{
//		printf("一分钟内关机, 输入1024 取消关机\n");
//		printf("请输入：");
//		scanf("%s", input);
//		if (strcmp(input, "1024") == 0)
//		{
//			system("shutdown -a");
//			break;
//		}
//	}
//
//	return 0;
//}

//int main()
//{
//	for (int i = 101; i <= 200; i += 2)
//	{
//		int j = 2;
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (j > sqrt(i)) 
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}


//int main()
//{
//	int a = 24;
//	int b = 16;
//	int c = a % b;
//	while (c != 0) 
//	{
//		a = b;
//		b = c;
//		c = a % b;
//	}
//	printf("%d\n", b);
//}

//void menu()
//{
//	printf("****************************\n");
//	printf("*******    1. game   *******\n");
//	printf("*******    0. exit   *******\n");
//	printf("****************************\n");
//}
//
//void game()
//{
//	int ret = rand() % 100 + 1; // 1 - 100
//	while (1)
//	{
//		int guess = 0;
//		printf("请输出猜的数字：");
//		scanf("%d", &guess);
//		if (ret > guess)
//		{
//			printf("猜小了\n");
//		}
//		else if (ret == guess) 
//		{
//			printf("猜对了\n");
//			break;
//		}
//		else {
//			printf("猜大了\n");
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出\n");
//			break;
//		default :
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}

//int main()
//{
//	printf("123\t12\n");	
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int ret = 1;
//	int sum = 0;
//	for (int i = 1; i <= n; i++) {
//		ret *= i;
//		sum += ret;
//	}
//	printf("%d\n", ret);
//	printf("%d\n", sum);
//
//	return 0;
//}


