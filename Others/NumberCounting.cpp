/*
*Copyright (c) 2018,UESTC
*All rights reserved.
*
*ժ Ҫ��ͳ����������
*�� �ߣ�����
*�� �ڣ�2018��3��15��
*/
#include "stdafx.h"
#include<iostream>
#include<fstream>
//��ÿһ��ҳ��ֽ�ɵ������֣�����¼
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