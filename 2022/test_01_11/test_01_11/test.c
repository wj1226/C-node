#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//int main()
//{
//	int arr[10] = { 0 };
//	char* p = arr;
//	for (int i = 0; i < 40; i++)
//	{
//		*(p + i) = 1;
//	}
//	int* t = arr;
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", *(t + i));
//	}
//
//	int c = 3;
//	printf("\n%d\n", c + --c);
//
//	int a = 0x11223344;
//	printf("%d", a);
//
//	return 0;
//}

//struct Book
//{
//	char name[20];
//	double age;
//	char id[20];
//};
//
//int main()
//{
//	struct Book b = { "C语言", 50.3, "123" };
//	strcpy(b.name, "Java");
//	printf("%s\n", b.name);
//
//	struct Book *pb = &b;
//	printf("%.1lf", pb->age);
//
//	return 0;
//}

//void exchange(int* a, int* b, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		int tmp = *(a+i);
//		*(a+i) = *(b+i);
//		*(b+i) = tmp;
//	}
//}
//
//void print(int* a, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *(a + i));
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int a[] = { 1,2,3,4,5 };
//	int b[] = { 6,7,8,9,0 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	exchange(a, b, sz);
//	print(a, sz);
//	print(b, sz);
//}

//int main()
//{
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			if (i == 0 || i == 3 || j == 0 || j == 3) {
//				printf("* ");
//			} else {
//				printf("  ");
//			}
//		}
//		printf("\n");
//	}
//
//	int arr[][3] = { {1,2,3}, {1}, {5,6} };
//
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	int b = (a++) + (a++) + (a++);
//	int g = 1;
//	int f = (g++) + (g++);
//	printf("g = %d  f = %d\n", g, f);
//	printf("a = %d  b = %d\n", a, b);
//
//	int i = 1;
//	int k = (++i) + (++i) + (++i);
//	printf("i = %d  k = %d\n", i, k);
//
//	int h = 1;
//	int w = (++h) + (++h);
//	printf("h = %d  w = %d", h, w);
//
//	return 0;
//}

//int main()
//{
//	int a = 15;
//	// 00000000000000000000000000001111
//	// 11111111111111111111111111110000 - ~a
//	// 11111111111111111111111111101111 - 反
//	// 10000000000000000000000000010000 - 补  2^4=16 -> -16
//	int b = ~a;
//	printf("%d\n", b);
//	return 0;
//}
//
//int main6()
//{
//	int arr3[][5] = { {1, 2}, {3, 4}, {5, 6} };
//	return 0;
//}
//
//int main5()
//{
//	char arr[20] = { 0 };
//	scanf("%s", arr);
//	printf("%s\n", arr);
//
//	getchar();
//
//	char str[20] = { 0 };
//	gets(str);
//	printf("%s\n", str);
//	return 0;
//}
//
//void test(int* px, int* py)
//{
//	*px = 10;
//	*py = 20;
//}
//
//int main4()
//{
//	int x = 0;
//	int y = 0;
//	test(&x, &y);
//	printf("%d %d", x, y);
//	return 0;
//}
//
//char* fun(char* s, char* t) 
//{
//	char* s1 = s;
//	char* t1 = t;
//	while (*s1++ != '\0' && *t1++ != '\0') {
//		;
//	}
//	if (*s1 != '\0' || (*s1 == '\0' && *t1 == '\0'))
//	{
//		return s;
//	}
//	else 
//	{
//		return t;
//	}
//}
//
//int main3()
//{
//	char* s = "abcsg";
//	char* t = "abcde";
//	printf("%s\n", fun(s, t));
//
//	return 0;
//}
//
//#define ADD(X, Y) ( (X) + (Y) )
//
//#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
//
//int main2()
//{
//	int a = 5;
//	int b = 7;
//	int max = MAX(a, b);
//	printf("max = %d\n", max);
//
//	int sum = ADD(100, 10);
//	printf("sum = %d\n", sum);
//
//	return 0;
//}
//
//int main1()
//{
//	char arr[] = { 'a', 'b', 'c', 'd', 'e', '\0'};
//	char arr2[] = { 'a', 'b', 'c', 'd', 'e'};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("%d\n", sz); // 6
//
//	int len = strlen(arr);
//	printf("%d\n", len); // 5
//
//	printf("%s\n", arr); // abcde
//	printf("%s\n", arr2); // abcde随机数。。。
//
//	int arr3[20] = { 0 };
//	int sz2 = sizeof(arr3) / sizeof(arr3[0]);
//	printf("%d\n", sz2);
//	printf("%d\n", sizeof(arr3));
//
//	
//	return 0;
//}
