#pragma once
#include <stdio.h>


/** Script
  */
void script_Start() {
	printf("사칙연산 시작\n");
}
void script_End() {
	printf("사칙연산 끝\n");
}
void script_Number1() {
	printf("첫 번째 숫자 입력 필요\n");
}
void script_Operator() {
	printf("연산자 입력 필요\n");
}
void script_Number2() {
	printf("두 번째 숫자 입력 필요\n");
}
void script_Wainting_Calculating() {
	printf("연산 대기 중\n");
}
void script_Operator_Error() {
	printf("연산자 입력 오류\n");
}

/** Input
  */
int input_Number1() {
	int num = 0;
	script_Number1();
	scanf_s("%d", &num);
	getchar();
	return num;
}
int input_Number2() {
	int num = 0;
	script_Number2();
	scanf_s("%d", &num);
	getchar();
	return num;
}
char input_Operator() {
	script_Operator();
	char s;
	scanf_s("%c", &s);
	getchar();
	return s;
}


/** Calculation
  */
int calc_Add(int num1, int  num2) {
	return num1 + num2;
}
int calc_Sub(int num1, int num2) {
	return num1 - num2;
}
int calc_Mul(int num1, int num2) {
	return num1 * num2;
}
double calc_Div(int num1, int num2) {
	return (double)num1 / num2;
}


/** Output
  */
void output_Number(int num, double dnum, char ope) {
	if (ope == '/') {
		printf("		결과	:	%f\n", dnum);
	}
	if (ope != '/') {
		printf("		결과	:	%d\n", num);
	}
}
