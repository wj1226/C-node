#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//有一个数组a 编写函数 求数组中前K个最小的数字
//int FindMin(int a[], int k)
//{
//	int min = a[0];
//	int i = 0;
//	for (i = 0; i < k-1; i++)
//	{
//		if (a[i] < min)
//			min = a[i];
//	}
//	return min;
//}
//
//int main()
//{
//	int a[] = { 5,3,7,8,1,4,9,10,6,2 };
//	int k = 7;
//	
//	int ret = FindMin(a, k);
//	
//	printf("%d\n", ret);
//
//	return 0;
//}

//typedef char STRING[255]; 
//STRING s;

//int main()
//{
//	int a = 10;
//	double b = 3.14;
//	'A' + a + b;
//
//	return 0;
//}

//#include <string.h>
//int main()
//{
//	char s[] = "\\123456\123456\t";
//	printf("%d\n", strlen(s));
//}

//int main()
//{
//	int s = 0, n;
//	for (n = 0; n < 4; n++)
//	{
//		switch (n)
//		{
//		default:s += 4;
//		case 1:s += 1;
//		case 2:s += 2;
//		case 3:s += 3;
//		}
//	}
//	printf("%d\n", s);
//	//10 16 21 24
//	//1 2 3
//	return 0;
//}

//5 5 4 6
//#include <string.h>
//int main()
//{
//	char* pc = "blue1";
//	char ac[] = "blue1";
//	printf("%d\n", strlen(pc));
//	printf("%d\n", strlen(ac));
//	printf("%d\n", sizeof(pc));
//	printf("%d\n", sizeof(ac));
//
//	return 0;
//}

//int main()
//{
//	unsigned long ulA = 0x11000000;
//	printf("%x\n", *(unsigned char*)&ulA);
//	return 0;
//}

//int FindTimes(int arr[], int sz)
//{
//	int i = 0;
//	int cnt = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,2,2,2,5,4,2 };
//	int sz = size(arr) / sizeof(arr[0]);
//
//	int ret = FindTimes(arr, sz);
//	printf("%d\n", ret);
//	
//	return 0;
//}

//void Func(char str_arg[2])
//{
//	int m = sizeof(str_arg);
//	int n = strlen(str_arg);
//	printf("%d\n", m);
//	printf("%d\n", n);
//}
//int main()
//{
//	char str[] = "Hello";
//	Func(str);
//}

//000 00000000000000000000000000001000

//union X {
//	int x;
//	char y[4];
//}a;
//int main() {
//	a.x = 0x11223344;
//	a.y[0];
//}

//int main()
//{
//	const char* p = "hello,world";
//	return 0;
//}

//int main()
//{
//	int a, x;
//	for (a = 0, x = 0; a <= 1 && !x++; a++)
//	{
//		a++;
//	}
//	printf("%d %d", a, x);
//
//	return 0;
//}

//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int* p1 = (int*)(&a + 1);
//	int* p2 = (int*)((int)a + 1);
//	int* p3 = (int*)(a + 1);
//	printf("%d, %x, &d\n", p1[-1], p2[0], p3[1]);
//	return 0;
//}

//int main()
//{
//	char* str[3] = { "stra", "strb", "strc" };
//	char* p = str[0];
//	int i = 0;
//	while (i < 3)
//	{
//		printf("%s ", p++);
//		i++;
//	}
//	return 0;
//}


//char* myString()
//{
//	char buffer[6] = { 0 };
//	char *s = "Hello World!";
//	int i = 0;
//	for (i = 0; i < sizeof(buffer)-1; i++)
//	{
//		buffer[i] = *(s + i);
//	}
//	return buffer;
//}
//int main()
//{
//	printf("%s\n", myString());
//	return 0;
//}

//int main()
//{
//	int i = 1;
//	printf("%d %d\n", sizeof(i++), i);
//}

//#include <string.h>
//int main()
//{
//	char a[1000];
//	int i;
//	for (i = 0; i < 1000; i++)
//	{
//		a[i] = (char)(-1 - i);
//	}
//	printf("%d\n", strlen(a));
//	return 0;
//}

//int fun(char* s)
//{
//	char* p = s;
//	while (*p != '\0')
//	{
//		p++;
//	}
//	return(p - s);
//}
//
//int main()
//{
//	printf("%d\n", fun("goodbye!"));
//}

//int main()
//{
//	int a[4] = { 0 };
//	*a;
//	a[0];
//	a;
//	a++;
//	return 0;
//}

//000000000000000000000000000000001010

