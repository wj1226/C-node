#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//浙大版《C语言程序设计（第3版）》题目集
int sum(int m, int n)
{
    int i = 0;
    int sum = 0;
    for (i = m; i <= n; i++)
    {
        sum += i;
    }
    return sum;

}


int max(int a, int b)
{
    return a > b ? a : b;
}


void pyramid(int n)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            printf(" ");
        }
        for (j = 0; j <= i; j++)
        {
            printf("%d ", i+1);
        }
        printf("\n");
    }
}

int main()
{
    int n;

    scanf("%d", &n);
    pyramid(n);

    return 0;
}


int sign(int x)
{
    if (x > 1)
        return 1;
    else if (x == 0)
        return 0;
    else
        return -1;
}


int even(int n)
{
    if (n % 2 != 0)
        return 0;
    else
        return 1;
}

int OddSum(int List[], int N)
{
    int i = 0;
    int sum = 0;
    for (i = 0; i < N; i++)
    {
        if (List[i] % 2 != 0)
        {
            sum += List[i];
        }
    }
    return sum;
}