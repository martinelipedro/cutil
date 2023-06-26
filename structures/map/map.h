#ifndef CUTIL_STRUCTURES_MAP_H
#define CUTIL_STRUCTURES_MAP_H

#include "../vector/vector.h"

#define KEY_STRING_SIZE 20

typedef struct MAP_STRUCT
{
    vec_T* keys;
    vec_T* data;
    size_t len;

} map_T;

map_T* init_map(size_t data_size);
void map_add(map_T* map, char* key, void* value);
void* map_get(map_T* map, char* key);
int map_key_exists(map_T* map, char* key);




#endif