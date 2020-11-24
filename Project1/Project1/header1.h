#pragma once
#include <stdio.h>
#include "header2.h"


/** script
  */
void script_Start();
void script_End();
void script_Number1();
void script_Operator();
void script_Number2();
void script_Wainting_Calculating();
void script_Operator_Error();

/** Input
  */
int input_Number(int num);
char input_Operator();


/** Calculation
  */
int calc_Add(int num1, int num2);
int calc_Sub(int num1, int num2);
int calc_Mul(int num1, int num2);
double calc_Div(int num1, int num2);


/** Output
  */
void output_Number(int num, double dnum, char ope);