/*
*Copyright (c) 2018,UESTC
*All rights reserved.
*
*摘 要：二分搜索算法
*作 者：玉宇
*日 期：2018年4月1日
*/
#include "stdafx.h"
#include<iostream>

struct searchValue
{
	int value;//搜索元素x在数组中时，x在数组中的位置
	int i;//搜索元素x不在数组中时，小于x的最大元素位置
	int j;//搜索元素x不在数组中时，大于x的最小元素位置
} returnVal, test;

searchValue BinarySearch(int arr[], int x, int left, int right)
{
	while (right >= left)
	{
		int middle = (left + right) / 2;
		if (x == arr[middle])//搜索元素x在数组中
		{
			returnVal.value = middle;
			returnVal.i = 0;
			returnVal.j = 0;
			return returnVal;
		}
		if (x < arr[middle])
		{
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
	}
		//搜索元素x不在数组中
		returnVal.value = 0;
		returnVal.i = right;
		returnVal.j = left;

	return returnVal;
}

//int main()
//{
//	int arr[7] = { 1, 2, 4, 5, 7, 15, 17 };
//	std::cout << "An array is: ";
//	for (int i = 0; i < 7; i++){
//		std::cout << arr[i] << " ";
//	}
//	int x = 4;
//	std::cout << "\nBinarySearch x: " << x << std::endl;
//	test = BinarySearch(arr, x, 0, 6);
//	if (test.value != 0){
//		std::cout << "Found x in position: " << test.value << std::endl;
//	}
//	else
//	{
//		std::cout << "Not found x, the max elem that is less than x (i): " 
//			<< test.i <<"\nand the min elem that is greater than x (j): "
//			<< test.j << std::endl;
//	}
//}