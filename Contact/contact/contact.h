#pragma once


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define NAME_MAX 30
#define SEX_MAX 15
#define TELE_MAX 15
#define ADDR_MAX 30

#define MAX 1000

#define DEFAULT_SZ 3


struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
};


// 通讯录
// 1. 静态版本
//struct Contact
//{
//	struct PeoInfo data[MAX]; // 存放1000个人的数据在data数组中
//	int sz; // 记录当前通讯录有效信息的个数
//};

// 动态增长版本
struct Contact
{
	struct PeoInfo* data;
	int sz; // 通讯录中当前有效信息的个数
	int capacity; // 通讯录当前的最大容量
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

// 销毁通讯录
void DestroyContact(struct Contact* pc);


// 保存信息到通讯录中
void SaveContact(struct Contact* pc);

// 加载文件中的信息到通讯录中
void LoadContact(struct Contact* pc);
