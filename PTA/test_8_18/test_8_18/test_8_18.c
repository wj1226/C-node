#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int prime(int p)
{
    if (p <= 1)
        return 0;
    if (p == 2)
        return 1;
    int i = 0;
    for (i = 2; i < p; i++)
    {
        if (p % i == 0)
            return 0;
    }
    if (i == p)
        return 1;
}


int PrimeSum(int m, int n)
{
    int i = 0;
    int j = 0;
    int sum = 0;
    for (i = m; i <= n; i++)
    {
        int flag = 1;
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
                flag = 0;
        }
        if (flag == 1)
            sum += i;
    }
    return sum;
}


int CountDigit(int number, int digit)
{
    int count = 0;

    if (number < 0)
        number *= -1;

    while (number > 10)
    {
        if (number % 10 == digit)
            count++;
        number /= 10;
    }

    if (number == digit)
        count++;

    return count;
}