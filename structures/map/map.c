#include "map.h"

#include <string.h>
#include <stdio.h>

map_T* init_map(size_t data_size)
{
    map_T* map = calloc(1, sizeof(struct MAP_STRUCT));

    map->keys = init_vector(KEY_STRING_SIZE * sizeof(char));
    map->data = init_vector(data_size);
    map->len = 0;

    return map;
}

void map_add(map_T* map, char* key, void* value)
{
    vector_push(map->keys, key);
    vector_push(map->data, value);
    map->len++;
}

void* map_get(map_T* map, char* key)
{
    for (size_t i = 0; i < map->len; ++i)
    {
        if (strcmp((char*)vector_get(map->keys, i), key) == 0)
        {
            return vector_get(map->data, i);
        }
    }

    printf("Key %s not found in map", key);
    exit(1);
}

int map_key_exists(map_T* map, char* key)
{

}