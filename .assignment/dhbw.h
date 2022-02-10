#ifndef _INCLUDE_DHBW_H
#define _INCLUDE_DHBW_H

/**
 * Print the integer and its description to the standard output
 */
void dhbw_print_integer(const char* description, int l);

/**
 * Print the text to the standard output
 */
void dhbw_print_line(const char* text);

/**
 * Print the float and its description to the standard output
 */
void dhbw_print_float(const char* description, float l);

/**
 * Print a value of an integer array for a specific index.
 */
void dhbw_print_int_array_element(const char *array_name, int index, int value);

/**
 * Read next integer from stdin. Returns 0 when 0 or invalid number.
 */
int dhbw_read_int(const char *prompt);

/**
 * Print the string and its description to the standard output 
 */
void dhbw_print_string(const char* description, const char* str);

#endif

