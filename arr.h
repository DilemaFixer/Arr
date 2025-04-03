#ifndef ARR_H
#define ARR_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    void** data;
    size_t size;
    size_t capacity;
} Arr;

Arr* arr_create(size_t initial_capacity);
void arr_destroy(Arr* arr);
bool arr_push(Arr* arr, void* element);
void* arr_get(Arr* arr, size_t index);
bool arr_set(Arr* arr, size_t index, void* element);
bool arr_remove(Arr* arr, size_t index);
size_t arr_size(Arr* arr);
bool arr_resize(Arr* arr, size_t new_capacity);

#endif
