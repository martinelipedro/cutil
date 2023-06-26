#ifndef CUTIL_STRUCTURES_VECTOR_H
#define CUTIL_STRUCTURES_VECTOR_H

#include <stdlib.h>

typedef struct VECTOR_STRUCT
{
    void** data;
    size_t element_size;
    size_t size;
    size_t len;

} vec_T;

vec_T* init_vector(size_t element_size);

void vector_push(vec_T* vector, void* element);
void* vector_get(vec_T* vector, size_t index);

#endif