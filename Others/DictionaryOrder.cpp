/*
*Copyright (c) 2018,UESTC
*All rights reserved.
*
*摘 要：字典序问题
*作 者：玉宇
*日 期：2018年3月15日
*/
#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;


//以字母i开头，长度为k的升序字符串
//其个数为f(i, k)
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

//长度为k的升序字符串总个数为g(k)
int g(int k){
	int sum = 0;
	for (int i = 1; i <= 27 - k; ++i)
		sum += f(i, k);
	return sum;
}

//求升序字符串的字典编码
int dict_encode(char str[]){
	int code = 0;
	int len = strlen(str);

	//求长度小于待求字符串的所有组合个数
	for (int k = 1; k < len; ++k)
		code += g(k);

	//求长度等于len,首字母小于待求字符串首字母的组合个数
	int first_letter = str[0] - 'a' + 1;
	for (int i = 1; i < first_letter; ++i)
		code += f(i, len);

	//求长度等于len,首字母等于待求字符串首字母的所有字符串个数
	//此种情况需要与待求字符串从2-len位依次比较
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