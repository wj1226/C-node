#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	double num = 0;
//	double avg = 0.0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%lf", &num);
//		avg += 1.0 / num;
//	}
//	avg /= n;
//	
//	printf("%.2f", 1 / avg);
//
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//    printf("To iterate is human, to recurse divine.");
//    return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//    int n = 0; // 总字数
//    int k = 0; // 每分钟能看的字数
//    int m = 0; // minute
//
//    scanf("%d %d %d", &n, &k, &m);
//    printf("%d", n - (k * m));
//
//    return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//    int date = 0;
//    scanf("%d", &date);
//
//    if (date / 100 < 22)
//    {
//        if (date / 100 >= 1000)
//            printf("%d-%02d", date / 100, date % 100);
//        else
//            printf("20%02d-%02d", date / 100, date % 100);
//    }
//    else
//    {
//        if (date / 100 >= 1000)
//            printf("%d-%02d", date / 100, date % 100);
//        else
//            printf("19%02d-%02d", date / 100, date % 100);
//    }
//
//    return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	double price = 0.0;
//	int i = 0;
//	scanf("%d %d", &n, &m);
//
//	for (i = 0; i < n; i++)
//	{
//		scanf("%lf", &price);
//		if ((double)m > price)
//			printf("On Sale! %.1lf\n", price);
//	}
//
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	int arr[24] = { 0 };
//	int _time = 0;
//	int i = 0;
//	for (i = 0; i < 24; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	while (1)
//	{
//		scanf("%d", &_time);
//		if (_time < 0 || _time > 23)
//			break;
//		if (arr[_time] > 50)
//			printf("%d Yes\n", arr[_time]);
//		else
//			printf("%d No\n", arr[_time]);
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
//	int arr[20000] = { 0 };
//	scanf("%d", &n);
//	for(i=0; i<n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int max = arr[0];
//	int min = arr[0];
//	for (i = 0; i < n; i++)
//	{
//		if (max < arr[i])
//			max = arr[i];
//		if (min > arr[i])
//			min = arr[i];
//	}
//	int cnt1 = 0;
//	int cnt2 = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (max == arr[i])
//			cnt1++;
//		if (min == arr[i])
//			cnt2++;
//	}
//	printf("%d %d\n", min, cnt2);
//	printf("%d %d\n", max, cnt1);
//
//	return 0;
//}


//bug
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char* arr1[] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
//	char* arr2[100] = { 0 };
//	int num = 0;
//	int i = 0;
//	scanf("%d", &num);
//	while (num)
//	{
//		if (num < 0)
//		{
//			arr2[i++] = "fu";
//			arr2[i++] = arr1[num % 10];
//			num /= 10;
//		}
//		else
//		{
//			arr2[i++] = arr1[num % 10];
//			num /= 10;
//		}
//	}
//
//	int len = strlen(arr2);
//	int left = 0; //'a'
//	int right = len - 1; //'f'
//
//	while (left < right)
//	{
//		char tmp = arr2[left];
//		arr2[left] = arr2[right];
//		arr2[right] = tmp;
//		left++;
//		right--;
//	}
//
//	for (i = 0; i < len; i++)
//	{
//		printf("%s ", arr2[i]);
//	}
//
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	int hh = 0;
//	int mm = 0;
//	scanf("%d:%d", &hh, &mm);
//	if (hh > 12)
//	{
//		int times = hh - 12;
//		if (mm > 0)
//		{
//			times += 1;
//		}
//		while (times--)
//		{
//			printf("Dang");
//		}
//	}
//	else
//	{
//		printf("Only %02d:%02d.  Too early to Dang.", hh, mm);
//	}
//
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    int i = 0;
//    int arr[1000] = {0};
//    scanf("%d", &n);
//    for(i=0; i<n; i++)
//    {
//        scanf("%d", &arr[i]);
//        int j = 0;
//        int flag = 1;
//        for(j=0; j<i; j++)
//        {
//            if(arr[i] == arr[j])
//            {
//                flag = 0;
//                break;
//            }
//        }
//        if(flag == 1)
//        {
//            printf("%d ", arr[i]);
//        }
//    }
//
//    return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    int m = 0;
//    int arr[10][10] = { 0 };
//    scanf("%d %d", &n, &m);
//    int i = 0;
//    int j = 0;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < m; j++)
//        {
//            scanf("%d", &arr[i][j]);
//        }
//    }
//    int k = 0;//操作的次数
//    scanf("%d", &k);
//    char t = 0;
//    int a = 0;
//    int b = 0;
//    for (i = 0; i < k; i++)
//    {
//        //每一次操作的过程
//        scanf(" %c %d %d", &t, &a, &b); //消除\n
//        if (t == 'r') //交换行
//        {
//            for (j = 0; j < m; j++)
//            {
//                int tmp = arr[a - 1][j];
//                arr[a - 1][j] = arr[b - 1][j];
//                arr[b - 1][j] = tmp;
//            }
//        }
//        else if (t == 'c') //交换列
//        {
//            for (j = 0; j < n; j++)
//            {
//                int tmp = arr[j][a - 1];
//                arr[j][a - 1] = arr[j][b - 1];
//                arr[j][b - 1] = tmp;
//            }
//        }
//    }
//
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < m; j++)
//        {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//
//    return 0;
//}


#include <stdio.h>

int main()
{
	int n = 0;
	int arr[30][30] = { 0 };
	scanf("%d", &n);
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (j == 0)
				arr[i][j] = 1;
			if (i == j)
				arr[i][j] = 1;
			if (i >= 2 && j >= 1)
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}