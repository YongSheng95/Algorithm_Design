/*
*Copyright (c) 2018,UESTC
*All rights reserved.
*
*摘 要：用动态规划算法实现最优二叉查找树
*作 者：玉宇
*日 期：2018年6月6日
*/
#include "stdafx.h"
#include<iostream>
#include<iomanip>

const int MaxVal = 999;

const int n = 5;
//搜索到根节点和虚拟键的概率
double p[n + 1] = { 0, 0.15, 0.1, 0.05, 0.1, 0.2 };
double q[n + 1] = { 0.05, 0.1, 0.05, 0.05, 0.05, 0.1 };

int root[n + 1][n + 1]; //记录根节点
double w[n + 2][n + 2]; //子树概率总和
double e[n + 2][n + 2]; //子树期望代价

/*
* p是存放关键字节点概率的数组[1,n]，q是存放伪关键字节点(叶子节点)出现概率的数组[0,n]
* n是节点个数
* e[i,j]是存放包含关键字Ki~Kj的最优二叉树进行一次搜索的期望代价，由于要包括e[n+1,n]
* 的q[n]和e[1,0]q[0]，所以范围是[0,n+1]
* w[i,j]是存放Ki~Kj的概率和,w[i,j]=w[i,r-1]+p[r]+w[r+1,j]
* root[i,j]是存放包含Ki~Kj的关键字的子树，最优情况下，root节点的下标
*/

void OptimalBst(double* p, double* q, int n) 
{
	//首先处理w[i,j]和e[i,j]中i=j+1的情况，这种情况都是q[i-1]
	for (int i = 1; i <= n + 1; i++)
	{
		w[i][i - 1] = q[i - 1];
		e[i][i - 1] = q[i - 1];
	}

	//然后处理长度L从1到n的循环
	int l = 0; //代表ki~kj的长度
	int j = 0; //代表最后一个元素的下标值j
	int i = 0; //代表起始的一个元素的下标值i
	int r = 0; //代表root节点的下标
	double tmp = 0; //这里要存储e数组元素计算的临时结果，所以也是double类型的

	for (l = 1; l <= n; l++) 
	{
		//以i为外层循环，这里由于长度是L，i最大为n-l+1，而j-i+1=L，j=L+i-1
		for (i = 1; i <= n - l + 1; i++)
		{
			j = l + i - 1;
			e[i][j] = MaxVal;
			w[i][j] = w[i][j - 1] + p[j] + q[j];

			for (int r = i; r <= j; r++)
			{
				tmp = e[i][r - 1] + e[r + 1][j] + w[i][j];
				if (tmp < e[i][j])
				{
					e[i][j] = tmp;
					root[i][j] = r;
				}
			}
		}
	}
}


/*
* 打印最优二叉搜索树
*/
void PrintOptimalBst(int i, int j, int r, bool root_flag) {
	int root_node = root[i][j];
	if (root_flag) 
	{
		std::cout << " 根结点为：k" << root_node << std::endl;
		root_flag = false;
		PrintOptimalBst(i, root_node - 1, root_node, root_flag);
		PrintOptimalBst(root_node + 1, j, root_node, root_flag);
		return;
	}

	if (i > j + 1)
	{
		return;
	}
	else if (i == j + 1)
	{
		if (j < r) 
		{
			std::cout << " d" << j << "是" << "k" << r << "的左孩子" << std::endl;
		}
		else 
		{
			std::cout << " d" << j << "是" << "k" << r << "的右孩子" << std::endl;
		}
		return; //这里加个return是因为，当循环到i==j+1的时候，已经到头了，不能再递归了，此时不存在合理的root_node了
	}
	else
	{
		if (root_node < r) {
			std::cout << " k" << root_node << "是" << "k" << r << "的左孩子" << std::endl;
		}
		else {
			std::cout << " k" << root_node << "是" << "k" << r << "的右孩子" << std::endl;
		}
	}
	PrintOptimalBst(i, root_node - 1, root_node, root_flag);
	PrintOptimalBst(root_node + 1, j, root_node, root_flag);
}
//void main()
//{
//	OptimalBst(p, q, n);
//	PrintOptimalBst(1, 5, root[1][5], true);
//	std::cout << " root table:" << std::endl;
//	for (int i = 1; i < 6; i++)
//	{
//		for (int j = 1; j < 6; j++)
//		{
//			std::cout << std::setw(6) << root[i][j] << " ";
//		}
//		std::cout << std::endl;
//	}
//	std::cout << " E table:" << std::endl;
//	for (int i = 1; i < 6; i++)
//	{
//		for (int j = 0; j < 6; j++)
//		{
//			std::cout << std::setw(6) << e[i][j] << " ";
//		}
//		std::cout << std::endl;
//	}
//	std::cout << " W table:" << std::endl;
//	for (int i = 1; i <= 6; i++)
//	{
//		for (int j = 1; j < 6; j++)
//		{
//			std::cout << std::setw(6) << w[i][j] << " ";
//		}
//		std::cout << std::endl;
//	}
//}