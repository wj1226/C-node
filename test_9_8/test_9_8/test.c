#define _CRT_SECURE_NO_WARNINGS 1

// 指针笔试题
#include <stdio.h>

int main()
{
	int a[4] = { 1, 2, 3, 4 };
	int* ptr1 = (int*)(&a + 1);
	int* ptr2 = (int*)((int)a + 1);
	
	printf("%x,%x", ptr1[-1], *ptr2); // 4,2000000 

	return 0;
}


#include <stdio.h>

int main()
{
	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
	
	int* p;
	p = a[0];

	printf("%d", p[0]);

	return 0;
}


#include <stdio.h>

int main()
{
	int a[5][5];

	int(*p)[4];
	p = a;

	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);

	return 0;
}
// FFFFFFFC, -4


#include <stdio.h>

int main()
{
	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int* ptr1 = (int*)(&aa + 1);
	int* ptr2 = (int*)(*(aa + 1));

	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));

	return 0;
}



#include <stdio.h>

int main()
{
	char* a[] = { "work","at","alibaba" };

	char** pa = a;
	pa++;

	printf("%s\n", *pa);

	return 0;
}


#include <stdio.h>

int main()
{
	char* c[] = { "ENTER","NEW","POINT","FIRST" };

	char** cp[] = { c + 3,c + 2,c + 1,c };

	char*** cpp = cp;

	printf("%s\n", **++cpp);

	printf("%s\n", *-- * ++cpp + 3);

	printf("%s\n", *cpp[-2] + 3);

	printf("%s\n", cpp[-1][-1] + 1);

	return 0;
}


#include <stdio.h>

int main()
{
	int arr[10][10] = { 0 };
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		int j = 0;
		for (j = 0; j <= i; j++)
		{
			if (j == 0)
				arr[i][j] = 1;
			if (i == j)
				arr[i][j] = 1;

			if (i >= 2 && j >= 1)
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	for (i = 0; i < 10; i++)
	{
		int j = 0;
		for (j = 0; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}


#include <stdio.h>

int main()
{
	// 0-255
	unsigned char a = 200;
	// 00000000000000000000000011001000
	// 11001000 - a  存到a、b中截断

	unsigned char b = 100;
	// 00000000000000000000000001100100
	// 01100100 - b
	
	unsigned char c = 0;

	c = a + b;
	// 计算：整型提升
	// 无符号数，直接补0

	// 00000000000000000000000011001000 - a
	// 00000000000000000000000001100100 - b
	// 00000000000000000000000100101100 - a+b
	// 00101100 - c 存进c截断

	printf("%d %d", a + b, c);
	// c按%d补码打印 整型提升
	// c是unsigned char 补0
	// 00000000000000000000000000101100 - %d打印c  正数原反补相同
	// 44
	
	// a+b的值没有存进c，没有发生截断，直接以%d打印
	// 00000000000000000000000100101100 - a+b
	// 正数原反补相同
	// 300

	return 0;
}