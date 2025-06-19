#include "dynamicArray.h"

int main(){
    // Initialize array, print exit code (Wanted: 0)
    DynamicArray* arr = (DynamicArray*) malloc(sizeof(DynamicArray*));
    DynamicArrayError exit_value = initArray(arr);
    printf("%d\n", exit_value);

    // Fill array with values 1 - 10, print current_length and max_capacity each time (Wanted: 0 times 10)
    for(int i = 1; i < 11; i++){
        exit_value = pushBack(arr, i);
        printf("Current length: %ld, max capacity: %ld, exit code: %d\n", arr->current_size, arr->max_capacity, exit_value);
    }

    // Test successful getAt. (Wanted: 8) 
    int n; 
    exit_value = getAt(arr, 7, &n);
    printf("%d", n);

    // Test successful setAt. (Wanted: 15)
    exit_value = setAt(arr, 5, 15);
    exit_value = getAt(arr, 5, &n);
    printf("%d", n);

    // Test unsuccesful getAt. (Wanted: 4)
    exit_value = getAt(arr, 18, &n);
    printf("%d", exit_value);

    // Test unsuccessful setAt. (Wanted: 4)
    exit_value = setAt(arr, -1, 5);
    printf("%d", exit_value);

    //Remove all elements, test shrink.
    for(int i = 0; i < 10; i++){
        exit_value = popBack(arr);
        printf("Current length: %ld, max capacity: %ld, exit code: %d\n", arr->current_size, arr->max_capacity, exit_value);
    }
}