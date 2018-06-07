/*
*Copyright (c) 2018,UESTC
*All rights reserved.
*
*ժ Ҫ���ö�̬�滮�㷨ʵ�־��������ż����ŵķ�ʽ
*�� �ߣ�����
*�� �ڣ�2018��5��24��
*/
#include "stdafx.h"
#include<iostream>
#include<iomanip>
const int N = 9;
int s[N][N], m[N][N];
void MatrixChain(int *p, int n, int(*m)[N], int(*s)[N])
{
	/*
	p:��������
	n:��������ĳ���
	m:��¼�����������ŵļ���������������ɼ���������٣�
	s:��¼��������ȡ���ż������ʱ�������зֵ�
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
