#define _CRT_SECURE_NO_WARNINGS 1

// 模拟实现atoi
#include <stdio.h>
#include <string.h>

int my_atoi(const char* str)
{
	int is_negative = 0; // 判断正负数
	int ret = 0; // 最终返回数
	char tmp = '0';

	const char* p = str;

	if (NULL == p)
	{
		return -1;
	}

	int len = strlen(str);

	if (*p == '-')
	{
		is_negative = 1;
	}

	int i = 0;
	for (i = 0; i < len; i++)
	{
		tmp = *p++;
		if (tmp > '9' || tmp < '0') // 排除非数字字符
		{
			continue;
		}
		if (tmp != '0' || ret != '0') // 排除开始的0
		{
			tmp -= '0';
			ret = ret * 10 + tmp;
		}
	}
	if (is_negative == 1)
	{
		ret = -ret;
	}

	return ret;
}

int main()
{
	char arr[20] = { 0 };

	strcpy(arr, "98993489");
	int ret = my_atoi(arr);
	printf("字符串值：%s\n整形值：%d\n", arr, ret);

	strcpy(arr, "runoob.com");
	ret = my_atoi(arr);
	printf("\n字符串值：%s\n整形值：%d\n", arr, ret);

	strcpy(arr, "-0123");
	ret = my_atoi(arr);
	printf("\n字符串值：%s\n整形值：%d\n", arr, ret);

	return 0;
}