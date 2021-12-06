#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 30");
	while (1)
	{
		printf("30s\n");
		scanf("%s", input);
		if (strcmp(input, "1024") == 0)
		{
			system("shutdown -a");
			break;
		}
	}

	return 0;
}