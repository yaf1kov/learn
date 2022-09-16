#define _CRT_SECURE_NO_WARNINGS 1

#include <windows.h>
#include "game.h"

//游戏功能具体实现

//函数定义

void Initboard(char board[ROW][COL], int row, int col)//初始化棋盘（★或在再次游戏之前清空棋盘）
{
	int i = 0;
	int j = 0;

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			board[i][j] = ' ';
		}
	}
}


//void Displayboard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		if (i < row - 1) 
//		{
//			printf("---|---|---\n");
//		}
//	}
//}


void Displayboard(char board[ROW][COL], int row, int col)//打印棋盘
{
	int i = 0;
	for (i = 0; i < row; i++)//一行数据 + 一行分割行 为 1 row
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
			else
				printf("\n");
			
		}
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
				else
					printf("\n");
			}
		}
	}
}


void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("玩家走\n");
	
	
	while (1)
	{
		printf("请输入落子的坐标>:");
		scanf("%d%d", &x, &y);
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;

			}
			else
			{
				printf("该坐标已有棋子\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入");
		}
	}	
	
}


void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走...\n");
	Sleep(2000);

	while (1)
	{
		x = rand() % row;
		y = rand() & col;
		if (board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = '#';
			break;
		}
	}
}


int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			/*★if (board[i][j] != ' ')
				return 1;
			else
				return 0;*/
			if (board[i][j] == ' ')//只要有一个格子为空，游戏继续
				return 0;
		}
	}
	return 1;
}
 

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	
	for (i = 0; i < col; i++)
	{
		if ((board[0][i] == board[1][i] && board[1][i] == board[2][i]) && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}

	if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) && board[0][0] != ' ')
	{
		return board[0][0];
	}

	if ((board[0][2] == board[1][1] && board[1][1] == board[2][0]) && board[0][2] != ' ')
	{
		return board[0][2];
	}
	
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}

	return 'C';
}
