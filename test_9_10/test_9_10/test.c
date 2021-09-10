#define _CRT_SECURE_NO_WARNINGS 1

// test
#include <stdio.h>
#include <string.h>

void left_move(char* arr, int k)
{
	int i = 0;
	int len = strlen(arr);
	for (i = 0; i < k; i++)
	{
		// 左旋1个字符
		// 1、保存第一个字符
		char tmp = *arr;
		// 2、把后续的字符依次往前移动
		int j = 0;
		for (j = 0; j < len - 1; j++)
		{
			*(arr + j) = *(arr + j + 1);
		}
		// 3、把保存好的第一个字符存放在最后
		*(arr + len - 1) = tmp;
	}
}

int main()
{
	char arr[] = "abcdef";

	left_move(arr, 2);

	printf("%s\n", arr);

	return 0;
}


#include <stdio.h>
#include <string.h>
#include <assert.h>

void reverse(char* l, char* r)
{
	assert(l && r);

	while (l < r)
	{
		char tmp = *l;
		*l = *r;
		*r = tmp;

		l++;
		r--;
	}
}

void left_move(char* arr, int k)
{
	assert(arr);
	int len = strlen(arr);
	k %= len;

	reverse(arr, arr + k - 1); // 逆序左边
	reverse(arr + k, arr + len - 1); // 逆序右边
	reverse(arr, arr + len - 1); // 逆序整个字符串
}

int main()
{
	char arr[] = "abcdef";

	left_move(arr, 2);

	printf("%s\n", arr);

	return 0;
}



#include <stdio.h>
#include <assert.h>
#include <string.h>

void reverse(char* l, char* r)
{
	assert(l && r);

	while (l < r)
	{
		char tmp = *l;
		*l = *r;
		*r = tmp;

		l++;
		r--;
	}
}

void left_move(char* arr, int k)
{
	assert(arr);
	int len = strlen(arr);
	k %= len;

	reverse(arr, arr + k - 1); // 逆序左边
	reverse(arr + k, arr + len - 1); // 逆序右边
	reverse(arr, arr + len - 1); // 逆序整个字符串
}

// 判断arr2是否是arr1旋转得到的
int is_left_move(char arr1[], const char arr2[])
{
	int len = strlen(arr1);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		left_move(arr1, 1);
		if (strcmp(arr1, arr2) == 0)
			return 1;
	}
	return 0;
}

int main()
{
	char arr1[] = "ABCDEF";
	char arr2[] = "BCDEFA";

	int ret = is_left_move(arr1, arr2);
	if (ret == 1)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}



#include <stdio.h>
#include <assert.h>
#include <string.h>

void reverse(char* l, char* r)
{ 
	assert(l && r);

	while (l < r)
	{
		char tmp = *l;
		*l = *r;
		*r = tmp;

		l++;
		r--;
	}
}

void left_move(char* arr, int k)
{
	assert(arr);
	int len = strlen(arr);
	k %= len;

	reverse(arr, arr + k - 1); // 逆序左边
	reverse(arr + k, arr + len - 1); // 逆序右边
	reverse(arr, arr + len - 1); // 逆序整个字符串
}

// 判断arr2是否是arr1旋转得到的
int is_left_move(char arr1[], char arr2[])
{
	assert(arr1 && arr2);

	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	if (len1 != len2)
		return 0;
	
	// 1、给arr1的后面追加一个arr1字符串
	strncat(arr1, arr1, len1);
	// 2、判断arr2是否为arr1的子串
	if (NULL == strstr(arr1, arr2))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	char arr1[20] = "AABCD";
	// AABCDAABCD 给arr1追加arr1
	char arr2[] = "BCDAA";

	int ret = is_left_move(arr1, arr2);
	if (ret == 1)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}


// 字符串追加
int main()
{
	char arr[20] = "abc";
	// strcat - 字符串追加
	strcat(arr, "def");
	// strncat - 字符串追加自己
	strncat(arr, arr, 3);


	char arr1[] = "abcdefabcdef";
	char arr2[] = "def";
	// strstr - 查找字符串
	char* ret = strstr(arr1, arr2); // 查找arr1中有没有arr2，返回arr1中第一次出现的arr2的起始地址
	if (ret == NULL)
	{
		printf("找不到\n");
	}
	else
	{
		printf("找到了：%s\n", ret);
	}	
}



#include <stdio.h>

void find_k(int arr[3][3], int k, int r, int c)
{
	int x = 0;
	int y = c - 1; // 从左上角开始找

	while (x < r && y>= 0)
	{
		if (arr[x][y] < k)
			x++;
		else if (arr[x][y] > k)
			y--;
		else
		{
			printf("找到了，下标是：%d %d\n", x, y);
			return;
		}
	}
	printf("找不到\n");
}

int main()
{
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int k = 7;

	find_k(arr, k, 3, 3);

	return 0;
}


// 把找到的坐标带回
#include <stdio.h>

void find_k(int arr[3][3], int k, int *px, int *py)
{
	int x = 0;
	int y = *py - 1; // 从左上角开始找

	while (x < *px && y >= 0)
	{
		if (arr[x][y] < k)
			x++;
		else if (arr[x][y] > k)
			y--;
		else
		{
			*px = x; // 带回main中的x，y
			*py = y;

			return;
		}
	}
	*px = -1;
	*py = -1;
}

int main()
{
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int k = 7;
	int x = 0;
	int y = 0;

	// &x &y
	// 输入 输出
	// 返回型参数
	find_k(arr, k, &x, &y);
	printf("找到了，坐标是：%d %d\n", x, y);

	return 0;
}



// 字符函数，字符串函数，内存函数

// 1、strlen
#include <stdio.h>

int main()
{
	char arr[] = "abcdef";
	
	// size_t - unsigned int
	
	// size_t sz = strlen("abcdef");
	size_t sz = strlen(arr);

	printf("%u\n", sz);

	return 0;
}


#include <stdio.h>

int main()
{
	if (strlen("abc") - strlen("abcdef") > 0)
	{
		printf("haha\n");
	}
	else
	{
		printf("hehe\n");
	}

	return 0;
}

int main()
{
	if ((int)strlen("abc") - (int)strlen("abcdef") > 0)
	{
		printf("haha\n");
	}
	else
	{
		printf("hehe\n");
	}

	return 0;
}

// strlen的模拟实现
// 1、计数器，2、指针-指针，3、递归


// 2、strcpy
int main()
{
	char arr1[] = "xxxxxxxxxxxxxxxx";
	char arr2[] = "hello";
	// 拷贝arr2中的字符串，包括\0，hello\0

 strcpy(arr1, arr2);
 
	return 0;
}

int main()
{
	char arr1[] = "xxxxxxxxxxxxxxxx";
	char arr2[] = "hello\0abc";
	// 拷贝到\0停止
	// hello\0

	return 0;
}

// strcpy模拟实现
#include <stdio.h>
#include <assert.h>

char* my_strcpy(char* dest, char* src)
{
	assert(dest && src);

	char* ret = dest;
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

int main()
{
	char arr1[] = "xxxxxxxxx";
	char arr2[] = "abc";

	printf("%s\n", my_strcpy(arr1, arr2));

	return 0;
}
