/*
*Copyright (c) 2018,UESTC
*All rights reserved.
*
*ժ Ҫ�����������㷨
*�� �ߣ�����
*�� �ڣ�2018��4��1��
*/
#include "stdafx.h"
#include<iostream>

struct searchValue
{
	int value;//����Ԫ��x��������ʱ��x�������е�λ��
	int i;//����Ԫ��x����������ʱ��С��x�����Ԫ��λ��
	int j;//����Ԫ��x����������ʱ������x����СԪ��λ��
} returnVal, test;

searchValue BinarySearch(int arr[], int x, int left, int right)
{
	while (right >= left)
	{
		int middle = (left + right) / 2;
		if (x == arr[middle])//����Ԫ��x��������
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
		//����Ԫ��x����������
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