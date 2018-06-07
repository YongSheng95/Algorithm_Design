/*
*Copyright (c) 2018,UESTC
*All rights reserved.
*
*摘 要：用动态规划算法实现矩阵链最优加括号的方式
*作 者：玉宇
*日 期：2018年5月24日
*/
#include "stdafx.h"
#include<iostream>
#include<iomanip>
const int N = 9;
int s[N][N], m[N][N];
void MatrixChain(int *p, int n, int(*m)[N], int(*s)[N])
{
	/*
	p:矩阵链表
	n:矩阵链表的长度
	m:记录矩阵链表最优的计算次数（矩阵连成计算次数最少）
	s:记录矩阵链表取最优计算次数时的子链切分点
	*/
	for (int i = 1; i <= n ; i++)
		m[i][i] = 0;
	for (int r = 2; r <= n; r++)
	{
		for (int i = 1; i <= n - r + 1; i++)
		{
			int j = i + r - 1;
			m[i][j] = m[i + 1][j] + p[i-1] * p[i] * p[j];
			s[i][j] = i;
			for (int k = i + 1; k < j; k++)
			{
				int t = m[i][k] + m[k + 1][j] + p[i-1] * p[k] * p[j];
				if (t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
}
void TrackBack(int(*s)[N], int i, int j)
{
	if (i == j)
		return;
	TrackBack(s, i, s[i][j]);
	TrackBack(s, s[i][j] + 1, j);
	std::cout << "[" << i << "," << s[i][j] << "]," << "[" <<
		s[i][j] + 1 << "," << j << "]" << std::endl;
}

void PrintTable(int(*t)[N])
{
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			std::cout << std::setw(6) << t[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
