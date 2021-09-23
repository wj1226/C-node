#define _CRT_SECURE_NO_WARNINGS 1

//模拟实现库函数：strcpy

//Null - \0
//null - \0
//NULL - 空指针

// strcpy
#include <stdio.h>
#include <string.h>

int main()
{
	//strcpy - string copy - 字符串拷贝
	char arr1[] = "abcdef";
	char arr2[10] = { 0 };
	strcpy(arr2, arr1); //arr2目标数组 

	printf("%s\n", arr2);

	return 0;
}


//my_strcpy

//1
//dest 是指向目标空间的
//src 是指向原字符串的 
void my_strcpy(char* dest, char* src)//目标 源头
{
	while (*src != '\0') // \0=0 当指向\0时停止
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = *src; //strcpy把\0一起拷贝 出循环指向的是\0 拷贝\0
}

int main()
{
	//strcpy - string copy - 字符串拷贝
	char arr1[] = "abcdef";
	char arr2[10] = { 0 };
	my_strcpy(arr2, arr1); //arr2目标数组 

	printf("%s\n", arr2);

	return 0;
}


//2优化
void my_strcpy(char* dest, char* src)
{
	while (*src != '\0')
	{
		*dest++ = *src++; //后置++
	}
	*dest = *src; // \0
}


//3优化
void my_strcpy(char* dest, char* src)
{
	//1. 拷贝字符
	//2. 遇到\0 循环停止
	while (*dest++ = *src++)
	{
		;
	}
}


//4优化 判断空指针
#include <assert.h>

void my_strcpy(char* dest, char* src)
{
	/*if (src == NULL || dest == NULL)
	{
		return;
	}*/

	assert(src != NULL); //断言 - release版本可以优化掉
	assert(dest != NULL);
	//assert发现问题会告诉我们

	/*assert(src);
	assert(dest);

	assert(src && dest);*/

	while (*dest++ = *src++)
	{
		;
	}
}



const
int main()
{
	const int num = 10; //num是常变量
	//num = 20; //err

	int* p = &num;
	*p = 20; //可以修改

	printf("%d\n", num);
}


//const修饰指针 *左右
int main()
{
	const int num = 10;

	//const修饰指针

	//const 放在*的左边
	//修饰的是指针指向的内容（*p）,指针指向的内容，不能通过指针来改变了
	//但是指针变量本身（p）是可以改变的
	int n = 100;
	const int* p = &num; //写法相同int const * p = &num;
	*p = 20;
	p = &n;
	printf("%d\n", num); //修饰的是p 此时p不能存放n的地址

	//const 放在*的右边
	//修饰的是指针变量本身（p）,指针变量本身（p）不能修改了
	//指针指向的内容（*p）可以修改，
	int n = 100;
	int* const p = &num; //修饰的是*p 指针所指向的对象 
	*p = 20;
	p = &n;

	printf("%d\n", num);
}


//5优化 const
// 健壮性/鲁棒性 - 抗风险
#include <assert.h>

void my_strcpy(char* dest, const char* src) //修饰*src 保护src不被修改
{
	assert(src != NULL);
	assert(dest != NULL);

	while (*src++ = *dest++) //如果写反
	{
		;
	}
}


//6优化 返回类型
#include <assert.h>

char* my_strcpy(char* dest, const char* src)
{
	assert(src != NULL);
	assert(dest != NULL);

	char* ret = dest; //先存起来 下面已经指向src对应得\0的位置 不是起始位置

	while (*dest++ = *src++)
	{
		;
	}

	return ret; //返回目标起始位置
}

int main()
{
	char arr1[] = "abcdef";
	char arr2[10] = "xxxxxxxxxx";
	char* ret = my_strcpy(arr2, arr1); //arr2目标数组 

	printf("%s\n", ret);
	//只打印abcdef 没有打印后面的xxxx是因为字符串的结束标志是\0

	return 0;
}


