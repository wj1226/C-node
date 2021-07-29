#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

// 初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}


// 打印棋盘
// 11*11下标0-11  里面9*9棋盘是1-9 从1开始
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	for (i = 0; i <= 9; i++) // 打印列号
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++) // 从1开始 小于等于9
	{
		int j = 0;
		printf("%d ", i); // 打印行号
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("----------------------\n");
}


// 布置雷
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;

	while (count)
	{
		// 1. 生成随机值下标
		// main函数里调rand
		int x = rand() % row + 1; // row是9 %9是0-8 加一是1-9
		int y = rand() % col + 1;

		if (board[x][y] != '1')
		{
			board[x][y] = '1'; // 判断如果没有雷 放置雷
			count--; // 放置成功--
		}
	}
}


// 排查雷
int GetMineCount(char mine[ROWS][COLS], int x, int y) // 计算雷的个数
{
	// 都是字符 减字符0就是数字 一周8个
	return (mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0');
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - EASY_COUNT) // 71
	{
		printf("请输入要排查的坐标:>\n");
		scanf("%d %d", &x, &y);
		// 判断坐标是否合法
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾你被炸死了\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				int count = GetMineCount(mine, x, y); // 算周围有几个雷
				show[x][y] = count + '0'; // 例'3'-'0'=3 打印的是字符 所以要加字符0
				DisplayBoard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("坐标非法，重新输入\n");
		}
	}

	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功\n");
		DisplayBoard(mine, ROW, COL);
	}
}