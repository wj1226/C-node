#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	int a[] = { 2,3,6,8,10,12,14,16,20,22,24 }, * q[4], k;
//	for (k = 0; k < 4; k++)
//	{
//		q[k] = &a[k * 3];
//	}
//	printf("%d\n", q[3][1]);
//	//2 8 14 22
//	return 0;
//}

//int main()
//{
//	int i, j, a = 0;
//	for (i = 0; i < 2; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			if (j % 2)
//				break;
//			a++;
//		}
//		a++;
//	}
//	printf("%d\n", a);
//
//	return 0;
//}

//#define INT_PTR int*
//typedef int* int_ptr;
//INT_PTR a, b;
//int_ptr c, d;

//int FindNumber(int arr[4][4], int k)
//{
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			if (arr[i][j] == k)
//				return 1;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int arr[4][4] = {
//		1,2,8,9,
//		2,4,9,12,
//		4,7,9,12,
//		6,8,11,15
//	};
//	int k = 0;
//	scanf("%d", &k);
//	int ret = FindNumber(arr, k);
//	if (ret == 1)
//		printf("YES\n");
//	else
//		printf("NO\n");
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	printf("%d", a += a *= a -= a / 3);
//	return 0;
//}

//void main()
//{
//	int i = 0;
//	while (i < 10) {
//		if (i < 1)continue;
//		if (i == 5)break;
//		i++;
//	}
//}

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//void replace(char* arr, char* arr2)
//{
//	while (*arr != '\0')
//	{
//		if (*arr != ' ')
//		{
//			*arr2 = *arr;
//			arr2++;
//		}
//		else
//		{
//			strcpy(arr2, "%20");
//			arr2 += 3;
//		}
//		arr++;
//	}
//}
//
//int main()
//{
//	char arr[20] = "abc defgx yz";
//	char arr2[50] = { 0 };
//	replace(arr, arr2);
//	printf("%s\n", arr2);
//	return 0;
//}

//int main()
//{
//	int x = 2;
//	int z = 2, y = 3;
//	if (x > y)
//		z = 1;
//	else if (x == y)
//		z = 0;
//	else
//		z = -1;
//	printf("%d", z);
//
//	return 0;
//}

//#include <stdlib.h>
//
//int main()
//{
//	char axHello[] = "hello\0world";
//	char axNew[15] = { 0 };
//	strcpy(axNew, axHello);
//	printf("%d\n", strlen(axNew));
//	printf("%d\n", strlen(axHello));
//	return 0;
//}


//#include <stdio.h>
//
//int Fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("%d\n", ret);
//	return 0;
//}

//int main()
//{
//	char a[20];
//	char* p1 = (char*)a;
//	char* p2 = (char*)(a + 5);
//	int n = p2 - p1;
//	printf("%d", n);
//
//	return 0;
//}

//#define F(X,Y) ((X)+(Y))
//int main()
//{
//	int a = 3, b = 4;
//	printf("%d\n", F(a++, b++));
//}

//int main()
//{
//	int x = 5 > 1 + 2 && 2 || 2 * 4 < 4 - !0;
//	printf("%d", x);
//}

//11 11 11
//#pragma pack(4)
//int main(int argc, char* argv[])
//{
//	struct tafTest1
//	{
//		short a;
//		char d;
//		long b;
//		long c;
//	};
//	struct tafTest2
//	{
//		long b;
//		short c;
//		char d;
//		long a;
//	};
//	struct tafTest3
//	{
//		short c;
//		long b;
//		char d;
//		long a;
//	};
//	struct tagTest1 stT1;
//	struct tagTest2 stT2;
//	struct tagTest3 stT3;
//	printf("%d %d %d", sizeof(stT1), sizeof(stT2), sizeof(stT3));
//	return 0;
//}
//#pragma pack()

//enum ENUM_A
//{
//	X1,
//	Y1,
//	Z1 = 5,
//	A1,
//	B1
//};
//enum ENUM_A enumA = Y1;
//enum ENUM_A enumB = B1;
//
//int main()
//{
//	printf("%d %d", enumA, enumB);
//}
//int fun(int x, int y)
//{
//	static int m = 0;
//	static int i = 2;
//	i += m + 1;
//	m = i + x + y;
//	return m;
//}
//int main()
//{
//	int j = 4;
//	int m = 1;
//	int k;
//	k = fun(j, m);
//	printf("%d\n", k);
//	k = fun(j, m);
//	printf("%d\n", k);
//	return 0;
//}

