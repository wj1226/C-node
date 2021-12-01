#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>



//int main()
//{
//	char buf[100] = { 0 };
//	gets(buf);
//
//	int i = 0;
//	int cnt_a = 0;
//	int cnt_b = 0;
//	while (buf[i] != '0')
//	{
//		if (buf[i] == 'A')
//			cnt_a++;
//		else if (buf[i] == 'B')
//			cnt_b++;
//		i++;
//	}
//
//	if (cnt_a > cnt_b)
//		printf("A\n");
//	else if (cnt_a < cnt_b)
//		printf("B\n");
//	else
//		printf("E\n");
//
//	return 0;
//}

//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e2 - *(int*)e1;
//}
//
//int main()
//{
//	int n = 0;
//	int i = 0;
//	int j = 0;
//	int arr[50] = { 0 };
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	qsort(arr, n, 4, cmp_int);
//
//	//for (i = n - 1; i >= n - 5; i--)
//	//{
//	//	printf("%d ", arr[i]);
//	//}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for (i = 10000; i <= 99999; i++)
//	{
//		int j = 0;
//		int sum = 0;
//		for (j = 10; j <= 10000; j *= 10)
//		{
//			sum += (i / j) * (i % j);
//		}
//		if (sum == i)
//		{
//			printf("%d\n", i);
//		}
//	}
//
//	return 0;
//}

//int main()
//{
//	double price = 0.0;
//	int month = 0;
//	int date = 0;
//	double discount = 1.0;
//	int flag = 0;
//	scanf("%lf %d %d %d", &price, &month, &date, &flag);
//
//	if (month == 11 && date == 11)
//	{
//		discount = 0.7;
//	}
//	if (month == 12 && date == 12)
//	{
//		discount = 0.8;
//	}
//
//	price = price * discount - (double)flag * 50;
//
//	if (price < 0.0)
//		price = 0.0;
//
//	printf("%.2lf\n", price);
//
//	return 0;
//}
