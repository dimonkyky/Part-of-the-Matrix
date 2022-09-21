#include "../inc/header.h"

void mx_error(char *m, char *arg) {
    mx_printerr(m);
    mx_printerr(arg);
    mx_printerr("\n");
}