//数组的错误情况
int main()
{
	//1
	char arr1[] = "abcdef"; //[a b c d e f \0]
	char arr2[] = "xxxxxxxxx";

	//2 - 原字符串中一定要有\0
	char arr1[] = { 'a', 'b', 'c' };
	char arr2[10] = "xxxxxxxxx";

	//3 - 目标空间一定要足够大
	char arr1[] = "abcdef";
	char arr2[3] = { 0 };

	//4 - 目标空间必须可修改
	char arr1[] = "abcdef";
	const char* arr2 = "xxxxxxxxxxxxxxx"; //指针指向的内容 不希望被修改时 加const 更严谨安全
	//arr2是指针 指向常量字符串，常量字符串是放在常量区，是不能修改的
	//不能拷贝，因为目标空间arr2不能被修改

	char* ret = my_strcpy(arr2, arr1);
	printf("%s\n", ret);

	return 0;
}


//打印字符串 解引用打印一个字符
int main()
{
	char arr[] = "abcdef";
	const char* str = "kel";
	//打印字符串
	printf("%s\n", arr);
	printf("%s\n", str);

	//字符指针 解引用 只能访问一个字符 
	//arr访问的是a 打印的是字符%c
	printf("%c\n", *arr); //a
	printf("%c\n", *str); //k

	return 0;
}


//常量字符串首字符地址存放在指针
int main()
{
	const char* str = "abcdef";
	//常量字符串abcdef在内存的常量区里 
	//把常量字符串首字符a的地址存放在str中
	printf("%s\n", str); //abcdef
	printf("%c\n", *str); //a

	return 0;
}



//模拟实现strlen函数
#include <assert.h>

//size_t - unsigned int 扩大范围
unsigned int my_strlen(const char* str)
{
	assert(str != NULL);

	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}

	return count;
}

int main()
{
	char arr[] = "abcdef";

	int ret = my_strlen(arr);

	printf("%d", ret);

	return 0;
}


//strlen返回类型是无符号数
int main()
{
	//3-6 = -3
	//10000000000000000000000000000011 - 原
	//11111111111111111111111111111100 - 反
	//11111111111111111111111111111101 - -3补码
	//在内存中被解析为无符号数 全都是有效位
	//补码即原码 是一个很大的正数
	if (strlen("abc") - strlen("abcdef") > 0)
	{
		printf("hehe\n"); //hehe
	}
	else
	{
		printf("haha\n");
	}

	return 0;
}



//作业1
#include <stdio.h>

int main()
{
	int a, b, c;

	a = 5;
	c = ++a;
	b = ++c, c++, ++a, a++;
	b += a++ + c;

	printf("a = %d b = %d c = %d\n:", a, b, c);
	//a:9, b:23, c:8
	return 0;
}



//2 统计二进制中1的个数
//写一个函数返回参数二进制中 1 的个数。
//比如： 15    0000 1111    4 个 1

//1) 用&1和>>方法 
size_t count_bit_one(int n)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < 32; i++) //i==31时 最高位来到最低位
	{
		//最低位和1按位与 如果是1按位与后结果就是1
		//00000000000000000000000000001111 - 15
		//00000000000000000000000000000001 - 1
		//00000000000000000000000000000001 - &1 最低位是1 结果就是1
		//按位与后>>
		if (((n >> i) & 1) == 1) //当i=0时 没有右移
		{
			count++;
		}
	}

	return count;
}

int main()
{
	int num = 0;
	scanf("%d", &num);

	int ret = count_bit_one(num);

	printf("%d\n", ret);

	return 0;
}


//2) 用%2方法 

//十进制%10 /10可以得到每一位 
//123%10=3
//12/10=12
//12%10=2

//负数算不了 用无符号数
size_t count_bit_one(unsigned int n) //把负数当成无符号数求
{
	int count = 0;
	while (n)
	{
		if (n % 2 == 1)
		{
			count++;
		}
		n /= 2;
	}

	return count;
}

int main()
{
	int num = 0;
	scanf("%d", &num);

	int ret = count_bit_one(num);

	printf("%d\n", ret);

	return 0;
}


//3）用n-1&
size_t count_bit_one(int n)
{
	int count = 0;
	while (n)
	{
		n = n & (n - 1);
		count++;
	}
	return count;
}

int main()
{
	int num = 0;
	scanf("%d", &num);

	int ret = count_bit_one(num);

	printf("%d\n", ret);

	return 0;
}



//写一个代码，判断一个数是不是2的次方数

//2 -- 0010
//4 -- 0100
//8 -- 1000
//16 -- 10000
int main()
{
	int n = 0;
	scanf("%d", &n);
	if ((n & (n - 1)) == 0)
	{
		printf("YES\n");
	}
	else
	{
		printf("N0\n");
	}

	return 0;
}