//int main()
//{
//	unsigned char a = 0xA5;
//	unsigned char b = ~a >> 4 + 1;
//	printf("%d\n", b);
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4 };
//	printf("%d", sizeof(arr)-strlen(arr));
//	return 0;
//}

//int main()
//{
//	unsigned char a = 0xA5;
//	unsigned char b = ~a >> 4 + 1;
//	printf("%d", b);
//}

//int main()
//{
//	const int i = 0;
//	int* j = (int*)&i;
//	*j = 1;
//	printf("%d %d", i, *j);
//}

//00000000000000000000000000000010
//00000000000000000000000000000100
//00000000000000000000000000000000 0
//00000000000000000000000000000110 6
//00000000000000000000000000000011 3

//int f(int x, int y)
//{
//	return (x & y) + ((x ^ y) >> 1);
//}
//int main()
//{
//	int result = f(2, 4);
//	printf("%d\n", result);
//	return 0;
//}

//void fun(int x, int y, int* c, int* d)
//{
//	*c = x + y; 
//	*d = x - y;
//}
//int main()
//{
//	int a = 4, b = 3, c = 0, d = 0;
//	fun(a, b, &c, &d);
//	printf( "%d %d\n", c, d);
//}

//int main()
//{
//	int a[10] = { 0,1,2,3,4,5,6,7,8,9 }, * p = a;
//
//	printf("%d\n", *a);
//	printf("%d\n", *p);
//	printf("%d\n", a);
//	printf("%d\n", a[p-a]);
//}

//int main()
//{
//	int c[] = { 1,3,5 };
//	int* k = c + 1;
//	printf("%d", *++k);
//}

//#define MA(X,Y) (X)*(Y)
//int main()
//{
//	int i = 5;
//	i = MA(i, i +1)-7;
//	printf("%d", i);
//}


//#define sum(a,b,c) a+b+c
//int main()
//{
//	int i = 3;
//	int j = 2;
//	printf("%d\n", i*sum(i, (i + j), j));
//}

//int f(int n)
//{
//	static int i = 1;
//	if (n >= 5)
//		return n;
//	n = n + i;
//	i++;
//	return f(n);
//}
//int main() {
//	printf("%d\n", f(1));
//}

//int func() {
//	int i, j, k = 0;
//	for (i = 0, j = -1; j = 0; i++, j++) {
//		k++;
//	}
//	return k;
//}
//int main() {
//	printf("%d\n", (func()));
//}

//#include <stdio.h>
//#include <string.h>
//void exchange(char a[], char b[])
//{
//	int len1 = strlen(a);
//	int len2 = strlen(b);
//	int i = 0;
//	for (i = 0; i < len1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < len2; j++)
//		{
//			if (a[i] == b[j])
//				a[i] = '1';
//		}
//	}
//	for (i = 0; i < len1 - 1; i++)
//	{
//		if(a[i] != '1')
//			printf("%c", a[i]);
//	}
//}
//int main()
//{
//	char a[] = "They are students.";
//	char b[] = "aeiou";
//	exchange(a, b);
//	return 0;
//}

//int main()
//{
//	int c[] = { 1,3,5 };
//	int* k = c + 1;
//	printf("%d", *++k);
//}

//struct student {
//	char name[10];
//	int age;
//	char gender;
//}std[3], *p=std;
//int main()
//{
//	scanf("%d", &(*p).age);
//	scanf("%d", &std[0].gender );
//	scanf("%d", &(p->gender ));
//	scanf("%d", &std.name  );
//}

//int main()
//{
//	int a = 2, * p1, ** p2;
//	p2 = &p1;
//	p1 = &a;
//	a++;
//	printf("%d,%d,%d\n", a,*p1, **p2);
//}

//int main()
//{
//	int k, j, s;
//	for (k = 2; k < 6; k++, k++)
//	{
//		s = 1;
//		for (j = k; j < 6; j++)
//			s += j;
//	}
//	printf("%d\n", s);
//	return 0;
//}

//int main()
//{
//	int arr[] = { 6,7,8,9,10 };
//	int* ptr = arr;
//	*(ptr++) += 123;
//	printf("%d,%d", *ptr, *(++ptr));
//}

//int is_num(int n)
//{
//	int n2 = n;
//	int y = 0;
//	while (n2)
//	{
//		y = y * 10 + n2 % 10;
//		n2 /= 10;
//	}
//	if (y == n)
//		return 1;
//	else
//		return 0;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = is_num(n);
//	if (ret == 1)
//		printf("YES\n");
//	else
//		printf("NO\n");
//
//	return 0;
//}