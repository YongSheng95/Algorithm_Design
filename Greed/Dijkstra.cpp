/*
*Copyright (c) 2018,UESTC
*All rights reserved.
*
*摘 要：用Dijkstra算法实现单源最短路径
*作 者：玉宇
*日 期：2018年4月22日
*/
#include "stdafx.h"
#include<iostream>
#include<iomanip>
#define VertexNum 6
#define MaxInt 9999
void Dijkstra(int n, int v, int dist[], int prev[], int (*c)[VertexNum])
{
 /* n:图的顶点数目
	v:源顶点的序号
	dist[]:存放当前找到的从源点v到每个v(i)的最短路径的权值
	prev[]:从源点到各顶点的最短路径上该顶点的前一顶点的序号
	c:有向图
 */
	bool s[VertexNum];
	for (int i = 0; i < n; i++)
	{
		dist[i] = c[v][i];//c[v][i]是边[v,i]的权
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
		for (int k = 0; k < n; k++)//V-S中寻找最小的dist[k]
		{
			if (!s[k] && (dist[k] < temp))
			{
				u = k;
				temp = dist[k];
			}
		}
		s[u] = true;//添加u到特殊路径
		for (int k = 0; k < n; k++)
		{
			if (!s[k] && (c[u][k] < MaxInt))
			{
				int newdist = dist[u] + c[u][k];
				if (newdist < dist[k])
				{
					dist[k] = newdist;//有改善，则修改V-S中的dist[k]
					prev[k] = u;
				}
			}
		}
	}
}

//int main()
//{
//	//邻接矩阵表示有向图
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