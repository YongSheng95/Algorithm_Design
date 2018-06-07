/*
*Copyright (c) 2018,UESTC
*All rights reserved.
*
*摘 要：贪心算法解决活动安排问题
*作 者：玉宇
*日 期：2018年4月22日
*/
#include "stdafx.h"
#include<iostream>

//对活动按结束时间非递减排序
void ActivitySort(int *s, int *f, int num)
{
	int tmps, tmpf;
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (*(f + i) > *(f + j))
			{
				tmpf = *(f + i);
				tmps = *(s + i);
				*(f + i) = *(f + j);
				*(s + i) = *(s + j);
				*(f + j) = tmpf;
				*(s + j) = tmps;
			}
		}
	}
}

//活动安排
void ActivitySelection(int *s, int *f, int *section, int num)
{
	section[0] = 1;
	for (int i = 0; i < num; i++)
	{
		if (section[i] == 1)
		{
			for (int j = i + 1; j < num; j++)
			{
				if (s[j] >= f[i])
				{
					section[j] = 1;
					break;
				}

			}
		}
	}
}

int main()
{
	const int num = 9;
	int s[num] = { 2, 2, 3, 4, 6, 7, 9, 10, 13 };//开始时间
	int f[num] = { 3, 4, 5, 7, 8, 11, 12, 15, 17 };//结束时间
	int section[num] = { 0 };//活动是否被选中
	std::cout << "Original Activities:" << std::endl;
	for (int i = 0; i < num; i++)
	{
		std::cout << "activity " << i << ": (" << s[i] <<", "<< f[i] <<")"<<std::endl;
	}
	std::cout << "After Sorting:" << std::endl;
	ActivitySort(s, f, num);
	for (int i = 0; i < num; i++)
	{
		std::cout << "activity " << i << ": (" << s[i] << ", " << f[i] << ")" << std::endl;
	}
	ActivitySelection(s, f, section, num);
	std::cout << "Section Results:" << std::endl;
	for (int i = 0; i < num; i++)
	{
		std::cout << section[i] << " ";
	}
	std::cout << std::endl;
}