#define _CRT_SECURE_NO_WARNINGS 1

#include <windows.h>
#include "game.h"

//��Ϸ���ܾ���ʵ��

//��������

void Initboard(char board[ROW][COL], int row, int col)//��ʼ�����̣�������ٴ���Ϸ֮ǰ������̣�
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


void Displayboard(char board[ROW][COL], int row, int col)//��ӡ����
{
	int i = 0;
	for (i = 0; i < row; i++)//һ������ + һ�зָ��� Ϊ 1 row
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

	printf("�����\n");
	
	
	while (1)
	{
		printf("���������ӵ�����>:");
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
				printf("��������������\n");
			}
		}
		else
		{
			printf("����Ƿ�������������");
		}
	}	
	
}


void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������...\n");
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
			/*��if (board[i][j] != ' ')
				return 1;
			else
				return 0;*/
			if (board[i][j] == ' ')//ֻҪ��һ������Ϊ�գ���Ϸ����
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
