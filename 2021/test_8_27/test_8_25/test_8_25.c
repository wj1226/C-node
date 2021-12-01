#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	int a[] = { 2,4,6,8,10,12,14,16,18,20,22,24 }, *q[4], k;
//	for (k = 0; k < 4; k++) 
//	{
//		q[k] = &a[k * 3];
//	}
//	printf("%d\n", q[3][1]);
//}

//int main()
//{
//	int x = 5 > 1 + 2 && 2 || 2 * 4 < 4 - !0;
//	printf("%d", x);
//}

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


//#define CIR(r) r*r
//
//void main()
//{
//	int a = 1;
//	int b = 2;
//	int t;
//	t = CIR(a + b);
//	printf("%d\n", t);
//}


//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int* p1 = (int*)(&a + 1);
//	int* p2 = (int*)((int)a + 1);
//	int* p3 = (int*)(a + 1);
//	printf("%d %x %d", p1[-1], p2[0], p3[1]);
//}


//char* myString()
//{
//	char buffer[6] = { 0 };
//	char* s = "Hello World!";
//	for (int i = 0; i < sizeof(buffer) - 1; i++)
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


//#define sum(a,b,c) a+b+c
//
//int main()
//{
//	int i = 3;
//	int j = 2;
//	printf("%d\n", i * (sum(i, (i + j), j)));
//	return 0;
//}


//int main()
//{
//	int arr[] = { 6,7,8,9,10 };
//	int* ptr = arr;
//	*(ptr++) += 123;
//	printf("%d,%d", *ptr, *(++ptr));
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	printf("%d,%d", a, --a);
//	return 0;
//}


//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	int* ptr = (int*)(&arr + 1);
//	printf("%d %d\n", *(arr + 1), *(ptr - 1));
//}


//int main()
//{
//	printf("%lf", (double)(10 / 4 * 4));
//}


//#include <stdio.h>
//
//void is_power(int n)
//{
//    if ((n & (n - 1)) == 0)
//    {
//        printf("YES\n");
//    }
//    else
//    {
//        printf("NO\n");
//    }
//}
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    is_power(n);
//    return 0;
//}