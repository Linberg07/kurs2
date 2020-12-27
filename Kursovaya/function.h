#ifndef FUNCTION_H
#define FUNCTION_H

#define pi "3.14159265358979323846"
#define Expon "2.71828182845904523536"

#include<iostream>

using namespace std;
string convertInt(double number);
int check_string(string infix);
void string_to_double(double& a, double& b, string after, string before);
void one_string_to_double(double& b, string after);
string string_power(string infix);
string string_exp(string infix);
string string_multiplication(string infix);
string string_pi(string infix);
string string_division(string infix);
string string_addition(string infix);
string string_computation(string infix);
string string_cos_procedure(string infix);
string string_sin_procedure(string infix);
string string_ctg_procedure(string infix);
string string_tg_procedure(string infix);
string string_ln_procedure(string infix);
string string_log_procedure(string infix);
string minus_plus_procedure(string infix);
string string_brackets(string infix, int& brackets_open);
string implementation(string infix);

#endif
