#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>

//void* my_memcpy(void* dest, const void* src, size_t count)
//{
//	char* ret = dest;
//	assert(dest && src);
//
//	while (count--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//
//	return ret;
//}
//
//void printf_arr(int* arr2, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//}
//
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[20] = { 0 };
//
//	my_memcpy(arr2, arr1, 10 * sizeof(int));
//
//	int sz = sizeof(arr2) / sizeof(arr2[0]);
//	printf_arr(arr2, sz);
//
//	return 0;
//}



//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	if (*str2 == '\0')
//		return str1;
//
//	char* s1; 
//	char* s2;
//	char* cp = str1;
//
//	while (*cp)
//	{
//		s1 = cp;
//		s2 = str2;
//
//		while (*s1 && *s2 && (*s1 == *s2))
//		{
//			s1++;
//			s2++;
//		}
//
//		if (*s2 == '\0')
//			return cp;
//
//		cp++;
//	}
//
//	return NULL;
//}
//
//int main()
//{
//	char arr1[] = "i am a student";
//	char arr2[] = "student";
//
//	char* ret = my_strstr(arr1, arr2);
//
//	if (ret == NULL)
//	{
//		printf("ÕÒ²»µ½\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//
//	return 0;
//}



//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//
//	while (*dest)
//	{
//		dest++;
//	}
//
//	while (*dest++ = *src++)
//	{
//		;
//	}
//
//	return ret;
//}
//
//
//int main()
//{
//	char arr1[20] = "xxxxxxxx";
//	char arr2[] = "abc";
//
//	my_strcat(arr1, arr2); // ×Ö·û´®×·¼Ó
//
//	printf("%s\n", arr1);
//
//	return 0;
//}



//int my_strcmp(const char* s1, const char* s2)
//{
//	assert(s1 && s2);
//
//	while (*s1 == *s2)
//	{
//		if (*s1 == 0)
//			return 0;
//		s1++;
//		s2++;
//	}
//
//	return *s1 - *s2;
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcq";
//
//	int ret = my_strcmp(arr1, arr2);
//
//	if (ret == 0)
//		printf("\n");
//	else if (ret > 0)
//		printf(">\n");
//	else
//		printf("<\n");
//	printf("%d\n", ret);
//
//	return 0;
//}



//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//
//	while (*dest++ = *src++)
//	{
//		;
//	}
//
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "hello world";
//	char arr2[20] = "xxxxxxxxxx";
//
//	printf("%s\n", my_strcpy(arr2, arr1));
//
//	return 0;
//}



//unsigned int my_strlen(const char* str)
//{
//	assert(str);
//
//	int cnt = 0;
//	while (*str)
//	{
//		cnt++;
//		str++;
//	}
//
//	return cnt;
//}
//
//int main()
//{
//	char arr[] = "hello world";
//
//	printf("%d\n", my_strlen(arr));
//
//	return 0;
//}



