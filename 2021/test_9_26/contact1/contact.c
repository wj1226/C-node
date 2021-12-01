#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

//void InitContact(struct Contact* pc)
//{
//	pc->sz = 0;
//	memset(pc->data, '0', MAX * sizeof(struct PeoInfo));
//}

void InitContact(struct Contact* pc)
{
	pc->sz = 0;
	pc->data = (struct PeoInfo*)malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
	pc->capacity = DEFAULT_SZ;
}

//void AddContact(struct Contact* pc)
//{
//	if (pc->sz == MAX)
//	{
//		printf("通讯录满了\n");
//	}
//	else
//	{
//		printf("请输入名字:>");
//		scanf("%s", pc->data[pc->sz].name);
//		printf("请输入年龄:>");
//		scanf("%d", &(pc->data[pc->sz].age));
//		printf("请输入性别:>");
//		scanf("%s", pc->data[pc->sz].sex);
//		printf("请输入电话:>");
//		scanf("%s", pc->data[pc->sz].tele);
//		printf("请输入住址:>");
//		scanf("%s", pc->data[pc->sz].addr);
//
//		pc->sz++;
//		printf("添加成功\n");
//	}
//}

void AddContact(struct Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		struct PeoInfo* ptr = realloc(pc->data, (pc->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity + 2;

			printf("增容成功\n");
		}
		else
		{
			return;
		}
	}
	printf("请输入名字:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->sz].addr);

	printf("添加成功\n");
	pc->sz++;
}

void ShowContact(struct Contact* pc)
{
	int i = 0;
	printf("%15s\t%7s\t%7s\t%15s\t%30s\n", "name", "age", "sex", "tele", "addr");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%15s\t%7d\t%7s\t%15s\t%30s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}

int FindContactByName(const struct Contact* pc, const char* name)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void DelContact(struct Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("通讯录为空，无法删除\n");
	}

	char name[NAME_MAX] = { 0 };
	printf("请输入要删除的名字:>");
	scanf("%s", name);

	int pos = FindContactByName(pc, name);
	if (pos == -1)
	{
		printf("要删除的联系人不存在\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j < pc->sz - 1; j++)
		{
			pc->data[j] = pc->data[j + 1];
		}
		pc->sz--;
		printf("删除成功\n");
	}
}

void SearchContact(const struct Contact* pc)
{
	char name[NAME_MAX] = { 0 };
	printf("请输入要查找的名字:>");
	scanf("%s", name);

	int pos = FindContactByName(pc, name);
	if (pos == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("%15s\t%7d\t%7s\t%15s\t%30s\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].addr);
	}
}

void ModifyContact(const struct Contact* pc)
{
	char name[NAME_MAX] = { 0 };

	printf("输入要修改人的名字:>");
	scanf("%s", name);

	int pos = FindContactByName(pc, name);
	if (-1 == pos)
	{
		printf("要修改的人的信息不存在\n");
	}
	else
	{
		printf("请输入新的名字:>");
		scanf("%s", pc->data[pos].name);
		printf("请输入新的年龄:>");
		scanf("%d", &(pc->data[pos].age));
		printf("请输入新的性别:>");
		scanf("%s", pc->data[pos].sex);
		printf("请输入新的电话:>");
		scanf("%s", pc->data[pos].tele);
		printf("请输入新的地址:>");
		scanf("%s", pc->data[pos].addr);

		printf("修改成功\n");
	}
}

void DestroyContact(struct Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}
