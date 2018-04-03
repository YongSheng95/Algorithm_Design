/*
*Copyright (c) 2018,UESTC
*All rights reserved.
*
*摘 要：二路归并算法
*作 者：玉宇
*日 期：2018年4月3日
*/
#include "stdafx.h"
#include<iostream>

//两个子序列的合并
void Merge(int *data, int low, int mid, int hight)
{
	int i = low;//指向第一个有序序列当前的比较值
	int j = mid + 1;//指向第二个有序序列当前的比较值
	int k = 0;
	int *temp = new int[hight - low + 1];//暂存合并的有序序列
	if (!temp)
	{
		std::cout << "New int[] ERROR!";
		return;
	}
	while (i <= mid && j <= hight)//顺序选取两个序列中较小的元素，存储到temp中
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
	while (i <= mid)//第一个序列还有剩余，直接复制到temp中
		temp[k++] = data[i++];
	while (j <= hight)//第二个序列还有剩余
		temp[k++] = data[j++];
	for (i = low, k = 0; i < hight; i++, k++)//从temp中恢复排序好的数据到data
	{
		data[i] = temp[k];
	}
	delete []temp;
}

//归并排序
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