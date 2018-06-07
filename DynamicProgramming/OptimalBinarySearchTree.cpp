/*
*Copyright (c) 2018,UESTC
*All rights reserved.
*
*ժ Ҫ���ö�̬�滮�㷨ʵ�����Ŷ��������
*�� �ߣ�����
*�� �ڣ�2018��6��6��
*/
#include "stdafx.h"
#include<iostream>
#include<iomanip>

const int MaxVal = 999;

const int n = 5;
//���������ڵ��������ĸ���
double p[n + 1] = { 0, 0.15, 0.1, 0.05, 0.1, 0.2 };
double q[n + 1] = { 0.05, 0.1, 0.05, 0.05, 0.05, 0.1 };

int root[n + 1][n + 1]; //��¼���ڵ�
double w[n + 2][n + 2]; //���������ܺ�
double e[n + 2][n + 2]; //������������

/*
* p�Ǵ�Źؼ��ֽڵ���ʵ�����[1,n]��q�Ǵ��α�ؼ��ֽڵ�(Ҷ�ӽڵ�)���ָ��ʵ�����[0,n]
* n�ǽڵ����
* e[i,j]�Ǵ�Ű����ؼ���Ki~Kj�����Ŷ���������һ���������������ۣ�����Ҫ����e[n+1,n]
* ��q[n]��e[1,0]q[0]�����Է�Χ��[0,n+1]
* w[i,j]�Ǵ��Ki~Kj�ĸ��ʺ�,w[i,j]=w[i,r-1]+p[r]+w[r+1,j]
* root[i,j]�Ǵ�Ű���Ki~Kj�Ĺؼ��ֵ���������������£�root�ڵ���±�
*/

void OptimalBst(double* p, double* q, int n) 
{
	//���ȴ���w[i,j]��e[i,j]��i=j+1������������������q[i-1]
	for (int i = 1; i <= n + 1; i++)
	{
		w[i][i - 1] = q[i - 1];
		e[i][i - 1] = q[i - 1];
	}

	//Ȼ������L��1��n��ѭ��
	int l = 0; //����ki~kj�ĳ���
	int j = 0; //�������һ��Ԫ�ص��±�ֵj
	int i = 0; //������ʼ��һ��Ԫ�ص��±�ֵi
	int r = 0; //����root�ڵ���±�
	double tmp = 0; //����Ҫ�洢e����Ԫ�ؼ������ʱ���������Ҳ��double���͵�

	for (l = 1; l <= n; l++) 
	{
		//��iΪ���ѭ�����������ڳ�����L��i���Ϊn-l+1����j-i+1=L��j=L+i-1
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
* ��ӡ���Ŷ���������
*/
void PrintOptimalBst(int i, int j, int r, bool root_flag) {
	int root_node = root[i][j];
	if (root_flag) 
	{
		std::cout << " �����Ϊ��k" << root_node << std::endl;
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
			std::cout << " d" << j << "��" << "k" << r << "������" << std::endl;
		}
		else 
		{
			std::cout << " d" << j << "��" << "k" << r << "���Һ���" << std::endl;
		}
		return; //����Ӹ�return����Ϊ����ѭ����i==j+1��ʱ���Ѿ���ͷ�ˣ������ٵݹ��ˣ���ʱ�����ں����root_node��
	}
	else
	{
		if (root_node < r) {
			std::cout << " k" << root_node << "��" << "k" << r << "������" << std::endl;
		}
		else {
			std::cout << " k" << root_node << "��" << "k" << r << "���Һ���" << std::endl;
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