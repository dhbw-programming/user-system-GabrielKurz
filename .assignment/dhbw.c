#include "dhbw.h"
#include <stdio.h>

void dhbw_print_integer(const char* description, int l) {
    printf("%s: %i\n", description, l);
}

void dhbw_print_line(const char* text) {
    printf("%s\n", text);
}

void dhbw_print_float(const char* description, float f) {
    printf("%s: %.2f\n", description, f);
}

void dhbw_print_int_array_element(const char *array_name, int index, int value) {
    printf("%s[%d]: %d\n", array_name, index, value);
}

int dhbw_read_int(const char *prompt) {
    int ret = 0;
    dhbw_print_line(prompt);
    scanf("%d", &ret);
    return ret; 
}

void dhbw_print_string(const char* description, const char* str) {
    printf("%s: %s\n", description, str);
}
