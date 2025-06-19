#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 1
#define SUCCESS_CODE 0
#define FAIL_CODE 1
#define EXPAND_COEFFICIENT 2
#define SUCCESS_MESSAGE ""
#define INIT_ERROR "Initializing error!"
#define EXPAND_ERROR "Expanding error!"
#define SHRINK_ERROR "Shrinking error!"
#define INDEX_ERROR "Index out of range!"

// #define RETURN_EXCEPTION(code, message) { \ 
//     struct DynamicArrayException* exit_value = {code, message}; \
//     return exit_value; \
//     }

typedef struct {
    int exit_code;
    char* error_message;
} DynamicArrayError;

typedef struct {
    int* head;
    size_t current_size;
    size_t max_capacity;
} DynamicArray;

// Create exception to return 
DynamicArrayError returnException(int exit_code, char* error_message){
    DynamicArrayError exit_value = {exit_code, error_message};
    return exit_value;
}

// Initialize dynamic array
DynamicArrayError initArray(DynamicArray* arr){
    arr->head = (int*) calloc(INIT_SIZE, sizeof(int));

    if (!arr->head){
        return returnException(FAIL_CODE, INIT_ERROR);
    }

    arr->current_size = 0;
    arr->max_capacity = INIT_SIZE;

    return returnException(SUCCESS_CODE, SUCCESS_MESSAGE);
}

// Free dynamic array
void freeArray(DynamicArray* arr){
    free(arr->head);
    free(arr);
}

// Expand the array by factor of the defined coefficient
DynamicArrayError expandArray(DynamicArray* arr){
    size_t new_max_capacity = EXPAND_COEFFICIENT * arr->max_capacity;
    arr->head = (int*) realloc(arr->head, new_max_capacity * sizeof(int));

    if (!arr->head){
        return returnException(FAIL_CODE, EXPAND_ERROR);
    }

    arr->max_capacity = new_max_capacity;

    return returnException(SUCCESS_CODE, SUCCESS_MESSAGE);
}

// Push value into the back of the dynamic array
DynamicArrayError pushBack(DynamicArray* arr, int value){
    if (arr->current_size == arr->max_capacity){
        DynamicArrayError exit_value = expandArray(arr);

        if (exit_value.exit_code == FAIL_CODE){
            return exit_value;
        }
    }

    arr->head[arr->current_size] = value;
    arr->current_size++;

    return returnException(SUCCESS_CODE, SUCCESS_MESSAGE);
}

// Shrink the array by factor of the defined coefficients
DynamicArrayError shrinkArray(DynamicArray* arr){
    size_t new_max_capacity = arr->max_capacity / EXPAND_COEFFICIENT;
    arr->head = (int*) realloc(arr->head, new_max_capacity * sizeof(int));

    if (!arr->head){
        return returnException(FAIL_CODE, SHRINK_ERROR);
    }

    arr->max_capacity = new_max_capacity;

    return returnException(SUCCESS_CODE, SUCCESS_MESSAGE);
}

// Remove last element of the array
DynamicArrayError popBack(DynamicArray* arr){
    if (arr->current_size <= arr->max_capacity / EXPAND_COEFFICIENT){
        DynamicArrayError exit_value = shrinkArray(arr);

        if (exit_value.exit_code == FAIL_CODE){
            return exit_value;
        }
    }

    arr->current_size--;

    return returnException(SUCCESS_CODE, SUCCESS_MESSAGE);
}

// Place in value pointer the value at the given index
DynamicArrayError getAt(DynamicArray* arr, size_t index, int* value){
    if (index >= arr->current_size){
        return returnException(FAIL_CODE, INDEX_ERROR);
    }

    *value = arr->head[index];

    return returnException(SUCCESS_CODE, SUCCESS_MESSAGE);
}

// Set the given value in the given index
DynamicArrayError setAt(DynamicArray* arr, size_t index, int value){
    if (index >= arr->current_size){
        return returnException(FAIL_CODE, INDEX_ERROR);
    }

    arr->head[index] = value;

    return returnException(SUCCESS_CODE, SUCCESS_MESSAGE);
}

// Print array
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

int main(){
    DynamicArray* arr = (DynamicArray*) malloc(sizeof(DynamicArray*));
    DynamicArrayError exit_value = initArray(arr);
    printf("%d", exit_value.exit_code);

    exit_value = pushBack(arr, 1);
    printf("%d", exit_value.exit_code);

    exit_value = setAt(arr, 2, 3);
    printf("%d", exit_value.exit_code);
    printf("%s", exit_value.error_message);

    int n;
    exit_value = getAt(arr, 0, &n);
    printf("%d", n);
    printf("%d", exit_value.exit_code);

    for(int i = 2; i < 10; i++){
        exit_value = pushBack(arr, i);
    }

    printArray(arr);
}
