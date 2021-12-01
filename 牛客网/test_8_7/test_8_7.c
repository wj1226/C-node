#define _CRT_SECURE_NO_WARNINGS 1

//test
//输入年月输出月的天数
#include <stdio.h>

int is_leap_year(int year)
{
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
	{
		return 1;
	}
	else
		return 0;
}

int main()
{
	int year = 0;
	int month = 0;
	while ((scanf("%d %d", &year, &month)) != EOF)
	{
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			printf("31\n");
			break;
		case 2:
			if (is_leap_year(year))
			{
				printf("29\n");
				break;
			}
			else
			{
				printf("28\n");
				break;
			}
		case 4:
		case 6:
		case 9:
		case 11:
			printf("30\n");
			break;
		default:
			break;
		}
	}

	return 0;
}

