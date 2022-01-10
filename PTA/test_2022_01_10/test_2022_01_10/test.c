#define _CRT_SECURE_NO_WARNINGS 1

// 7-26 单词长度
#include <stdio.h>

// 输出每个单词长度 判断条件
int main() 
{
	int len = 0; // 总长
	char cur = 0;
	char next = 0;
	scanf("%c", &next);
	int flag = 1; // 判断加空格
	while (next != '.') 
	{
		cur = next;
		if (cur != ' ') 
		{
			len++;
		}
		scanf("%c", &next);
		// cur 不为空 next 为空 --> 此单词结束
		if (cur != ' ' && next == ' ') 
		{
			if (flag == 1) 
			{
				printf("%d", len);
				flag = 0;
			}
			else {
				printf(" %d", len);
			}
			len = 0; // 下一次计算
		}
	}
	// 最后一个
	if (cur != ' ' && len != 0) 
	{
		if (flag == 1)
		{
			printf("%d", len);
		}
		else {
			printf(" %d", len);
		}
	}
	return 0;
}
