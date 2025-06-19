#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 1
#define EXPAND_COEFFICIENT 2

typedef enum {
    SUCCESS = 0,
    INIT_ERROR,
    EXPAND_ERROR,
    SHRINK_ERROR,
    INDEX_ERROR,
} DynamicArrayError;

typedef struct {
    int* head;
    size_t current_size;
    size_t max_capacity;
} DynamicArray;

DynamicArrayError initArray(DynamicArray* arr);
void freeArray(DynamicArray* arr);

DynamicArrayError expandArray(DynamicArray* arr);
DynamicArrayError shrinkArray(DynamicArray* arr);

DynamicArrayError pushBack(DynamicArray* arr, int value);
DynamicArrayError popBack(DynamicArray* arr);

DynamicArrayError getAt(DynamicArray* arr, size_t index, int* value);
DynamicArrayError setAt(DynamicArray* arr, size_t index, int value);

void printArray(const DynamicArray* arr);
