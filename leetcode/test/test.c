#include <stdio.h>

int main()
{
	int y = 10;
	do {
		y--;
	} while (--y);
	printf("%d", y--);
	return 0;
}
