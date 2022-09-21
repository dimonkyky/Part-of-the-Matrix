#include "../inc/header.h"

int mx_find_operation(const char *s) {
    int index = -1;
    for (int i = 0; i < mx_strlen(s); i++) {
        if (s[i] == ' ') {
            continue;
        }
        if (s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/' && s[i] != '?') {
            return -1;
        }
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '?') {
            if (index != -1) {
                return -1;
            }
            index = i;
        }
    }
    return index;
}

