/*
*Copyright (c) 2018,UESTC
*All rights reserved.
*
*ժ Ҫ����Dijkstra�㷨ʵ�ֵ�Դ���·��
*�� �ߣ�����
*�� �ڣ�2018��4��22��
*/
#include "stdafx.h"
#include<iostream>
#include<iomanip>
#define VertexNum 6
#define MaxInt 9999
void Dijkstra(int n, int v, int dist[], int prev[], int (*c)[VertexNum])
{
 /* n:ͼ�Ķ�����Ŀ
	v:Դ��������
	dist[]:��ŵ�ǰ�ҵ��Ĵ�Դ��v��ÿ��v(i)�����·����Ȩֵ
	prev[]:��Դ�㵽����������·���ϸö����ǰһ��������
	c:����ͼ
 */
	bool s[VertexNum];
	for (int i = 0; i < n; i++)
	{
		dist[i] = c[v][i];//c[v][i]�Ǳ�[v,i]��Ȩ
		s[i] = false;
		if (dist[i] == MaxInt)
		{
			prev[i] = -1;
		}
		else
		{
			prev[i] = 1;
		}
	}
	dist[v] = 0;
	s[v] = true;
	for (int j = 1; j < n; j++)
	{
		int temp = MaxInt;
		int u = v;
		for (int k = 0; k < n; k++)//V-S��Ѱ����С��dist[k]
		{
			if (!s[k] && (dist[k] < temp))
			{
				u = k;
				temp = dist[k];
			}
		}
		s[u] = true;//���u������·��
		for (int k = 0; k < n; k++)
		{
			if (!s[k] && (c[u][k] < MaxInt))
			{
				int newdist = dist[u] + c[u][k];
				if (newdist < dist[k])
				{
					dist[k] = newdist;//�и��ƣ����޸�V-S�е�dist[k]
					prev[k] = u;
				}
			}
		}
	}
}

//int main()
//{
//	//�ڽӾ����ʾ����ͼ
//	int c[VertexNum][VertexNum] = { { 9999, 9999, 10, 9999, 30, 100 },
//	{ 9999, 9999, 5, 9999, 9999, 9999 }, { 9999, 9999, 9999, 50, 9999, 9999 },
//	{ 9999, 9999, 9999, 9999, 9999, 10 }, { 9999, 9999, 9999, 20, 9999, 60 },
//	{ 9999, 9999, 9999, 9999, 9999, 9999 } };
//	int dist[VertexNum];
//	int prev[VertexNum];
//	std::cout << "Matrix:" << std::endl;
//	for(int i = 0; i < VertexNum;i++ )
//	{
//		for (int j = 0; j < VertexNum; j++)
//		{
//			std::cout << std::setw(4)<< c[i][j] << " ";
//		}
//		std::cout << std::endl;
//	}
//	std::cout << std::endl;
//	std::cout << "Run Dijkstra" << std::endl;
//	Dijkstra(VertexNum, 0, dist, prev, c);
//	std::cout << "dist[]: ";
//	for (int i = 0; i < VertexNum; i++)
//	{
//		std::cout << std::setw(4) << dist[i]<<" ";
//	}
//	std::cout << std::endl;
//	std::cout << "prev[]: ";
//	for (int i = 0; i < VertexNum; i++)
//	{
//		std::cout << std::setw(4) << prev[i]<<" ";
//	}
//	std::cout << std::endl;
//}