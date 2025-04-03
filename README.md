# Arr 🚀

![Build Status](https://img.shields.io/badge/build-passing-brightgreen)
![Version](https://img.shields.io/badge/version-1.0.0-blue)
![License](https://img.shields.io/badge/license-MIT-green)
![Language](https://img.shields.io/badge/language-C-blue)

A lightweight, dynamic array library in C providing flexible and easy-to-use array management with dynamic resizing capabilities.

## 📥 Installation

### Unix-based Systems (Linux, macOS)
```bash
# Download arr.h
curl -o arr.h https://raw.githubusercontent.com/DilemaFixer/Arr/main/arr.h

# Download arr.c
curl -o arr.c https://raw.githubusercontent.com/DilemaFixer/Arr/main/arr.c
```

### Windows
```powershell
# Download arr.h
Invoke-WebRequest -Uri https://raw.githubusercontent.com/DilemaFixer/Arr/main/arr.h -OutFile arr.h

# Download arr.c
Invoke-WebRequest -Uri https://raw.githubusercontent.com/DilemaFixer/Arr/main/arr.c -OutFile arr.c
```

## 🛠 API and Usage Examples

### Data Structure

```c
typedef struct {
    void** data;     // Pointer to the array of void pointers
    size_t size;     // Current number of elements in the array
    size_t capacity; // Total allocated capacity of the array
} Arr;
```

### Core Functions

#### Array Creation and Destruction

```c
// Create a new array with initial capacity
Arr* arr_create(size_t initial_capacity);

// Destroy and free the array
void arr_destroy(Arr* arr);
```

#### Element Manipulation

```c
// Add an element to the end of the array
bool arr_push(Arr* arr, void* element);

// Get an element at a specific index
void* arr_get(Arr* arr, size_t index);

// Set an element at a specific index
bool arr_set(Arr* arr, size_t index, void* element);

// Remove an element at a specific index
bool arr_remove(Arr* arr, size_t index);
```

#### Array Management

```c
// Get the current number of elements in the array
size_t arr_size(Arr* arr);

// Resize the array to a new capacity
bool arr_resize(Arr* arr, size_t new_capacity);
```

### Usage Example

```c
#include "arr.h"
#include <stdio.h>

int main() {
    // Create an array
    Arr* myArray = arr_create(4);

    // Push some elements
    int a = 10, b = 20, c = 30;
    arr_push(myArray, &a);
    arr_push(myArray, &b);
    arr_push(myArray, &c);

    // Get and print elements
    for (size_t i = 0; i < arr_size(myArray); i++) {
        int* element = (int*)arr_get(myArray, i);
        printf("%d ", *element);
    }

    // Clean up
    arr_destroy(myArray);
    return 0;
}
```

### Required Header

```c
#include "arr.h"
```
