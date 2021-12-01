#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//#define MOD(x, y) x%y
//
//int main()
//{
//	int a = 13;
//	int b = 94;
//	printf("%d\n", MOD(b, a + 4));
//
//	return 0;
//}

//int main()
//{
//	const int i = 0;
//	int* j = (int*)&i;
//	*j = 1;
//	printf("%d,%d", i, *j);
//}


//#include <stdio.h>
//#include <math.h>
//
//int narcissistic(int number);
//void PrintN(int m, int n);
//
//int main()
//{
//    int m, n;
//
//    scanf("%d %d", &m, &n);
//    if (narcissistic(m)) printf("%d is a narcissistic number\n", m);
//    PrintN(m, n);
//    if (narcissistic(n)) printf("%d is a narcissistic number\n", n);
//
//    return 0;
//}
//
//
//int cnt_num(int n)
//{
//    int cnt = 0;
//    if (n < 10)
//        cnt = 1;
//    else
//    {
//        while (n)
//        {
//            n /= 10;
//            cnt++;
//        }
//    }
//    return cnt;
//}
//
//int narcissistic(int number)
//{
//    int cnt = cnt_num(number);
//    if (number >= 3)
//    {
//        int i = 0;
//        int sum = 0;
//        int number2 = number;
//        for (i = 0; i < cnt; i++)
//        {
//            sum += (int)pow((number % 10), cnt);
//            number /= 10;
//        }
//        if (sum == number2)
//            return 1;
//    }
//    return 0;
//}
//
//void PrintN(int m, int n)
//{
//    int i = 0;
//    int sum = 0;
//    for (i = m + 1; i < n; i++)
//    {
//        if (narcissistic(i) == 1)
//        {
//            printf("%d\n", i);
//        }
//    }
//}