//#include <stdio.h>
//
//int CntNumOne(unsigned int n)
//{
//	int count = 0;
//	while (n)
//	{
//		if (n & 1)
//			count++;
//		n >>= 1;
//	}
//	return count;
//}
//
//int main()
//{
//	unsigned int x = 15;
//	
//	int ret = CntNumOne(x);
//	
//	printf("%d\n", ret);
//
//	return 0;
//}


//int Change(int* pX)
//{
//	int y = 8;
//	y = y - *pX;
//	pX = &y;
//	return 0;
//}
//int main()
//{
//	int xx = 3;
//	int* pY = &xx;
//	Change(pY);
//	printf("%d\n", *pY);
//	return 0;
//}

//int main()
//{
//	char arr[2][4];
//	strcpy((char*)arr, "you");
//	strcpy(arr[1], "me");
//	arr[0][3] = '&';
//	printf("%s\n", arr);
//	return 0;
//}

//int main()
//{
//	//10000000000000000000000000011011
//	//11111111111111111111111111100100
//	//111111111111111111111111
//	1110 0101
//
//	return 0;
//}

//int main()
//{
//	int a = 4, b = 3, * p, * q, * w;
//	p = &a;
//	q = &b;
//	w = q;
//	q = NULL;
//}

//111 1110 0011 -2019
//111 1110 0010 -2018
//111 1110 1110 

//int fun(int x)
//{
//	int count = 0;
//	while (x) {
//		count++;
//		x = x & (x - 1);
//	}
//	return count;
//}
//int main()
//{
//	printf("fun(2017)=%d\n", fun(2019));
//}

//#define CIR(r) r*r
//int main()
//{
//	int a = 1;
//	int b = 2;
//	int t;
//	t = CIR(a + b);
//	printf("%d/n", t);
//
//	return;
//}

//unsigned long g_ulGlobal = 0;
//void GlobalInit(unsigned long ulArg)
//{
//	ulArg = 0x01;
//	return;
//}
//void Test()
//{
//	GlobalInit(g_ulGlobal);
//	printf("%lu", g_ulGlobal);
//	return;
//}
//int main()
//{
//	Test();
//}

//int fun(int a, int b)
//{
//	if (a > b)
//		return(a + b);
//	else
//		return(a - b);
//}
//int main()
//{
//	int x = 3, y = 8, z = 6, r;
//	r = fun(fun(x, y), 2 * z);
//	printf("%d\n", r);
//	return 0;
//}

//int f(int a)
//{
//	int b = 0;
//	static int c = 3;
//	a = c++, b++;
//	return (a);
//}
//int main()
//{
//	int a = 2, i, k;
//	for (i = 0; i < 2; i++)
//		k = f(a++);
//	printf(" % d\n", k);
//	return 0;
//}

//int x = 3;
//void inc()
//{
//	static int x = 1;
//	x *= (x + 1);
//	printf("%d", x);
//	return;
//}
//int main()
//{
//	int i;
//	for (i = 1; i < x; i++)
//	{
//		inc();
//	}
//	return 0;
//}

//int main()
//{
//	int m, n;
//	for (m = 0, n = -1; m = 0; m++, n++)
//		n++;
//	return 0;
//}

//int a = 1;
//void test()
//{
//	int a = 2;
//	a += 1;
//}
//int main()
//{
//	test();
//	printf("%d\n", a);
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int j = 0;
//	if ((++i > 0) || (++j > 0)) {
//		printf("%d %d", i, j);
//	}
//}

//#define MOD(x,y) x%y
//
//int main()
//{
//	int a = 13, b = 94;
//	printf("%d\n", MOD(b, a + 4));
//}

//int main()
//{
//	int x = 0;
//	switch (++x)
//	{
//	case 0:++x;
//	case 1:++x;
//	case 2:++x;
//	}
//	printf("%d", x);
//
//	return 0;
//}