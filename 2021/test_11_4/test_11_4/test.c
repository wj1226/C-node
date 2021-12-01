#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>

 /*
 * 等边三角形则输出“Equilateral triangle!”，等腰三角形则输出“Isosceles triangle!”，
 其余的三角形则输出“Ordinary triangle!”，反之输出“Not a triangle!”
 */
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	while (~(scanf("%d %d %d", &a, &b, &c)))
//	{
//		if (a + b > c && a + c > b && c + b > a)
//		{
//			if (a == b && a == c)
//				printf("Equilateral triangle!\n");
//			else if((a==b&&a!=c) || (a==c&&a!=b) || (b==c&&b!=a))
//				printf("Isosceles triangle!\n");
//			else
//				printf("Ordinary triangle!\n");
//		}
//		else
//		{
//			printf("Not a triangle!\n");
//		}
//	}
//
//	return 0;
//}


//int main()
//{
//	char ch = 0;
//	while (~(scanf(" %c", &ch)))
//	{
//		if (isupper(ch))
//		{
//			printf("%c\n", tolower(ch));
//		}
//		if(islower(ch))
//		{
//			printf("%c\n", toupper(ch));
//		}
//	}
//
//	return 0;
//}

//int main()
//{
//	char ch = 0;
//	while (~(scanf(" %c", &ch)))
//	{
//		if (isalpha(ch))
//		{
//			printf("%c is an alphabet.\n", ch);
//		}
//		else
//		{
//			printf("%c is not an alphabet.\n", ch);
//		}
//	}
//
//	return 0;
//}

//int main()
//{
//	char ch = 0;
//	char vowel[] = "aeiouAEIOU";
//	while (~(scanf(" %c", &ch)))
//	{
//		if (strchr(vowel, ch))
//		{
//			printf("Vowel\n");
//		}
//		else
//		{
//			printf("Consonant\n");
//		}
//	}
//
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	while (~(scanf("%d", &n)))
//	{
//		if (n % 2 == 1)
//		{
//			printf("Odd\n");
//		}
//		else
//		{
//			printf("Even\n");
//		}
//	}
// 
// 	int a = 7; 
//float x = 2.5, y = 4.7;
//printf("%lf", x + a % 3 * (int)(x + y) % 2 / 4);
//
//	return 0;
//}

