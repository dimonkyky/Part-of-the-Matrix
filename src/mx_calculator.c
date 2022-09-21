#include "../inc/header.h"

void mx_calculator(char *operand1, char operation, char *operand2, char *result) {
    if (operation == '?') {
        mx_calculator(operand1, '+', operand2, result);
        mx_calculator(operand1, '-', operand2, result);
        mx_calculator(operand1, '*', operand2, result);
        mx_calculator(operand1, '/', operand2, result);
        return;
    }

    int op1_len = mx_strlen(operand1);
    int op2_len = mx_strlen(operand2);
    int res_len = mx_strlen(result);
    bool op1_below_zero = false;
    bool op2_below_zero = false;
    bool res_below_zero = false;

    if (operand1[0] == '-') {
        op1_below_zero = true;
        operand1++;
        op1_len--;
    } 
    if (operand2[0] == '-') {
        op2_below_zero = true;
        operand2++;
        op2_len--;
    }
    if (result[0] == '-') {
        res_below_zero = true;
        result++;
        res_len--;
    }

    int first_number = mx_atoi(operand1);
    int second_number = mx_atoi(operand2);
    int third_number = mx_atoi(result);

    for (int i = 0; i < mx_pow(10, op1_len); i++) {
        if (first_number > 0) {
            i = first_number;
        }
        char *temp1 = mx_itoa(i);
        int diff = op1_len - mx_strlen(temp1);
        bool check = true;
        for (int count = 0; count < diff; count++) {
            if (mx_isdigit(operand1[count]) && operand1[count] != '0') {
                check = false;
                break;
            }
        }
        for (int count = diff; count < op1_len; count++) {
            if (operand1[count] != '?' && operand1[count] != temp1[count - diff]) {
                check = false;
                break;
            }
        }
        free(temp1);
        temp1 = NULL;
        if (!check) {
            continue;
        }
        for (int j = 0; j < mx_pow(10, op2_len); j++) {  
            if (second_number > 0) {
                j = second_number;
            }
            char *temp2 = mx_itoa(j);
            diff = op2_len - mx_strlen(temp2);
            check = true;
            for (int count = 0; count < diff; count++) {
                if (mx_isdigit(operand2[count]) && operand2[count] != '0') {
                    check = false;
                    break;
                }
            }
            for (int count = diff; count < op2_len; count++) {
                if (operand2[count] != '?' && operand2[count] != temp2[count - diff]) {
                    check = false;
                    break;
                }
            }
            free(temp2);
            temp2 = NULL;
            if (!check) {
                continue;
            }
            for (int k = 0; k < mx_pow(10, res_len); k++) {
                if (third_number > 0) {
                    k = third_number;
                }
                char *temp3 = mx_itoa(k);
                diff = res_len - mx_strlen(temp3);
                check = true;
                for (int count = 0; count < diff; count++) {
                    if (mx_isdigit(result[count]) && result[count] != '0') {
                        check = false;
                        break;
                    }
                }
                for (int count = diff; count < res_len; count++) {
                    if (result[count] != '?' && result[count] != temp3[count - diff]) {
                        check = false;
                        break;
                    }
                }
                free(temp3);
                temp3 = NULL;
                if (!check) {
                    continue;
                }
                if (op1_below_zero) {
                    i *= -1;
                }
                if (op2_below_zero) {
                    j *= -1;
                }
                if (res_below_zero) {
                    k *= -1;
                }
                if (operation == '+') {
                    if (i + j == k) {
                        mx_printint(i);
                        mx_printstr(" + ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }
                else if (operation == '-') {
                        if (i - j == k) {
                        mx_printint(i);
                        mx_printstr(" - ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }
                else if (operation == '*') {
                        if (i * j == k) {
                        mx_printint(i);
                        mx_printstr(" * ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }
                else if (operation == '/') {
                    if (j != 0 && i / j == k) {
                        mx_printint(i);
                        mx_printstr(" / ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }
                if (op1_below_zero) {
                    i *= -1;
                }
                if (op2_below_zero) {
                    j *= -1;
                }
                if (res_below_zero) {
                    k *= -1;
                }
                if (third_number > 0) {
                    break;
                }
            }
            if (second_number > 0) {
                break;
            }
        }
        if (first_number > 0) {
            break;
        }
    }

    if (op1_below_zero) {
        operand1--;
    }
    if (op2_below_zero) {
        operand2--;
    }
    if (res_below_zero) {
        result--;
    }
}

