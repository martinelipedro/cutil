#ifndef CUTIL_STRING_H
#define CUTIL_STRING_H

#include <stdlib.h>

typedef struct STRING_STRUCT
{
    size_t len;
    size_t size;
    char* buffer;

} string_T;

string_T* init_string(char* initial_string);
void string_append_char(string_T* string, char c);
void string_append_string_type(string_T* dest, string_T* src);


#endif