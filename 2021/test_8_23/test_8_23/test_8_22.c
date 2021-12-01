#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//int main()
//{
//	char a[] = "123456789", * p = a;
//	int i = 0;
//	while (*p)
//	{
//		if (i % 2 == 0) *p = '!';
//		i++; p++;
//	}
//	puts(a);
//	return 0;
//}

//#include <stdlib.h>
//int main()
//{
//	char str[] = "ABCDEFG";
//	char* p1, *p2;
//	p1 = "abcd"; p2 = "efgh";
//	strcpy(str + 1, p2 + 1); //\0
//	strcpy(str + 3, p1 + 3);
//	printf("%s\n", str);
//	return 0;
//}

//int main()
//{
//	unsigned int a = 0xFFFFFFF7;
//	unsigned char i = (unsigned char)a;
//	char* b = (char*)&a;
//	printf("%08x,%08x", i, *b);
//
//	return 0;
//}

//int main()
//{
//	int j = 4;
//	int i = j;
//	for(; i <= 2 * j; i++) 
//	{
//		switch (i / j) 
//		{
//		case 0:
//		case 1:
//			printf("*"); 
//			break;
//		case 2:
//			printf("#");
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int x = 1, y = 012; //8½øÖÆ
//	printf("%d", y * x++);
//	return 0;
//}

//int main()
//{
//	unsigned short sht = 0;
//	sht--;
//	printf("%d", sht);
//}
//
//int main()
//{
//
//	int arr[] = { 1,2,3,4,5 };
//	int* ptr = (int*)(&arr + 1);
//	printf("%d %d\n", *(arr + 1), *(ptr - 1));
//}

//int main()
//{
//	char ch = 'B' + '8' - '3';
//	printf("%c", ch);
//}

//#include <stdio.h>
//
//long long Pow(int x, int y)
//{
//	if (y == 0)
//		return 1;
//	else if (y == 1)
//		return x;
//	else
//	{
//		long long i = 0;
//		long long x2 = 1;
//		for (i = 0; i < y; i++)
//		{
//			x2 *= x;
//		}
//		return x2;
//	}
//}
//int main()
//{
//	long long a = 2;
//	long long b = 4;
//	long long ret = Pow(a, b);
//	printf("%lld", ret);
//}

//int main()
//{
//	unsigned long p[] = { 6,7,8,9,10 };
//	unsigned long* pu;
//	pu = p;
//	*(pu + 2) += 2;
//	printf("%d,%d\n", *pu, *(pu + 2));
//}

//int main()
//{
//	char* s = "abcde";
//	s += 2;
//	printf("%lu\n", s);
//	return 0;
//}

//int main()
//{
//	int i;
//	char a[20] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
//	for (i = 0; i < 10; i++)
//	{
//		a[i] = '0';
//	}
//	printf("%d\n", strlen(a));
//	return 0;
//}

//void foo(int b[][3])
//{
//	++b;
//	b[1][1] = 9;
//}
//int main()
//{
//	int a[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
//	foo(a);
//	printf("%d\n", a[2][1]);
//}

//int main()
//{
//	int x = 0, y = 0, z = 0;
//	z = (x == 1) && (y = 2);
//	printf("%d ", y);
//}

//int main()
//{
//	int i = 10;
//	long long t = sizeof(i++);
//	printf("%d", i);
//}

//#define N 3
//#define Y(n) ((N+1)*n)
//
//int main()
//{
//	int z = 2 * (N + Y(5 + 1));
//	printf("%d", z);
//}

//int main()
//{
//	int i = 6;
//	if (i <= 6)
//		printf("hello\n");
//	else
//		printf("b");
//}
//
//int main()
//{
//	char ch = -1;
//	printf("%d\n", ch);
//}

//int main()
//{
//	int i, x, y;
//	i = x = y = 0;
//	do
//	{
//		++i;
//		if (i % 2)
//		{
//			x += i;
//			i++;
//			y += i++;
//		}
//
//	} while (i <= 7);
//	printf("%d %d %d", i, x, y);
//}

//int main()
//{
//	//int a = 5, * p = &a, * q = &a;
//	//a = (*p) * (*q);
//	//q = a;
//	//a = p - q;
//	//p = q;
//
//	//int x, y = 5, * p = &x;
//	//x = *p;
//	//*p = &y;
//	//x = &y;
//	//x = y;
//
//	//int a[][3] = { 1,2,3,4,5,6,7 };
//}

//int main()
//{
//	int x = 0;
//	x = 4;
//	x += x *= x + x;
//	printf("%d", x);
//}

//int main()
//{
//	char x[] = "China";
//	printf("%d", sizeof(x));
//}

//int main()
//{
//	char str1[8] = { 'h', 'o', 'f', 's', 'v' };
//	char str2[5] = "good!";
//	char* str3 = "good!";
//	char str4[5] = { 'g', 'o', 'o', 'd', '!' };
//}

//int fun(int x)
//{
//	int count = 0;
//	while (x)
//	{
//		count++;
//		x = x & (x - 1);
//	}
//	return count;
//}
//int main()
//{
//	printf("%d\n", fun(2019));
//}

//int func(int a) 
//{
//	int b = 0;
//	static int c = 3;
//	a = c++, b++;
//	return (a);
//}
//
//int main() 
//{
//	int a = 2, i, k;
//	for (i = 0; i < 2; i++) 
//	{
//		k = func(a++);
//	}
//	printf("%d\n", k);
//}

//int main()
//{
//	int s = 0, n;
//	for (n = 0; n < 4; n++)
//	{
//		switch (n)
//		{
//		default:
//			s += 4;
//		case 1:
//			s += 1;
//		case 2:
//			s += 2;
//		case 3:
//			s += 3;
//		}
//	}
//	printf("%d\n", s);
//
//	return 0;
//}

//#include <stdio.h>
//
//int is_power(int n)
//{
//	if ((n & (n - 1)) == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = is_power(n);
//	if(ret == 1)
//	{
//		printf("YES\n");
//	}
//	else
//	{
//		printf("NO\n");
//	}
//}