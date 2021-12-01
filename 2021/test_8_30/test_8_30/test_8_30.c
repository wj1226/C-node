#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//
//void ReplaceBlank(char* str, int len)
//{
//	int MLen = 0;//计算字符的个数
//	int NumBlank = 0;//计算空格的数组
//	int IndexofMLen = 0;
//	int Indexofnew = 0;
//	int newlen = 0;
//	int i = 0;//从0号下标开始遍历
//	if (str == NULL || len <= 0)
//	{
//		return;
//	} 
//	while(str[i] != '\0')
//	{
//		++MLen;
//		if (str[i] == ' ')
//		{
//			++NumBlank;
//		} 
//		++i;
//	} 
//	newlen = MLen + NumBlank * 2;//a%20b%20c%20d a b c d
//	if (newlen > len)//newlen是扩充后数组的大小，所以一定要小于len原来大小，不然放不下
//	{
//		return;
//	} 
//	IndexofMLen = MLen;
//	Indexofnew = newlen;
//	while (IndexofMLen >= 0 && Indexofnew > IndexofMLen)
//	{
//		if (str[IndexofMLen] == ' ')
//		{
//			str[Indexofnew--] = '0';
//			str[Indexofnew--] = '2';
//			str[Indexofnew--] = '%';
//		} 
//		else
//		{
//			str[Indexofnew--] = str[IndexofMLen];
//		} 
//		--IndexofMLen;
//	}
//} 
//
//int main()
//{
//	char str[30] = "a b c d";
//	int len = (sizeof(str) / sizeof(str[0]));
//	ReplaceBlank(str, len);
//	printf("%s\n", str);
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//void replace(char* arr, char* arr2)
//{
//    while (*arr != '\0')
//    {
//        if (*arr != ' ')
//        {
//            *arr2 = *arr;
//            arr2++;
//        }
//        else
//        {
//            strcpy(arr2, "%20");
//            arr2 += 3;
//        }
//        arr++;
//    }
//}
//
//int main()
//{
//    char arr[20] = "abc defgx yz";
//    char arr2[50] = { 0 };
//    replace(arr, arr2);
//    printf("%s\n", arr2);
//    return 0;
//}


//#include <stdio.h>
//
//int CntNumOne(int n)
//{
//    int count = 0;
//    while (n)
//    {
//        ++count;
//        n = (n - 1) & n;
//    }
//    return count;
//}
//
//int main()
//{
//    printf("%d\n", CntNumOne(-1));
//
//    return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	char killer = 0;
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
//		{
//			//判断表达式 0 1
//			printf("%c\n", killer);
//			break;
//		}
//	}
//
//	return 0;
//}


#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if ((b == 2) + (a == 3) == 1
							&& (b == 2) + (e == 4) == 1
							&& (c == 1) + (d == 2) == 1
							&& (c == 5) + (d == 3) == 1
							&& (e == 4) + (a == 1) == 1)
						{
							if (a * b * c * d * e == 120)
								printf("a=%d,b=%d,c=%d,d=%d,e=%d", a, b, c, d, e);
						}
					}
				}
			}
		}
	}

	return 0;
}


#include <stdio.h>

//int main()
//{
//    int n = 0;
//    while ((scanf("%d", &n)) != EOF)
//    {
//        int i = 0;
//        int j = 0;
//        for (i = 0; i <= n; i++)
//        {
//            for (j = 0; j <= n - i; j++)
//            {
//                printf("* ");
//            }
//            for (j = 0; j < i; j++) //空格 坑
//            {
//                printf(" ");
//            }
//            printf("\n");
//        }
//        for (i = 0; i < n; i++)
//        {
//            for (j = 0; j <= i + 1; j++)
//            {
//                printf("* ");
//            }
//            for (j = 0; j <= n - 1 - i; j++) //空格 坑
//            {
//                printf(" ");
//            }
//            printf("\n");
//        }
//    }
//
//    return 0;
//}


void bubble_sort(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
void print_arr(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	bubble_sort(arr, sz);
	print_arr(arr, sz);

	return 0;
}