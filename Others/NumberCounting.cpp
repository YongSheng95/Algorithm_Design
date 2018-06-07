/*
*Copyright (c) 2018,UESTC
*All rights reserved.
*
*摘 要：统计数字问题
*作 者：玉宇
*日 期：2018年3月15日
*/
#include "stdafx.h"
#include<iostream>
#include<fstream>
//对每一个页码分解成单个数字，并记录
void number_count(int num, int *arr){
	while (num > 0){
		arr[num % 10]++;
		num = num / 10;
	}
}

void examples_1_1(){
	int arr[10];
	for (int i = 0; i < 10; ++i)
		arr[i] = 0;
	std::ifstream input("input_1_1.txt");
	std::ofstream output("output_1_1.txt");
	if (!input || !output){
		std::cerr << "Unable to open the necesary files.\n";
	}

	int num;
	input >> num;
	for (int j = 1; j <= num; ++j)
		number_count(j, arr);
	for (int k = 0; k < 10; ++k)
		output << arr[k] << "\n";

	input.close();
	output.close();
}