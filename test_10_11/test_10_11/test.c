#define _CRT_SECURE_NO_WARNINGS 1

//有如下宏定义和结构定义，当A = 2， B = 3时，pointer分配（ ）个字节的空间。
#include <stdio.h>
#include <stdlib.h>

#define A 2
#define B 3
#define MAX_SIZE A+B

struct _Record_Struct
{
	// 1byte - 8bit
	unsigned char Env_Alarm_ID : 4;
	unsigned char Para1 : 2;
	// 1byte
	unsigned char state;
	// 2byte
	unsigned char avail : 1;
}*Env_Alarm_Record;

int main()
{

	struct _Record_Struct* pointer = (struct _Record_Struct*)malloc(sizeof(struct _Record_Struct) * MAX_SIZE);
	
	int sz = sizeof(struct _Record_Struct) * MAX_SIZE;
	                                  // 3 * 2 + 3 = 9
	return 0;
}



//下面代码的结果是（ ）
#include <stdio.h>
#include <string.h>

int main()
{
    unsigned char puc[4];

    struct tagPIM
    {
        unsigned char ucPim1;
        unsigned char ucData0 : 1;
        unsigned char ucData1 : 2;
        unsigned char ucData2 : 3;
    }*pstPimData;

    pstPimData = (struct tagPIM*)puc;
    memset(puc, 0, 4);

    pstPimData->ucPim1 = 2;
    pstPimData->ucData0 = 3;
    pstPimData->ucData1 = 4;
    pstPimData->ucData2 = 5;

    printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
    // 02 29 00 00
    return 0;
}
 



#include <stdio.h>

union Un
{
	short s[7]; // 7*2=14
	// 2 8 2
	int n;
	// 4 4 4
	// 14不是4的倍数 -> 16
};

int main()
{
	printf("%d\n", sizeof(union Un));

	return 0;
}



// 在X86下，有下列程序
#include<stdio.h>

int main()
{
    union
    {
        short k;
        char i[2];
    }*s, a;

    s = &a;
    s->i[0] = 0x39;
    s->i[1] = 0x38;

    printf("%x\n", a.k);

    return 0;
}



// 模拟实现atoi
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <limits.h>

enum State
{
	VALID, // 正常
	INVALID, // 非法
};
enum State state = INVALID;

int my_atoi(const char* str)
{
	// str是NULL
	assert(str);

	// str指向的是空字符串
	if (*str == '\0') 
		return 0; // 返回的是0还是空字符串返回0

	// 跳过空白字符
	while (isspace(*str)) // 如果参数时空白字符，为真，返回非0数字，不是，返回0
	{
		str++;
	}

	// 识别正负数
	int flag = 1;
	if (*str == '+')
	{
		str++;
	}
	else if (*str == '-')
	{
		flag = -1;
		str++;
	}

	// 识别数字字符并转换
	long long ret = 0;
	while (*str)
	{
		if (isdigit(*str)) // 判断数字字符
		{
			ret = ret * 10 + flag * (*str - '0');
			if (ret > INT_MAX || ret < INT_MIN)
			{
				return 0; // 非法返回
			}
			str++;
		}
		else
		{
			state = VALID;
			return (int)ret; // 合法
		}
	}

	state = VALID;
	return (int)ret;
}

int main()
{
	int ret = my_atoi("    -1234abc");
	// my_atoi("    1234"); // 前面有空白字符
	// my_atoi("    +1234"); // 前面+-
	// my_atoi("    +1234abc"); // 非数字字符
	// my_atoi("    123123123123123"); // 给的数字太大了，溢出了

	if (state == VALID)
	{
		printf("合法返回，值为：%d\n", ret);
	}
	else
	{
		printf("非法返回，值为：%d\n", ret);
	}

	return 0;
}



/* 找单身狗
一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
编写一个函数找出这两个只出现一次的数字 */
#include <stdio.h>

void FindNum(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		int flag = 1;
		int j = 0;
		for (j = 0; j < sz; j++)
		{
			if (i == j)
			{
				continue;
			}
			if (arr[i] == arr[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			printf("%d ", arr[i]);
		}
	}
}

int main()
{
	int arr[] = { 1,1,2,2,3,4,4,5,6,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	FindNum(arr, sz);

	return 0;
}


#include <stdio.h>

int main()
{
	int arr[] = { 1,2,3,4,5,1,2,3,4,6 };

	// 1. 把所有数字异或在一起，就是5^6
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = 0;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		ret = ret ^ arr[i];
	}
	
	// 2. 计算ret的二进制的第几位为1
	int pos = 0;
	for (i = 0; i < 32; i++)
	{
		if (((ret >> i) & 1) == 1)
		{
			pos = i;
			break;
		}
	}

	// 3. 按照不相同的位分组
	int m = 0;
	int n = 0;
	for (i = 0; i < sz; i++)
	{
		if (((arr[i] >> pos) & 1) == 1) // arr[i]的第pos位&1如果是1
		{
			m ^= arr[i]; // 1 1 3 3 5
		}
		else
		{
			n ^= arr[i]; // 2 2 4 4 6
		}
	}
	// 分组：
	// 101   5 1 1 3 3
	// 110   6 2 2 4 4

	printf("%d %d\n", m, n);

	return 0;
}



// 交换奇偶位
// 写一个宏，可以将一个整数的二进制位的奇数位和偶数位交换
#include <stdio.h>

#define SWAP_BIT(n) (n=((n&0xaaaaaaaa)>>1)+((n&0x55555555)<<1))
// a - 1010

int main()
{
	int a = 10;
	// 00000000000000000000000000001010 - 10
	
	SWAP_BIT(a);
	printf("a = %d\n", a);
	
	return 0;
}



// offsetof宏
// 写一个宏，计算结构体中某变量相对于首地址的偏移，并给出说明
// 考察：offsetof宏的实现
#include <stdio.h>
#include <stddef.h>

struct Stu
{
	int a; // 0-3
	char c; // 4
	double d; // 8-15 
};

#define OFFSETOF(struct_type, mem_name)  (int)&(((struct_type*)0)->mem_name) 
// 假设地址是0，把0强制类型转换成结构体指针，偏移量就相当于地址    取出成员的地址，偏移量是整数，强制类性转换

int main()
{
	// printf("%d\n", sizeof(struct Stu));
	//printf("%d\n", offsetof(struct Stu, a)); // 0
	//printf("%d\n", offsetof(struct Stu, c)); // 4
	//printf("%d\n", offsetof(struct Stu, d)); // 8

	printf("%d\n", OFFSETOF(struct Stu, a)); // 0
	printf("%d\n", OFFSETOF(struct Stu, c)); // 4
	printf("%d\n", OFFSETOF(struct Stu, d)); // 8

	return 0;
}

