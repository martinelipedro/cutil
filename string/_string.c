#include "_string.h"
#include <string.h>

string_T* init_string(char* initial_string)
{
    string_T* string = calloc(1, sizeof(struct STRING_STRUCT));

    string->len = strlen(initial_string);
    string->size = sizeof(initial_string);
    string->buffer = initial_string;

    return string;
}