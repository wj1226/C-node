#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//void menu()
//{
//	printf("*****************************************\n");
//	printf("**********      1. play       **********\n");
//	printf("**********      0. exit       ***********\n");
//	printf("*****************************************\n");
//}
//
//void game()
//{
//	char mine[ROWS][COLS] = { 0 };
//	char show[ROWS][COLS] = { 0 };
//
//	InitBoard(mine, ROWS, COLS, '0');
//	InitBoard(show, ROWS, COLS, '*');
//
//	// DisplayBoard(mine, ROW, COL);
//	DisplayBoard(show, ROW, COL);
//
//	SetMine(mine, ROW, COL);
//
//	FindMine(mine, show, ROW, COL);
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("Please choose:");
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("exit the game\n");
//			break;
//		default:
//			printf("Choose wrong, choose again please!\n");
//			break;
//		}
//
//	} while (input);
//
//	return 0;
//}



//int main()
//{
//	int n = 0;
//	int i = 0;
//	char gender = 0;
//	double height = 0.0;
//	scanf("%d", &n);
//	getchar();
//	for (i = 0; i < n; i++)
//	{
//		scanf("%c %lf", &gender, &height);
//		getchar();
//		if (gender == 'M') {
//			printf("%.2lf\n", height / 1.09);
//		}
//		else {
//			printf("%.2lf\n", height * 1.09);
//		}
//	}
//
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	int count = 1;
//	while (1)
//	{
//		scanf("%d", &n);
//		if (n == 250)
//			break;
//		count++;
//	}
//	printf("%d", count);
//	return 0;
//}


//int main()
//{
//    int day = 0;
//    int month = 0;
//    int year = 0;
//    scanf("%02d-%02d-%04d", &month, &day, &year);
//    printf("%04d-%02d-%02d", year, month, day);
//
//    return 0;
//}

//int main()
//{
//    char planet[7] = { 0 };
//    scanf("%s", &planet);
//    printf("Hello %s", planet);
//
//    return 0;
//}


//int main()
//{
//    int n = 0;
//    char name[3] = { 0 };
//    int rate = 0;
//    int beat = 0;
//    scanf("%d", &n);
//    while (n--)
//    {
//        scanf("%s %d %d", &name, &rate, &beat);
//        if ((rate >= 15) && (rate <= 20) && (beat >= 50) && (beat <= 70))
//        {
//            ;
//        }
//        else
//        {
//            printf("%s\n", name);
//        }
//    }
//
//    return 0;
//}


//int main()
//{
//    int money = 0;
//    int discount = 0;
//    scanf("%d %d", &money, &discount);
//    double price = money * discount / 10.0;
//    printf("%.2lf", price);
//
//    return 0;
//}
//
//int main()
//{
//    printf("2018\nwo3 men2 yao4 ying2 !");
//    return 0;
//}


//int main()
//{
//    int a = 0;
//    int b = 0;
//    scanf("%d %d", &a, &b);
//    int c = a + b;
//    while (c--)
//    {
//        printf("Wang!");
//    }
//    return 0;
//}


//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	double weight = 0.0;
//	double height = 0.0;
//	scanf("%lf %lf", &weight, &height);
//	double num = weight / pow(height, 2);
//	if (num > 25)
//	{
//		printf("%.1lf\nPANG", num);
//	}
//	else
//	{
//		printf("%.1lf\nHai Xing", num);
//	}
//
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	int num = 0;
//	scanf("%d", &n);
//	while (n--)
//	{
//		int i = 0;
//		scanf("%d", &num); // 233088
//		int tmp = num; // 233088
//		int tmp2 = num / 1000; // 233
//		int sum1 = 0;
//		int sum2 = 0;
//		for (i = 0; i < 3; i++) // 后3位数和
//		{
//			sum1 += tmp % 10;
//			tmp /= 10;
//		}
//		for (i = 0; i < 3; i++) // 前3位数和
//		{
//			sum2 += tmp2 % 10;
//			tmp2 /= 10;
//		}
//		if (sum1 == sum2)
//			printf("You are lucky!\n");
//		else
//			printf("Wish you good luck.\n");
//	}
//
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	int height = 0;
//	int weight = 0;
//	int gender = 0;
//	scanf("%d", &n);
//	while (n--)
//	{
//		scanf("%d %d %d", &gender, &height, &weight);
//
//		if (gender == 1)
//		{
//			if (height > 130)
//				printf("ni li hai! ");
//			else if (height < 130)
//				printf("duo chi yu! ");
//			else
//				printf("wan mei! ");
//			if (weight > 27)
//				printf("shao chi rou!");
//			else if (weight < 27)
//				printf("duo chi rou!");
//			else
//				printf("wan mei!");
//			printf("\n");
//		}
//		if (gender == 0)
//		{
//			if (height > 129)
//				printf("ni li hai! ");
//			else if (height < 129)
//				printf("duo chi yu! ");
//			else
//				printf("wan mei! ");
//			if (weight > 25)
//				printf("shao chi rou!");
//			else if (weight < 25)
//				printf("duo chi rou!");
//			else
//				printf("wan mei!");
//			printf("\n");
//		}
//			
//	}
//
//	return 0;
//}



//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//    int weight = 0;
//    int high = 0;
//    double bmi = 0.0;
//    scanf("%d %d", &weight, &high);
//
//    //bmi = weight/((high/100.0)*(high/100.0));
//    bmi = weight / (pow((high/100.0), 2));
//
//    printf("%.2lf\n", bmi);
//
//    return 0;
//}



int main()
{
	char* a[] = { "work", "at", "alibaba" };
	char** pa = a;
	pa++;
	printf("%s\n", *pa);

	return 0;
}