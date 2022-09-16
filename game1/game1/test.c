#define _CRT_SECURE_NO_WARNINGS 1

//��������Ϸ���


#include "game.h"

void menu()//�˵�����
{
	printf("**************************\n");
	printf("***  1.play    0.exit  ***\n");
	printf("**************************\n");
}

void game()//��Ϸ����
{
	char ret = 0;
	char board[ROW][COL] = { 0 };

	Initboard(board, ROW, COL);

	Displayboard(board, ROW, COL);

	while (1)
	{
		//�����
		PlayerMove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

		//������
		ComputerMove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	//����ѭ�������������
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else if (ret == 'Q')
	{
		printf("ƽ��\n");
	}
}

void test()//��ܺ���
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��(1/0))>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}