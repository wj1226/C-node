#pragma once

#include <stdio.h>
#include <string.h>

#define NAME_MAX 30
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30

#define MAX 1000

struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
};

// 通讯录
struct Contact
{
	struct PeoInfo data[MAX]; // 存放1000个人的数据在data数组中

	int sz; // 记录当前通讯录有效信息的个数
};

// 初始化通讯录
void InitContact(struct Contact* pc);

// 增加联系人
void AddContact(struct Contact* pc);

// 显示所有联系人
void ShowContact(struct Contact* pc);

// 删除指定联系人
void DelContact(struct Contact* pc);

// 查找指定联系人
void SearchContact(const struct Contact* pc);

// 修改指定联系人
void ModifyContact(struct Contact* pc);