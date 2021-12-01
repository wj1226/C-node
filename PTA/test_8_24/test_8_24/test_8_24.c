#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

// 习题5 - 6 使用函数输出水仙花数
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


//#include <math.h>
//
//double f(int n, double a[], double x)
//{
//    int i = 0;
//    double sum = 0.0;
//    for (i = 0; i <= n; i++)
//    {
//        sum += a[i] * (pow(x, i));
//    }
//    return sum;
//}


//int Sum(int List[], int N)
//{
//    int i = 0;
//    int sum = 0;
//    for (i = 0; i < N; i++)
//    {
//        sum += List[i];
//    }
//    return sum;
//}


//int Sum(int List[], int N)
//{
//    int i = 0;
//    int sum = 0;
//    for (i = 0; i < N; i++)
//    {
//        sum += List[i];
//    }
//    return sum;
//}


//ElementType Max(ElementType S[], int N)
//{
//    int i = 0;
//    ElementType max = S[0];
//    for (i = 0; i < N; i++)
//    {
//        if (max < S[i])
//            max = S[i];
//    }
//    return max;
//}


#include <stdio.h>
#include <math.h>

int IsTheNumber(const int N);

int main()
{
    int n1, n2, i, cnt;

    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for (i = n1; i <= n2; i++) {
        if (IsTheNumber(i))
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

int IsTheNumber(const int N)
{
    int n = (int)sqrt(N);
    if (N == pow(n, 2))
    {
        int count = 0;
        int i = 0;
        int N2 = N;
        int arr[10] = { 0 };
        while (N2)
        {
            arr[i++] = N2 % 10;
            N2 /= 10;
            count++;
        }
        for (i = 0; i < count - 1; i++)
        {
            int j = 0;
            for (j = i + 1; j < count; j++)
            {
                if (arr[i] == arr[j])
                    return 1;
            }
        }
    }
    return 0;
}