#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//void InitBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		int j = 0;
//		for (j = 0; j < col; j++)
//		{
//			board[i][j] = ' ';
//		}
//	}
//}
//
//void DisPlayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		int j = 0;
//		for (j = 0; j < col; j++)
//		{
//			printf(" %c ", board[i][j]);
//			if (j < col - 1)
//				printf("|");
//		}
//		printf("\n");
//		if (i < row - 1)
//		{
//			for (j = 0; j < col; j++)
//			{
//				printf("---");
//				if (j < col - 1)
//					printf("|");
//			}
//		}
//		printf("\n");
//	}
//}
//
//void PlayerMove(char board[ROW][COL], int row, int col)
//{
//	printf("玩家走:>\n");
//	int x = 0;
//	int y = 0;
//	while (1)
//	{
//		printf("请输入坐标:>\n");
//		scanf("%d %d", &x, &y);
//		if (x >= 1 && x <= row && y >= 1 && y <= col)
//		{
//			if (board[x - 1][y - 1] == ' ')
//			{
//				board[x - 1][y - 1] = '*';
//				break;
//			}
//			else
//			{
//				printf("坐标被占用，请重新输入:>\n");
//			}
//		}
//		else
//		{
//			printf("坐标非法，请重新输入:>\n");
//		}
//	}
//}
//
//void ComputerMove(char board[ROW][COL], int row, int col)
//{
//	printf("电脑走:>\n");
//	int x = 0;
//	int y = 0;
//	while (1)
//	{
//		x = rand() % row;
//		y = rand() % col;
//		if (board[x][y] == ' ')
//		{
//			board[x][y] = '#';
//			break;
//		}
//	}
//}
//
//IsFull(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		int j = 0;
//		for (j = 0; j < col; j++)
//		{
//			if (board[i][j] == ' ')
//				return 0;
//		}
//	}
//	return 1;
//}
//
//char IsWin(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
//			return board[i][0];
//	}
//	for (i = 0; i < col; i++)
//	{
//		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
//			return board[0][i];
//	}
//	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
//		return board[1][1];
//	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
//		return board[1][1];
//	if (IsFull(board, row, col))
//	{
//		return 'Q';
//	}
//	return 'C';
//}




//void InitBoard(char board[ROWS][COLS], int rows, int cols, int set)
//{
//	int i = 0;
//	for (i = 0; i < rows; i++)
//	{
//		int j = 0;
//		for (j = 0; j < cols; j++)
//		{
//			board[i][j] = set;
//		}
//	}
//}
//
//void DisPlayBoard(char board[ROWS][COLS], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i <= row; i++)
//	{
//		printf("%d ", i);
//	}
//	printf("\n");
//	for (i = 1; i <= row; i++)
//	{
//		printf("%d ", i);
//		for (j = 1; j <= col; j++)
//		{
//			printf("%c ", board[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void SetMine(char board[ROWS][COLS], int row, int col)
//{
//	int count = EASY_COUNT;
//	while (count)
//	{
//		int x = rand() % row + 1;
//		int y = rand() % col + 1;
//		if (board[x][y] != '1')
//		{
//			board[x][y] = '1';
//			count--;
//		}
//	}
//}
//
//int GetMineCount(char mine[ROWS][COLS], int x, int y)
//{
//	return (mine[x - 1][y] +
//		mine[x - 1][y - 1] +
//		mine[x][y - 1] +
//		mine[x + 1][y - 1] +
//		mine[x + 1][y] +
//		mine[x + 1][y + 1] +
//		mine[x][y + 1] +
//		mine[x - 1][y + 1]) - 8 * '0';
//}
//void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
//{
//	int x = 0;
//	int y = 0;
//	int win = 0;
//	while (win < row * col - EASY_COUNT)
//	{
//		printf("请输入要排查的坐标:>\n");
//		scanf("%d %d", &x, &y);
//		if (x >= 1 && x <= row && y >= 1 && y <= col)
//		{
//			if (mine[x][y] == '1')
//			{
//				printf("很遗憾，你被炸死了\n");
//				DisPlayBoard(mine, ROW, COL);
//				break;
//			}
//			else
//			{
//				int count = GetMineCount(mine, x, y);
//				show[x][y] = count + '0';
//				DisPlayBoard(show, ROW, COL);
//				win++;
//			}
//		}
//		else
//		{
//			printf("坐标非法，请重新输入:>\n");
//		}
//	}
//	if (win == row * col - EASY_COUNT)
//	{
//		printf("恭喜你，排雷成功！\n");
//		DisPlayBoard(show, ROW, COL);
//	}
//}