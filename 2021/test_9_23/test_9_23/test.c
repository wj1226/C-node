#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//void FindNum(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		int flag = 1;
//		int j = 0;
//		for (j = 0; j < sz; j++)
//		{
//			if (i == j)
//			{
//				continue;
//			}
//			if (arr[i] == arr[j])
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 1)
//		{
//			printf("%d ", arr[i]);
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,1,2,2,3,4,4,5,6,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	FindNum(arr, sz);
//
//	return 0;
//}



//#include <stdio.h>
//#include <assert.h>
//
//void* my_strncat(char* dest, const char* src, size_t count)
//{
//	assert(dest && src);
//	char* ret = dest;
//
//	while (*dest)
//	{
//		dest++;
//	}
//
//	while (count)
//	{
//		*dest++ = *src++;
//		count--;
//	}
//	*dest = '\0';
//
//	return ret;
//}
//
//int main()
//{
//	char arr1[30] = "xxxxxxx";
//	char arr2[] = "abcd";
//
//	my_strncat(arr1, arr2, 3);
//
//	printf("%s", arr1);
//
//	return 0;
//}


//#include <stdio.h>
//#include <assert.h>
//
//char* my_strncpy(char* dest, const char* src, size_t count)
//{
//	assert(dest && src);
//	char* ret = dest;
//
//	while (count)
//	{
//		*dest++ = *src++;
//		count--;
//	}
//	*dest = '\0';
//
//	return ret;
//}
//
//int main()
//{
//	char arr1[30] = "xxxxxxxx";
//	char arr2[] = "abcdef";
//
//	my_strncpy(arr1, arr2, 5);
//
//	printf("%s\n", arr1);
//
//	return 0;
//}

//int main()
//{
//    unsigned char puc[4];
//
//    struct t
//    {
//        unsigned char ucPim1;
//        unsigned char ucData0 : 1;
//        unsigned char ucData1 : 2;
//        unsigned char ucData2 : 3;
//    }*S;
//
//    S = (struct t*)puc;
//
//    memset(puc, 0, 4);
//
//    S->ucPim1 = 2;
//    S->ucData0 = 3;
//    S->ucData1 = 4;
//    S->ucData2 = 5;
//    
//    printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
//
//    return 0;
//}