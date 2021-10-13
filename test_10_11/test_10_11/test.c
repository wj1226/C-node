#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//    unsigned char puc[4];
//
//    struct tagPIM
//    {
//        unsigned char ucPim1;
//        unsigned char ucData0 : 1;
//        unsigned char ucData1 : 2;
//        unsigned char ucData2 : 3;
//    }*pstPimData;
//
//    pstPimData = (struct tagPIM*)puc;
//    memset(puc, 0, 4);
//
//    pstPimData->ucPim1 = 2;
//    pstPimData->ucData0 = 3;
//    pstPimData->ucData1 = 4;
//    pstPimData->ucData2 = 5;
//
//    printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
//
//    return 0;
//}
// 画图


//#include <stdio.h>
//
//union Un
//{
//	short s[7]; // 7*2=14
//	// 2 4 2
//	int n;
//	// 4 4 4
//	// 16
//};
//
//int main()
//{
//	printf("%d\n", sizeof(union Un));
//
//	return 0;
//}
// ???????????????????????????????


// 在X86下，有下列程序
//#include<stdio.h>
//
//int main()
//{
//    union
//    {
//        short k;
//        char i[2];
//    }*s, a;
//
//    s = &a;
//    s->i[0] = 0x39;
//    s->i[1] = 0x38;
//
//    printf("%x\n", a.k);
//
//    return 0;
//}
// ?????????????


// 模拟实现atoi
//#include <stdio.h>
//#include <assert.h>
//#include <ctype.h>
//#include <limits.h>
//
//enum State
//{
//	VALID, // 正常
//	INVALID, // 非法
//};
//enum State state = INVALID;
//
//int my_atoi(const char* str)
//{
//	// str是NULL
//	assert(str);
//
//	// str指向的是空字符串
//	if (*str == '\0')
//		return 0;
//
//	// 跳过空白字符
//	while (isspace(*str)) // 如果参数时空白字符 为真 不是，返回0
//	{
//		str++;
//	}
//
//	// 识别正负数
//	int flag = 1;
//	if (*str == '+')
//	{
//		str++;
//	}
//	else
//	{
//		flag = -1;
//		str++;
//	}
//
//	// 转化
//	long long ret = 0;
//	while (*str)
//	{
//		if (isdigit(*str)) // 判断数字字符
//		{
//			ret = ret * 10 + flag*(*str - '0');
//			if (ret > INT_MAX || ret < INT_MIN)
//			{
//				return 0; // 非法返回
//			}
//			str++;
//		}
//		else
//		{
//			state = VALID;
//			return (int)ret; // 合法
//		}
//	}
//
//	state = VALID;
//	return (int)ret;
//}
//
//int main()
//{
//	int ret = my_atoi("    -1234abc");
//	if (state == VALID)
//	{
//		printf("合法返回，值为：%d\n", ret);
//	}
//	else
//	{
//		printf("非法返回，值为：%d\n", ret);
//	}
//
//	//??????????????????
//
//	return 0;
//}


//#include <stdio.h>
//
//#define SWAP_BIT(n) (n=((n&0xaaaaaaaa)>>1)+((n&0x55555555)<<1))
//
//int main()
//{
//	int a = 10;
//	
//	SWAP_BIT(a);
//	printf("a=%d\n", a);
//	
//	return 0;
//}

 