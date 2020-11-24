#include <stdio.h>
#include "header1.h"
#include <Windows.h>
#include <process.h>
//#include <mutex>
//#include <semaphore>
//#include <stdlib.h>
//#include <thread>


#define max_sema_Count 10
HANDLE sema;



int num1 = 0;
int num2 = 0;
int num = 0;
double dnum = 0;
char ope=0;
int (*calculate)(int num1, int num2);
double (*dcalculate)(int num1, int num2);

unsigned _stdcall Thread_Input(void* arg) {
	int* p = (int*)arg;
	while (1) {
		num1 = input_Number1();

		ope = input_Operator();

		num2 = input_Number2();
	}
}
unsigned _stdcall Thread_Calculation(void* arg) {
	int* p = (int*)arg;
	while (1) {

		//Sleep(2000);
		//printf("%d	%d	%c\n", num1, num2, ope);

		switch (ope) {
		case '+': calculate = calc_Add; num = calculate(num1, num2);  break;
		case '-': calculate = calc_Sub; num = calculate(num1, num2);  break;
		case '*': calculate = calc_Mul; num = calculate(num1, num2);  break;
		case '/': dcalculate = calc_Div; dnum = dcalculate(num1, num2);  break;
		default: Sleep(2000); script_Operator_Error();
		}
	}
}
unsigned _stdcall Thread_Output(void* arg) {
	int* p = (int*)arg;
	while (1) {
		Sleep(2000);
		output_Number(num, dnum, ope);
	}
}


int main() {

	_beginthreadex(NULL, 0, Thread_Input, 0, 0, NULL);
	_beginthreadex(NULL, 0, Thread_Calculation,0, 0, NULL);
	_beginthreadex(NULL, 0, Thread_Output, 0, 0, NULL);

	//num1 = input_Number1();

	//ope = input_Operator();
	//getchar();

	//num2 = input_Number2();


	while (1) {
		//Sleep(2000);
		//printf("%c\n", ope);
		//printf("%d	%d	%c", num1, num2,op);
		//printf("%d		%f\n", num, dnum);
	}
	
	//char ope = input_Operator();
	//printf("%c", ope);

	return 0;
}