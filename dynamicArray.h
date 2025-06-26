#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 1
#define EXPAND_COEFFICIENT 2

typedef enum {
    SUCCESS = 0,
    ALLOCATION_ERROR,
    INDEX_ERROR
} DynamicArrayError;

typedef struct {
    int* head;
    size_t current_size;
    size_t max_capacity;
} DynamicArray;

/* 
Initialize dynamic array.

@param arr - pointer to the initialized array.

@return DynamicArrayError enum with exit code.
*/
DynamicArrayError initArray(DynamicArray* arr);

/* 
Free dynamic array.

@param arr - the array to free. 
*/
void freeArray(DynamicArray* arr);

/* Push given value into the back of the given array. 

@param arr - the array to push the value into. 
@param value - the value to push. 

@return DynamicArrayError enum with exit code.
*/
DynamicArrayError pushBack(DynamicArray* arr, int value);

/*
Deletes the last element of the given array. 

@param arr - the array to pop.

@return DynamicArrayError enum with exit code.
*/
DynamicArrayError popBack(DynamicArray* arr);

/*
Place the element at the given index of the given array into the given pointer.

@param arr - the array to get the element from. 
@param index - the index to get the element from.
@param value - the pointer to place the element in.

@return DynamicArrayError enum with exit code
*/
DynamicArrayError getAt(DynamicArray* arr, size_t index, int* value);

/* 
Set the given value in the given index of the given array.

@param arr - the array to insert the element in. 
@param index - the index to insert the element at.
@param value - the value to insert. 

@return DynamicArrayError enum with exit code
*/
DynamicArrayError setAt(DynamicArray* arr, size_t index, int value);

/*
Print the given array.

@param arr - the array to print.
*/
void printArray(const DynamicArray* arr);
