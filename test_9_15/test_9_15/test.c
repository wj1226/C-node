#define _CRT_SECURE_NO_WARNINGS 1

// 1、模拟实现strcat - 
// strcat 字符串连接 - 字符串追加
// 返回的是目标空间的起始地址

#include <stdio.h>
#include <string.h>
#include <assert.h>

char* my_strcat(char* dest, const char* src)
{
	char* ret = dest;
	assert(dest && src);

	// 1. 找到目标字符串末尾\0
	while (*dest)
	{
		dest++;
	}
	// 2. 追加原字符串直到\0
	while (*dest++ == *src++)
	{
		;
	}

	return ret;
}

int main()
{
	char arr1[20] = "abc";
	char arr2[] = { 'd', 'e', 'f', '\0' };
	
	//my_strcat(arr1, arr2);
	//printf("%s\n", arr1); // abcdef

	printf("%s\n", my_strcat(arr1, arr2));//abcdef

	return 0;
}


// 2、strcmp 比较字符串
// 比较的是字符串的内容，而不是长度

#include <stdio.h>
#include <string.h>

int main()
{
	char arr[] = "abcdef";
	char arr1[] = "abcq";
	char arr2[] = "abc";

	strcmp(arr, arr1); // d<q 返回大于0的数字
	strcmp(arr, arr2); // <0

	return 0;
}


#include <stdio.h>
#include <string.h>
#include <assert.h>

int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "abcq";

	int ret = strcmp(arr1, arr2);

	if (ret == 0)
	{
		printf(">\n");
	}
	else if (ret > 0)
	{
		printf(">\n");
	}
	else
	{
		printf("<\n");
	}
	
	if (ret == 1) // 有风险
	{ 
		printf(">\n");
	}

	printf("%d", ret);

	return 0;
}


// 模拟实现stcmp
#include <stdio.h>
#include <string.h>
#include <assert.h>
 
int my_strcmp(const char* s1, const char* s2)
{
	assert(s1 && s2);
 
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return 0;
		s1++;
		s2++;
	}

	return *s1 - *s2;
}

int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "abcq";

	int ret = my_strcmp(arr1, arr2);

	if (ret == 0)
	{
		printf("=\n");
	}
	else if (ret > 0)
	{
		printf(">\n");
	}
	else
	{
		printf("<\n");
	}

	printf("%d", ret);

	return 0;
}


// 3、长度（不）受限制的字符串函数
// 长度不受限制的字符串函数：strcpy strcat strcmp
// 不够安全
// 长度受限制的字符串函数：strncpy strncat strncmp
// 相对安全

// strncp
int main()
{
	char arr1[20] = "abcdef";
	char arr2[] = "xxx";

	strncpy(arr1, arr2, 6); // 不够用\0凑

	printf("%s\n", arr1);

	return;
}


// strncat
int main()
{
	char arr1[20] = "abc\0xxxxxx";
	char arr2[] = "defghi";

	strncat(arr1, arr2, 3); // abcdef\0
  // 追加完放\0

	printf("%s\n", arr1);

	return;
}

int main()
{
	char arr1[20] = "abc\0xxxxxx";
	char arr2[] = "def";

	strncat(arr1, arr2, 6); // 6不起作用 值追加到\0

	printf("%s\n", arr1);

	return;
}


// strcmp
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "abcqw";

	int ret = strncmp(arr1, arr2, 4); // 

	printf("%d\n", ret);

	return;
}


// VS安全版本 strcpy_s 与strncpy相似


// 4、strstr 字符串查找
// 在一个字符串中查找子字符串
// 返回arr2在arr1里出现的第一次的位置，找不到返回空指针
#include <stdio.h>
#include <string.h>

int main()
{
	char arr1[] = "i am a student, good student";
	char arr2[] = "student";

	char* ret = strstr(arr1, arr2);

	if (ret == NULL)
	{
		printf("找不到\n");
	}
	else
	{
		printf("%s\n", ret); // student, good student
	}

	return 0;
}


// 模拟实现strstr
#include <stdio.h>
#include <string.h>
#include <assert.h>

char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);

	char* s1;
	char* s2;
	char* cp = str1;

	if (*str2 == '\0')
		return str1;

	while (*cp)
	{
		s1 = cp; // 记录起始位置
		s2 = str2;

		// while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
		while (*s1 && *s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}

		if (*s2 == '\0')
		{
			return cp;
		}

		cp++;
	}

	// 找不到
	return NULL;
}

int main()
{
	char arr1[] = "i am a student, good student";
	char arr2[] = "student";

	char* ret = my_strstr(arr1, arr2);

	if (ret == NULL)
	{
		printf("找不到\n");
	}
	else
	{
		printf("%s\n", ret);
	}

	return 0;
}

                                       
// 5、strtok 分割字符串
// 如字符串：192.168.2.121  用.分割
// wk@bit.tech 分隔符是@和.
#include <stdio.h>
#include <string.h>

int main()
{
    char arr1[] = "wk@bit.tech";
    char arr2[20] = { 0 }; // 临时数据
    // wk\0bit\0tech

    char sep[] = "@.";

    strcpy(arr2, arr1);

    //strtok(arr2, sep);
    //strtok(NULL, sep);

    char* ret = NULL;
    for (ret=strtok(arr2, sep); ret!=NULL; ret=strtok(NULL, sep))
    {
        printf("%s\n", ret);
    }

    return 0;
}


// 6、内存拷贝
// memcpy memmove memset memcmp

// memcpy
#include <stdio.h>
#include <string.h>
int main()
{
    int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int arr2[20] = { 0 };
    // 拷贝的是整型数据，不能用字符串拷贝strcpy，用内存拷贝memcpy

    memcpy(arr2, arr1, 10 * sizeof(int));

    int i = 0;
    for (i = 0; i < 20; i++)
    {
        printf("%d ", arr2[i]);
    }

    return 0;
}

// 模拟实现memcpy
#include <stdio.h>
#include <string.h>
#include <assert.h>

void* my_memcpy(void* dest, const void* src, size_t count)
{
    void* ret = dest;
    assert(dest && src);

    while (count--)
    {
        *(char*)dest = *(char*)src;
        dest = (char*)dest + 1;
        src = (char*)src + 1;
    }

    return ret;
}

int main()
{
    int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int arr2[20] = { 0 };

    my_memcpy(arr2, arr1, 10 * sizeof(int));

    int i = 0;
    for (i = 0; i < 20; i++)
    {
        printf("%d ", arr2[i]);
    }

    return 0;
}


// 重叠/不重叠
void* my_memcpy(void* dest, const void* src, size_t count)
{
    void* ret = dest;
    assert(dest && src);

    while (count--)
    {
        *(char*)dest = *(char*)src;
        dest = (char*)dest + 1;
        src = (char*)src + 1;
    }

    return ret;
}

int main()
{
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

    my_memcpy(arr+2, arr, 16); // 起始位置3   把1234拷贝到2456
    // 不能完成
    
    // 但库函数和memcpy可以
    // memcpy - 只要完成不重叠的内存拷贝就完成任务60分，但VS中的memcpy完成了100分
    // 内存拷贝的时候，出现内存重叠的现象，应使用，memmove

    int i = 0;
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
