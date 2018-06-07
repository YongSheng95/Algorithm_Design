/*
*Copyright (c) 2018,UESTC
*All rights reserved.
*
*ժ Ҫ���ֵ�������
*�� �ߣ�����
*�� �ڣ�2018��3��15��
*/
#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;


//����ĸi��ͷ������Ϊk�������ַ���
//�����Ϊf(i, k)
int f(int i, int k){
	int sum = 0;
	if (k == 1)
		return 1;
	else{
		for (int j = i + 1; j <= 28 - k; ++j)
			sum += f(j, k - 1);
	}
	return sum;
}

//����Ϊk�������ַ����ܸ���Ϊg(k)
int g(int k){
	int sum = 0;
	for (int i = 1; i <= 27 - k; ++i)
		sum += f(i, k);
	return sum;
}

//�������ַ������ֵ����
int dict_encode(char str[]){
	int code = 0;
	int len = strlen(str);

	//�󳤶�С�ڴ����ַ�����������ϸ���
	for (int k = 1; k < len; ++k)
		code += g(k);

	//�󳤶ȵ���len,����ĸС�ڴ����ַ�������ĸ����ϸ���
	int first_letter = str[0] - 'a' + 1;
	for (int i = 1; i < first_letter; ++i)
		code += f(i, len);

	//�󳤶ȵ���len,����ĸ���ڴ����ַ�������ĸ�������ַ�������
	//���������Ҫ������ַ�����2-lenλ���αȽ�
	for (int n = 1; n < len; ++n){
		for (int m = first_letter + 1; m < str[n] - 'a' + 1; ++m)
			code += f(m, len - n);
		first_letter = str[n];
	}
	return code + 1;
}
void examples_1_2(){
	ifstream input("input_1_2.txt");
	ofstream output("output_1_2.txt");
	if (!input || !output){
		cerr << "Unable to open the necesary files.\n";
	}
	int code, num;
	char str[7];
	input >> num;
	for (int i = 0; i<num; ++i){
		input >> str;
		code = dict_encode(str);
		output << code << "\n";
	}
	input.close();
	output.close();
}