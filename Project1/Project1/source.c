#include <stdio.h>
#include "header1.h"
#include <Windows.h>
#include <process.h>


#define max_thread_count 2
#define max_sema_count 1


int count = 0;
int sema_count = 0;
HANDLE _sema;


int num1 = 0;
int num2 = 0;
int num = 0;
double dnum = 0;
char ope;


int (*calculate)(int num1, int num2);
double (*dcalculate)(int num1, int num2);


unsigned _stdcall Thread_Input(void* arg) {
	int* p = (int*)arg;

	while (1) {

		WaitForSingleObject(_sema, INFINITE);

		num1 = input_Number1();
		ope = input_Operator();
		num2 = input_Number2();
		
		ReleaseSemaphore(_sema, 1, &sema_count);
	}

}
unsigned _stdcall Thread_Calculation(void* arg) {
	int* p = (int*)arg;

	while (1) {

		WaitForSingleObject(_sema, INFINITE);

		switch (ope) {
		case '+': calculate = calc_Add; num = calculate(num1, num2);  break;
		case '-': calculate = calc_Sub; num = calculate(num1, num2);  break;
		case '*': calculate = calc_Mul; num = calculate(num1, num2);  break;
		case '/': dcalculate = calc_Div; dnum = dcalculate(num1, num2);  break;
		default: script_Operator_Error();
		}
		
		ReleaseSemaphore(_sema, 1, &sema_count);

	}
	
}
unsigned _stdcall Thread_Output(void* arg) {
	int* p = (int*)arg;

	while (1) {

		WaitForSingleObject(_sema, INFINITE);

		output_Number(num, dnum, ope);

		ReleaseSemaphore(_sema, 1, &sema_count);

	}
	
}

int main() {

	HANDLE thread[max_thread_count];

	_sema = CreateSemaphore(NULL, max_sema_count, max_sema_count, NULL);

	thread[0]=(HANDLE)_beginthreadex(NULL, 0, Thread_Input, 0, 0, NULL);
	thread[1]=(HANDLE)_beginthreadex(NULL, 0, Thread_Calculation,0, 0, NULL);
	thread[2]=(HANDLE)_beginthreadex(NULL, 0, Thread_Output, 0, 0, NULL);
	
	WaitForMultipleObjects(max_thread_count, thread, TRUE, INFINITE);
	
}