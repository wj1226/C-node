#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	int a = 5;
//	if (a = 0)
//		printf("%d", a - 10);
//	else
//		printf("%d", a++);
//
//	return 0;
//}

//int main()
//{
//	double** a[3][4];
//	int sz = sizeof(a) / sizeof(a[0][0]);
//
//	printf("%d", sz);
//
//	return 0;
//}

//int main()
//{
//	int i = 1, sum = 0;
//	while (i < 10) {
//		sum = sum + 1;
//		i++;
//	}
//	printf("i=%d, sum=%d\n", i, sum);
//	return 0;
//}
//123458910
//1234589

//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int number = 5 * sqrt(5 * 5) - 1;
//	printf("%d\n", number);
//
//	return 0;
//}
//
//int main()
//{
//	int i = 1;
//	if (i)
//		printf("2");
//	printf("3");
//
//	return 0;
//}


//猜数字
//#include <stdlib.h>
//#include <time.h>
//
//void menu()
//{
//	printf("*******************************************\n");
//	printf("**********       1. play        ***********\n");
//	printf("**********       0. exit        ***********\n");
//	printf("*******************************************\n");
//}
//
//void game()
//{
//	int ret = rand() % 100 + 1;
//	int guess = 0;
//	while (1)
//	{
//		printf("请选择数字:>");
//		scanf("%d", &guess);
//		if (guess > ret)
//			printf("猜大了\n");
//		else if (guess < ret)
//			printf("猜小了\n");
//		else
//		{
//			printf("恭喜你，猜对了!\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏！\n");
//			break;
//		default:
//			printf("选择错误，请重新选择:>\n");
//			break;
//		}
//
//	} while (input);
//
//	return 0;
//}

#include <string.h>
//
//int main()
//{
//	char arr[] = "hello bit";
//	char* ret = memset(arr, 'x', 6);
//	printf("%s", ret);
//	return 0;
//}

//int main()
//{
//	char arr1[20] = "xxxxxxxxxxxx";
//	char arr2[] = "hello";
//	char* ret = strcpy(arr1, arr2);
//	printf("%s\n", ret);
//	int len = strlen(arr1);
//	printf("%d\n", len);
//
//	return 0;
//}


//#include <math.h>
//
//int is_prime(int n)
//{
//	int j = 0;
//	for (j = 2; j <= sqrt(n); j++)
//	{
//		if (n % j == 0)
//			return 0;
//	}
//	return 1;
//}
//
//int main()
//{
//	int i = 0;
//	for (i = 2; i <= 100; i++)
//	{
//		if (is_prime(i) == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int ret = 1;
//	int sum = 0;
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//		sum += ret;
//	}
//	printf("%d %d\n", ret, sum);
//	return 0;
//}













