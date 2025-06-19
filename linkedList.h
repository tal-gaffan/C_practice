#include <stdio.h>

typedef struct {
    int value;
    Node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;

typedef enum {
    SUCCESS = 0,
    INIT_NODE_ERROR,
    INDEX_ERROR
} LinkedListError;

LinkedListError initList(LinkedList* list);
void freeList(LinkedList* list);

LinkedListError append(LinkedList* list, int value);
LinkedListError prepend(LinkedList* list, int value);

LinkedListError insert(LinkedList* list, size_t index, int value);
LinkedListError removeAt(LinkedList* list, size_t index);

LinkedListError getAt(LinkedList* list, size_t index, int* value);
LinkedListError setAt(LinkedList* list, size_t index, int value);

size_t len(LinkedList* list);
void printList(LinkedList* list);
