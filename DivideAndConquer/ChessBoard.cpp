/*
*Copyright (c) 2018,UESTC
*All rights reserved.
*
*摘 要：棋盘覆盖问题
*作 者：玉宇
*日 期：2018年4月1日
*/
#include "stdafx.h"
#include<iostream>
#include<iomanip>

const int N = 16;
int board[N][N];
int t = 1;

void ChessBoard(int(*arr)[N], int dr, int dc, int tr, int tc, int size)
{
//tr : 棋盘左上角方格的行号
//tc : 棋盘左上角方格的列号
//dr : 特殊方格所在的行号
//dc : 特殊方格所在的列号
//size : 方形棋盘的边长
	int s;
	if (size == 1)
		return;
	if (size > 1)
	{

		s = size / 2;
		if (dr <= (tr + s - 1) && dc <= (tc + s - 1))/*特殊方块在左上部分*/
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
		if (dr <= (tr + s - 1) && dc > (tc + s - 1))/*特殊方块在右上部分*/
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
		if (dr > (tr + s - 1) && dc <= (tc + s - 1))/*特殊方块在左下方*/
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
		if (dr > (tr + s - 1) && dc > (tc + s - 1))/*特殊方块在右下方*/
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