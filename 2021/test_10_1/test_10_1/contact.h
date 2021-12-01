#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_MAX 20
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

//struct Contact
//{
//	struct PeoInfo data[MAX];
//	int sz;
//};


struct Contact
{
	struct PeoInfo* data;
	int sz;
	int capacity;
};


void InitContact(struct Contact* pc);

void AddContact(struct Contact* pc);

void ShowContact(struct Contact* pc);

void DelContact(struct Contact* pc);

void SearchContact(struct Contact* pc);

void ModifyContact(struct Contact* pc);

void DestroyContact(struct Contact* pc);

void SaveContact(struct Contact* pc);