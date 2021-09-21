#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void InitContact(struct Contact* pc)
{
	pc->sz = 0; // 默认没有信息

	memset(pc->data, 0, MAX * sizeof(struct PeoInfo));
	// memset(pc->date, 0, sizeof(pc->data)); 
	// 通过结构体指针找到数组data 数组名data单独放在sizeof内部，计算的是数组总大小
}

void AddContact(struct Contact* pc)
{
	if (pc->sz == MAX)
	{
		printf("通讯录满了\n");
	}
	else
	{
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
}

void ShowContact(struct Contact* pc)
{
	int i = 0;
	printf("%15s\t%5s\t%8s\t%15s\t%30s\n\n", "name", "age", "sex", "tele", "addr");
	for (i = 0; i < pc->sz; i++)
	{
		//打印每一个数据
		printf("%15s\t%5d\t%8s\t%15s\t%30s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}