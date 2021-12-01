#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	char arr[1000] = { 0 };
//	int a[] = { 0,1,2,3,4,5,6,7,8,9 };
//	int b[10] = { 0 }; // 存放个数
//	scanf("%s", arr);
//	int len = strlen(arr);
//	for (i = 0; i < len; i++) // 遍历数组
//	{
//		for (j = 0; j < 10; j++)
//		{
//			if (a[j] == arr[i] - '0') // 减字符0，得到数字
//			{
//				b[j]++; // 对应位置++
//				break;
//			}
//		}
//	}
//	for (i = 0; i < 10; i++)
//	{
//		if (b[i] != 0)
//		{
//			printf("%d:%d\n", i, b[i]);
//		}
//	}
//
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	long long arr[1000] = { 0 };
//	int test1[1000] = { 0 };
//	int test2[1000] = { 0 };
//	scanf("%d", &n);
//
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%lld %d %d", &arr[i], &test1[i], &test2[i]);
//	}
//
//	int m = 0;
//	scanf("%d", &m);
//	int find = 0;
//	for (i = 0; i < m; i++)
//	{
//		scanf("%d", &find);
//		int j = 0;
//		for (j = 0; j < n; j++)
//		{
//			if (find == test1[j])
//			{
//				printf("%lld %d\n", arr[j], test2[j]);
//				break;
//			}
//		}
//	}
//
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	int i = 0;
//	int top = 0;
//	int bottom = 0;
//	double sum = 0.0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d/%d", &top, &bottom);
//		sum += top / bottom;
//	}
//	
//
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//
////int cmp_double(const void* e1, const void* e2)
////{
////	return *(double*)e1 < *(double*)e2 ? 1 : -1;
////}
//
//int main()
//{
//	int n = 0; // 共多少个学生
//	int k = 0; // 每份作业的评审数
//	int m = 0; // 需要输出个数
//
//	scanf("%d %d %d", &n, &k, &m);
//
//	int score = 0;
//
//	double arr[10000] = { 0 };
//
//	int i = 0;
//	int j = 0;
//	int e = 0;
//	for (i = 0; i < n; i++)
//	{
//		int max = 0;
//		int min = 100;
//		int sum = 0;
//		double avg = 0.0;
//
//		for (j = 0; j < k; j++)
//		{
//			scanf("%d", &score);
//			if (max < score)
//				max = score;
//			if (min > score)
//				min = score;
//			sum += score;
//		}
//		sum = sum - max - min;
//		avg = sum / 3.0;
//		arr[e++] = avg;
//	}
//
//	//int sz = sizeof(arr) / sizeof(arr[0]);
//	//qsort(arr, sz, sizeof(arr[0]), cmp_double);
//
//	for (i = 0; i < m; i++)
//	{
//		printf("%.3lf ", arr[i]);
//	}
//
//	return 0;
//}