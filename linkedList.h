#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CONNECTING_SIGN "->"

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

typedef enum {
    SUCCESS = 0,
    ALLOCATION_ERROR,
    INDEX_ERROR,
    VALUE_NOT_FOUND
} LinkedListError;

/*
Initialize linked list, set first node of list to null. 

@param list - pointer to list to initialize.

@return LinkedListError with exit code.
*/
LinkedListError initList(LinkedList* list);

/*
Free given list.

@param list - list to free. 
*/
void freeList(LinkedList* list);

/*
Add an element with the given value to the given list. 

@param list - the given list to append to.
@param value - the value to append.

@return LinkedListError with exit code.
*/
LinkedListError append(LinkedList* list, int value);

/* 
Add element with the given value to the beginning of the given list.

@param list - list to prepend to.
@param value - value of the element to prepend.

@return LinkedListError with exit code.
*/
LinkedListError prepend(LinkedList* list, int value);

/*
Insert element with the given value in the given index of the given list.

@param list - list to insert in.
@param index - index to insert at.
@param value - value of element to insert.

@return LinkedListError with exit code.
*/
LinkedListError insert(LinkedList* list, size_t index, int value);

/*
Remove the element at the given index of the given list.

@param list - the list to remove from.
@param index - the index to remove at.

@return LinkedListError with exit code.
*/
LinkedListError removeAt(LinkedList* list, size_t index);

/*
Points the given pointer to the value of the element at the given index of the given list.

@param list - given list.
@param index - given index.
@param value - pointer to the to-be value.

@return LinkedListError with exit code.
*/
LinkedListError getAt(LinkedList* list, size_t index, int* value);

/*
Set the element at the given index of the given list to be the given value.

@param list - given list.
@param index - given index.
@param value - given value to set.

@return LinkedListError with exit code.
*/
LinkedListError setAt(LinkedList* list, size_t index, int value);

/*
Returns the length of the given list.

@param list - given list.

@return the size of the given list.
*/
size_t len(LinkedList* list);

/*
Prints the given list.

@param list - given list.
*/
void printList(LinkedList* list);

/*
Return the index of the given value in the given list. Returns the first occurence if multiple exist. 

@param list - the given list. 
@param value - the given value to find. 
@param index - the pointer to place the index of the value at. 

@return LinkedListError with exit code.
*/
LinkedListError indexOf(LinkedList* list, int value, size_t* index);

/*
Removes all occurences of given value from a given list. 

@param list - the given list. 
@param value - the given value. 

@return LinkedListError with exit code.
*/
LinkedListError removeAll(LinkedList* list, int value);

/*
Sorts the given list inplace.

@param list - the list to sort. 

@return LinkedListError with exit code.
*/
LinkedListError sortList(LinkedList* list);