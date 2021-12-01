#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void menu()
{
	printf("************************************\n");
	printf("*****    1. add      2. del    *****\n");
	printf("*****    3. search   4. modify *****\n");
	printf("*****    5. show     6. sort   *****\n");
	printf("*****    0. exit               *****\n");
	printf("************************************\n");
}

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
};

int main()
{
	int input = 0;

	struct Contact con;

	InitContact(&con);

	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);

		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			break;
		case EXIT:
			DestroyContact(&con);
			printf("退出程序");
			break;
		default:
			printf("选择错误，请重新选择:>");
			break;
		}

	} while (input);

	return 0;
}
