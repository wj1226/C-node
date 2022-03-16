#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

void print_arr(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

void test1()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	qsort(arr, sz, sizeof(arr[0]), cmp_int);

	print_arr(arr, sz);
}


struct Stu
{
	char name[20];
	int age;
};

int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}

int cmp_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

void printStuName(struct Stu* s, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%s : %d\n", s->name, s->age);
		s++;
	}
}

void printStuAge(struct Stu* s, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%s : %d\n", s->name, s->age);
		s++;
	}
}

void test2()
{
	struct Stu s[3] = { {"张三", 15}, {"李四", 30}, {"王五", 10} };
	int sz = sizeof(s) / sizeof(s[0]);

	// 按照名字排序
	qsort(s, sz, sizeof(s[0]), cmp_by_name);
	printStuName(s, sz);
	// 李四: 30
	// 王五 : 10
	// 张三 : 15

	printf("\n");

	// 按照年龄排序
	qsort(s, sz, sizeof(s[0]), cmp_by_age);
	printStuAge(s, sz);
	// 王五 : 10
	// 张三 : 15
	//李四 : 30
}


int main()
{
	// 测试排序整型
	//test1();

	// 测试排序结构体数据
	test2();

	return 0;
}


//int main()
//{
//	unsigned char i = 0;
//	for (i = 0; i <= 255; i++)
//	{
//		printf("%d : hello world\n", i);
//	}
//	//unsigned char取值范围：0~255
//}


//int main()
//{
//	int x = 8;
//	for (; x > 0; x--)
//	{
//		if (x % 3)
//		{
//			printf("%d,", x--);
//			continue;
//		}
//		printf("%d,", --x);
//	}
//
//	return 0;
//}
