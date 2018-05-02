/*
*Copyright (c) 2018,UESTC
*All rights reserved.
*
*摘 要：三者取中法完成快速排序
*作 者：玉宇
*日 期：2018年3月30日
*/
#include "stdafx.h"
#include<iostream>

//交换数组中的两个数
void Swap(int *arr, int a, int b)
{
	int temp = *(arr+a);
	*(arr+a) = *(arr+b);
	*(arr+b) = temp;
}
//处理枢纽值
void DealPivot(int *arr, int left, int right)
{
	int middle = (left + right) / 2;
	//左、中、右三个元数排序，并在数组中交换位置
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
	Swap(arr, right - 1, middle);//将枢纽值放在当前待处理序列末尾
}
//快速排序
void QuickSort(int *arr, int left, int right){
	if (left < right)
	{
		DealPivot(arr, left, right);
		int pivot = right - 1;//枢纽值
		int i = left;//左指针
		int j = right - 1;//右指针
		while (true)
		{
			while (arr[++i] < arr[pivot]);//从左边扫描大于枢纽值的元素
			while (j > i && arr[--j] > arr[pivot]);//从右边扫描小于枢纽值的元素
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
			Swap(arr, i, pivot);//左右指针重合的时候，交换该元素与枢纽值
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