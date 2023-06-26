#include "vector.h"
#include <stdio.h>

vec_T* init_vector(size_t element_size)
{
    vec_T* vector = calloc(1, sizeof(struct VECTOR_STRUCT));

    vector->data = (void*)0;
    vector->element_size = element_size;
    vector->size = 0;
    vector->len = 0;

    return vector;
}

void vector_push(vec_T* vector, void* element)
{
    vector->len++;
    vector->size = vector->len * sizeof(vector->element_size);

    if (vector->len == 1)
    {
        vector->data = calloc(1, sizeof(vector->element_size));
        vector->data[0] = element;
        return;
    }

    vector->data = realloc(vector->data, vector->size);
    vector->data[vector->len - 1] = element;
}

void* vector_get(vec_T* vector, size_t index)
{
    if (index > vector->len - 1 || vector->size == 0) 
    {
        printf("[err?vector]: requested element %ld, does not exist.", index);
        exit(1);
    }

    return vector->data[index];
}