#include "dynamicArray.h"

/* 
Initialize dynamic array.

@param arr - pointer to the initialized array.

@return DynamicArrayError enum with exit code.
*/
DynamicArrayError initArray(DynamicArray* arr){
    arr->head = (int*) calloc(INIT_SIZE, sizeof(int));

    if (!arr->head){
        return INIT_ERROR;
    }

    arr->current_size = 0;
    arr->max_capacity = INIT_SIZE;

    return SUCCESS;
}

/* 
Free dynamic array.

@param arr - the array to free. 
*/
void freeArray(DynamicArray* arr){
    free(arr->head);
    free(arr);
}

/*
Expand the given array by factor of the defined EXPAND_COEFFICIENT.

@param arr - the array to expand. 

@return DynamicArrayError enum with exit code.
*/
DynamicArrayError expandArray(DynamicArray* arr){
    size_t new_max_capacity = EXPAND_COEFFICIENT * arr->max_capacity;
    arr->head = (int*) realloc(arr->head, new_max_capacity * sizeof(int));

    if (!arr->head){
        return EXPAND_ERROR;
    }

    arr->max_capacity = new_max_capacity;

    return SUCCESS;
}

/* Push given value into the back of the given array. 

@param arr - the array to push the value into. 
@param value - the value to push. 

@return DynamicArrayError enum with exit code.
*/
DynamicArrayError pushBack(DynamicArray* arr, int value){
    if (arr->current_size == arr->max_capacity){
        DynamicArrayError exit_value = expandArray(arr);

        if (exit_value != SUCCESS){
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
DynamicArrayError shrinkArray(DynamicArray* arr){
    size_t new_max_capacity = arr->max_capacity / EXPAND_COEFFICIENT;
    arr->head = (int*) realloc(arr->head, new_max_capacity * sizeof(int));

    if (!arr->head){
        return SHRINK_ERROR;
    }

    arr->max_capacity = new_max_capacity;

    return SUCCESS;
}

/*
Deletes the last element of the given array. 

@param arr - the array to pop.

@return DynamicArrayError enum with exit code.
*/
DynamicArrayError popBack(DynamicArray* arr){
    if (arr->current_size <= arr->max_capacity / EXPAND_COEFFICIENT){
        DynamicArrayError exit_value = shrinkArray(arr);

        if (exit_value != SUCCESS){
            return exit_value;
        }
    }

    arr->current_size--;

    return SUCCESS;
}

/*
Place the element at the given index of the given array into the given pointer.

@param arr - the array to get the element from. 
@param index - the index to get the element from.
@param value - the pointer to place the element in.

@return DynamicArrayError enum with exit code
*/
DynamicArrayError getAt(DynamicArray* arr, size_t index, int* value){
    if (index >= arr->current_size && index < 0){
        return INDEX_ERROR;
    }

    *value = arr->head[index];

    return SUCCESS;
}

/* 
Set the given value in the given index of the given array.

@param arr - the array to insert the element in. 
@param index - the index to insert the element at.
@param value - the value to insert. 

@return DynamicArrayError enum with exit code
*/
DynamicArrayError setAt(DynamicArray* arr, size_t index, int value){
    if (index >= arr->current_size){
        return INDEX_ERROR;
    }

    arr->head[index] = value;

    return SUCCESS;
}

/*
Print the given array.

@param arr - the array to print.
*/
void printArray(const DynamicArray* arr){
    for(int i = 0; i < arr->current_size; i++){
        if (i == arr->current_size - 1){
            printf("%d\n", arr->head[i]);
        }
        else{
            printf("%d, ", arr->head[i]);
        }
    }
}
