#include "dynamicArray.h"

DynamicArrayError initArray(DynamicArray* arr) {
    arr->head = (int*) calloc(INIT_SIZE, sizeof(int));

    if (!arr->head) {
        return ALLOCATION_ERROR;
    }

    arr->current_size = 0;
    arr->max_capacity = INIT_SIZE;

    return SUCCESS;
}

void freeArray(DynamicArray* arr) {
    free(arr->head);
    free(arr);
}

/*
Expand the given array by factor of the defined EXPAND_COEFFICIENT.

@param arr - the array to expand. 

@return DynamicArrayError enum with exit code.
*/
DynamicArrayError expandArray(DynamicArray* arr) {
    size_t new_max_capacity = EXPAND_COEFFICIENT * arr->max_capacity;
    int* tmp = (int*) realloc(arr->head, new_max_capacity * sizeof(int));

    if (!tmp) {
        return ALLOCATION_ERROR;
    }

    arr->head = tmp;
    arr->max_capacity = new_max_capacity;

    return SUCCESS;
}

DynamicArrayError pushBack(DynamicArray* arr, int value) {
    if (arr->current_size == arr->max_capacity) {
        DynamicArrayError exit_value = expandArray(arr);

        if (exit_value != SUCCESS) {
            return exit_value;
        }
    }

    arr->head[arr->current_size] = value;
    arr->current_size++;

    return SUCCESS;
}

/* 
Shrink the given array by factor of the define EXPAND_COEFFICIENT. 

@param arr - the array to shrink.

@return DynamicArrayError enum with exit code.
*/
DynamicArrayError shrinkArray(DynamicArray* arr) {
    size_t new_max_capacity = arr->max_capacity / EXPAND_COEFFICIENT;
    int* tmp = (int*) realloc(arr->head, new_max_capacity * sizeof(int));

    if (!tmp) {
        return ALLOCATION_ERROR;
    }

    arr->head = tmp;
    arr->max_capacity = new_max_capacity;

    return SUCCESS;
}

DynamicArrayError popBack(DynamicArray* arr) {
    if (arr->current_size <= arr->max_capacity / EXPAND_COEFFICIENT) {
        DynamicArrayError exit_value = shrinkArray(arr);

        if (exit_value != SUCCESS) {
            return exit_value;
        }
    }

    arr->current_size--;

    return SUCCESS;
}

DynamicArrayError getAt(DynamicArray* arr, size_t index, int* value) {
    if (index >= arr->current_size) {
        return INDEX_ERROR;
    }

    *value = arr->head[index];

    return SUCCESS;
}

DynamicArrayError setAt(DynamicArray* arr, size_t index, int value) {
    if (index >= arr->current_size) {
        return INDEX_ERROR;
    }

    arr->head[index] = value;

    return SUCCESS;
}

void printArray(const DynamicArray* arr) {
    for(int i = 0; i < arr->current_size; i++) {
        if (i == arr->current_size - 1) {
            printf("%d\n", arr->head[i]);
        }
        else{
            printf("%d, ", arr->head[i]);
        }
    }
}
