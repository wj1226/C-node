#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int arr3[][5] = { {1, 2}, {3, 4}, {5, 6} };
}

int main5()
{
	char arr[20] = { 0 };
	scanf("%s", arr);
	printf("%s\n", arr);

	getchar();

	char str[20] = { 0 };
	gets(str);
	printf("%s\n", str);
}

void test(int* px, int* py)
{
	*px = 10;
	*py = 20;
}

int main4()
{
	int x = 0;
	int y = 0;
	test(&x, &y);
	printf("%d %d", x, y);
	return 0;
}

char* fun(char* s, char* t) 
{
	char* s1 = s;
	char* t1 = t;
	while (*s1++ != '\0' && *t1++ != '\0') {
		;
	}
	if (*s1 != '\0' || (*s1 == '\0' && *t1 == '\0'))
	{
		return s;
	}
	else 
	{
		return t;
	}
}

int main3()
{
	char* s = "abcsg";
	char* t = "abcde";
	printf("%s\n", fun(s, t));

	return 0;
}

#define ADD(X, Y) ( (X) + (Y) )

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

int main2()
{
	int a = 5;
	int b = 7;
	int max = MAX(a, b);
	printf("max = %d\n", max);

	int sum = ADD(100, 10);
	printf("sum = %d\n", sum);

	return 0;
}

int main1()
{
	char arr[] = { 'a', 'b', 'c', 'd', 'e', '\0'};
	char arr2[] = { 'a', 'b', 'c', 'd', 'e'};
	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n", sz); // 6

	int len = strlen(arr);
	printf("%d\n", len); // 5

	printf("%s\n", arr); // abcde
	printf("%s\n", arr2); // abcde昧字方。。。

	int arr3[20] = { 0 };
	int sz2 = sizeof(arr3) / sizeof(arr3[0]);
	printf("%d\n", sz2);
	printf("%d\n", sizeof(arr3));

	
	return 0;
}
