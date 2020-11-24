#pragma once
#include <stdio.h>


/** Script
  */
void script_Start() {
	printf("��Ģ���� ����\n");
}
void script_End() {
	printf("��Ģ���� ��\n");
}
void script_Number1() {
	printf("ù ��° ���� �Է� �ʿ�\n");
}
void script_Operator() {
	printf("������ �Է� �ʿ�\n");
}
void script_Number2() {
	printf("�� ��° ���� �Է� �ʿ�\n");
}
void script_Wainting_Calculating() {
	printf("���� ��� ��\n");
}
void script_Operator_Error() {
	printf("������ �Է� ����\n");
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
		printf("		���	:	%f\n", dnum);
	}
	if (ope != '/') {
		printf("		���	:	%d\n", num);
	}
}
