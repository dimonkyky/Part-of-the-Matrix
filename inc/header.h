#ifndef HEADER
#define HEADER

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void mx_printint(int n);
double mx_pow(double n, unsigned int pow);
char *mx_itoa(long long number);
long long mx_atoi(const char *str);
void mx_error(char *m, char *arg);
bool mx_isdigit(int c);
char *mx_strnew(const int size);
void mx_printchar(char h);
void mx_calculator(char *operand1, char operation, char *operand2, char *result);
void mx_printstr(const char* s);
int mx_find_operation(const char *s);
char *mx_number_correction(char *s);
void mx_printerr(const char* s);
int mx_strlen(const char *s);
int main(int argc, char *argv[]);

#endif

