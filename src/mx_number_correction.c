#include "../inc/header.h"

char *mx_number_correction(char *s) {
    char *new_s = mx_strnew(mx_strlen(s));
    int count = 0;
    for (int i = 0; i < mx_strlen(s); i++) {
        if (s[i] == ' ') {
            continue;
        }
        if (!mx_isdigit(s[i]) && s[i] != '?' && s[i] != '-') {
            return NULL;
        }
        new_s[count] = s[i];
        count++;
    }
    return new_s;
}

