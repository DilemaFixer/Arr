# Arr 📊

[![Build Status](https://img.shields.io/badge/build-passing-brightgreen)](https://github.com/DilemaFixer/Arr)
[![Version](https://img.shields.io/badge/version-1.0.0-blue)](https://github.com/DilemaFixer/Arr/releases)
[![License](https://img.shields.io/badge/license-MIT-green)](https://github.com/DilemaFixer/Arr/blob/main/LICENSE)
[![Language](https://img.shields.io/badge/language-C-orange)](https://github.com/DilemaFixer/Arr)

A lightweight, dynamic array implementation for C that provides flexible storage and automatic resizing capabilities.

## 📥 Installation

### Unix-based systems (Linux, macOS)
```bash
curl -o arr.h https://raw.githubusercontent.com/DilemaFixer/Arr/main/arr.h
curl -o arr.c https://raw.githubusercontent.com/DilemaFixer/Arr/main/arr.c
```

### Windows
```cmd
curl -o arr.h https://raw.githubusercontent.com/DilemaFixer/Arr/main/arr.h
curl -o arr.c https://raw.githubusercontent.com/DilemaFixer/Arr/main/arr.c
```

## 🔧 API and Usage Examples

### Dynamic Array

A generic, dynamic array implementation that stores void pointers and automatically resizes when needed.

#### Core Structure
```c
typedef struct {
    void** data;    // Pointer array for storing elements
    size_t size;    // Current number of elements
    size_t capacity; // Total capacity of the array
} arr_t;
```

#### Functions
```c
arr_t* arr_create(size_t initial_capacity);
// Creates a new dynamic array with specified initial capacity

void arr_destroy(arr_t* arr);
// Frees all resources associated with the array

bool arr_push(arr_t* arr, void* element);
// Adds an element to the end of the array

void* arr_get(arr_t* arr, size_t index);
// Retrieves the element at the specified index

bool arr_set(arr_t* arr, size_t index, void* element);
// Sets the element at the specified index

bool arr_remove(arr_t* arr, size_t index);
// Removes the element at the specified index

size_t arr_size(arr_t* arr);
// Returns the number of elements in the array

bool arr_resize(arr_t* arr, size_t new_capacity);
// Resizes the array to the specified capacity
```

#### Usage Example
```c
#include "arr.h"
#include <stdio.h>
#include <stdlib.h>

// Example of storing integers (must be heap-allocated for persistence)
void integer_example() {
    // Create a new array with initial capacity of 4
    arr_t* array = arr_create(4);
    
    // Add some integers to the array
    for (int i = 0; i < 10; i++) {
        int* value = malloc(sizeof(int));
        *value = i * 10;
        arr_push(array, value);
    }
    
    // Access elements
    for (size_t i = 0; i < arr_size(array); i++) {
        int* value = arr_get(array, i);
        printf("Element at index %zu: %d\n", i, *value);
    }
    
    // Modify an element
    int* new_value = malloc(sizeof(int));
    *new_value = 500;
    arr_set(array, 5, new_value);
    
    // Remove an element
    arr_remove(array, 2);
    
    // Clean up (free the array and its data)
    for (size_t i = 0; i < arr_size(array); i++) {
        free(arr_get(array, i));
    }
    arr_destroy(array);
}
```

Required headers: `arr.h`, `stdio.h`, `stdlib.h`
