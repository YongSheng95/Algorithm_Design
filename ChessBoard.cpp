/*
*Copyright (c) 2018,UESTC
*All rights reserved.
*
*ժ Ҫ�����̸�������
*�� �ߣ�����
*�� �ڣ�2018��4��1��
*/
#include "stdafx.h"
#include<iostream>
#include<iomanip>

const int N = 16;
int board[N][N];
int t = 1;

void ChessBoard(int(*arr)[N], int dr, int dc, int tr, int tc, int size)
{
//tr : �������ϽǷ�����к�
//tc : �������ϽǷ�����к�
//dr : ���ⷽ�����ڵ��к�
//dc : ���ⷽ�����ڵ��к�
//size : �������̵ı߳�
	int s;
	if (size == 1)
		return;
	if (size > 1)
	{

		s = size / 2;
		if (dr <= (tr + s - 1) && dc <= (tc + s - 1))/*���ⷽ�������ϲ���*/
		{
			arr[tr + s - 1][tc + s] = t;
			arr[tr + s][tc + s] = t;
			arr[tr + s][tc + s - 1] = t;
			t++;
			ChessBoard(arr, dr, dc, tr, tc, s);
			ChessBoard(arr, tr + s - 1, tc + s, tr, tc + s, s);
			ChessBoard(arr, tr + s, tc + s, tr + s, tc + s, s);
			ChessBoard(arr, tr + s, tc + s - 1, tr + s, tc, s);
		}
		if (dr <= (tr + s - 1) && dc > (tc + s - 1))/*���ⷽ�������ϲ���*/
		{
			arr[tr + s - 1][tc + s - 1] = t;
			arr[tr + s][tc + s - 1] = t;
			arr[tr + s][tc + s] = t;
			t++;
			ChessBoard(arr, dr, dc, tr, tc + s, s);
			ChessBoard(arr, tr + s - 1, tc + s - 1, tr, tc, s);
			ChessBoard(arr, tr + s, tc + s - 1, tr + s, tc, s);
			ChessBoard(arr, tr + s, tc + s, tr + s, tc + s, s);
		}
		if (dr > (tr + s - 1) && dc <= (tc + s - 1))/*���ⷽ�������·�*/
		{
			arr[tr + s - 1][tc + s - 1] = t;
			arr[tr + s - 1][tc + s] = t;
			arr[tr + s][tc + s] = t;
			t++;
			ChessBoard(arr, dr, dc, tr + s, tc, s);
			ChessBoard(arr, tr + s - 1, tc + s - 1, tr, tc, s);
			ChessBoard(arr, tr + s - 1, tc + s, tr, tc + s, s);
			ChessBoard(arr, tr + s, tc + s, tr + s, tc + s, s);
		}
		if (dr > (tr + s - 1) && dc > (tc + s - 1))/*���ⷽ�������·�*/
		{
			arr[tr + s - 1][tc + s] = t;
			arr[tr + s - 1][tc + s - 1] = t;
			arr[tr + s][tc + s - 1] = t;
			t++;
			ChessBoard(arr, dr, dc, tr + s, tc + s, s);
			ChessBoard(arr, tr + s - 1, tc + s, tr, tc + s, s);
			ChessBoard(arr, tr + s - 1, tc + s - 1, tr, tc, s);
			ChessBoard(arr, tr + s, tc + s - 1, tr + s, tc, s);
		}
	}
}

//int main()
//{
//	int dr, dc;
//	std::cout << "please input dr(0<dr<"<< N <<"):";
//	std::cin >> dr;
//	std::cout << "please input dc(0<dc<" << N << "):";
//	std::cin >> dc;
//	board[dr][dc] = 0;
//	ChessBoard(board, dr, dc, 0, 0, N);
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			std::cout << std::setw(4) << board[i][j];
//		}
//		std::cout <<"\n";
//	}
//}