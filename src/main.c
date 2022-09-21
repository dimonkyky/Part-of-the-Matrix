#include "../inc/header.h"

int main(int argc, char *argv[]) {
    if (argc != 5) {
        mx_printerr("usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result] \n");
        exit(-1);
    }
    int operation_index = mx_find_operation(argv[2]);
    if (operation_index == -1) {
        mx_error("Invalid operation: ", argv[2]);
        exit(-1);
    }
    char operation = argv[2][operation_index];
    char *operand1 = mx_number_correction(argv[1]);
    if (operand1 == NULL) {
        mx_error("Invalid operand: ", argv[1]);
        exit(-1);
    }
    char *operand2 = mx_number_correction(argv[3]);
    if (operand2 == NULL) {
        mx_error("Invalid operand: ", argv[3]);
        exit(-1);
    }
    char *result = mx_number_correction(argv[4]);
    if (result == NULL) {
        mx_error("Invalid result: ", argv[4]);
        exit(-1);
    }
    mx_calculator(operand1, operation, operand2, result);
}

