/*
*Copyright (c) 2018,UESTC
*All rights reserved.
*
*ժ Ҫ����·�鲢�㷨
*�� �ߣ�����
*�� �ڣ�2018��4��3��
*/
#include "stdafx.h"
#include<iostream>

//���������еĺϲ�
void Merge(int *data, int low, int mid, int hight)
{
	int i = low;//ָ���һ���������е�ǰ�ıȽ�ֵ
	int j = mid + 1;//ָ��ڶ����������е�ǰ�ıȽ�ֵ
	int k = 0;
	int *temp = new int[hight - low + 1];//�ݴ�ϲ�����������
	if (!temp)
	{
		std::cout << "New int[] ERROR!";
		return;
	}
	while (i <= mid && j <= hight)//˳��ѡȡ���������н�С��Ԫ�أ��洢��temp��
	{
		if (data[i] < data[j])
		{
			temp[k++] = data[i++];
		}
		else
		{
			temp[k++] = data[j++];
		}
	}
	while (i <= mid)//��һ�����л���ʣ�ֱ࣬�Ӹ��Ƶ�temp��
		temp[k++] = data[i++];
	while (j <= hight)//�ڶ������л���ʣ��
		temp[k++] = data[j++];
	for (i = low, k = 0; i < hight; i++, k++)//��temp�лָ�����õ����ݵ�data
	{
		data[i] = temp[k];
	}
	delete []temp;
}

//�鲢����
void MergeSort(int *data, int low, int hight)
{
	if (low < hight)
	{
		int mid = (low + hight) / 2;
		MergeSort(data, low, mid);
		MergeSort(data, mid + 1, hight);
		Merge(data, low, mid, hight);
	}
}

int main()
{
	int x[] = { 1, 5, 2, 3, 9, 6, 8, 7 };
	std::cout << "Original Array:\n";
	for (int i = 0; i < 8; i++)
	{
		std::cout << x[i] << " ";
	}
	MergeSort(x, 0, 7);
	std::cout << "\nAfter MergeSort, the array is:\n";
	for (int i = 0; i < 8; i++)
	{
		std::cout << x[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}