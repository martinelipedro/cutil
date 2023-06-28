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


#endif