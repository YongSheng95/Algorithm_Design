/*
*Copyright (c) 2018,UESTC
*All rights reserved.
*
*ժ Ҫ������ȡ�з���ɿ�������
*�� �ߣ�����
*�� �ڣ�2018��3��30��
*/
#include "stdafx.h"
#include<iostream>

//���������е�������
void Swap(int *arr, int a, int b)
{
	int temp = *(arr+a);
	*(arr+a) = *(arr+b);
	*(arr+b) = temp;
}
//������Ŧֵ
void DealPivot(int *arr, int left, int right)
{
	int middle = (left + right) / 2;
	//���С�������Ԫ�����򣬲��������н���λ��
	if (arr[left] > arr[middle])
	{
		Swap(arr, left, middle);
	}
	if (arr[left] > arr[right])
	{
		Swap(arr, left, right);
	}
	if (arr[middle] > arr[right])
	{
		Swap(arr, middle, right);
	}
	Swap(arr, right - 1, middle);//����Ŧֵ���ڵ�ǰ����������ĩβ
}
//��������
void QuickSort(int *arr, int left, int right){
	if (left < right)
	{
		DealPivot(arr, left, right);
		int pivot = right - 1;//��Ŧֵ
		int i = left;//��ָ��
		int j = right - 1;//��ָ��
		while (true)
		{
			while (arr[++i] < arr[pivot]);//�����ɨ�������Ŧֵ��Ԫ��
			while (j > i && arr[--j] > arr[pivot]);//���ұ�ɨ��С����Ŧֵ��Ԫ��
			if (i < j)
			{
				Swap(arr, i, j);
			}
			else
			{
				break;
			}	
		}
		if (i < right){
			Swap(arr, i, pivot);//����ָ���غϵ�ʱ�򣬽�����Ԫ������Ŧֵ
		}
		QuickSort(arr, left, i - 1);
		QuickSort(arr, i + 1, right);
	}
}

int main(){
	std::cout << "QuickSort" <<std::endl;
	std::cout << "Orignial array:" << std::endl;
	const int lenArray = 9;
	int arr[] = { 3, 4, 2, 9, 6, 5, 8, 7, 1 };
	for (int i = 0; i < lenArray; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	QuickSort(arr, 0, 8);
	std::cout << "After QuickSort, array is:" << std::endl;
	for (int i = 0; i < lenArray; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	return 0;
}