#include "linkedList.h"

/*
Initialize linked list, set first node of list to null. 

@param list - pointer to list to initialize.

@return LinkedListError with exit code.
*/
LinkedListError initList(LinkedList* list){
    list->head = NULL;
}

/*
Free given list.

@param list - list to free. 
*/
void freeList(LinkedList* list){
    Node* head = list->head;
    Node* tmp;

    while (head != NULL){
        tmp = head;
        head = head->next;
        free(tmp);
    }

    free(list);
}

/*
Initialize a node with the given value. 

@param node - pointer to the soon-to-be initialized node.
@param value - value for initialized node. 

@return LinkedListError with exit code.
*/
LinkedListError initNode(Node* node, int value){
    node = (Node*) calloc(1, sizeof(Node*));

    if (!node){
        return INIT_NODE_ERROR;
    }

    node->value = value;
    node->next = NULL;

    return SUCCESS;
}

/*
Create first element of a list.

@param list - list to add element to.
@param value - value of the to-be first element.

@return LinkedListError with exit code.
*/
LinkedListError addFirstNode(LinkedList* list, int value){
    return initNode(list->head, value);
}

/*
Add an element with the given value to the given list. 

@param list - the given list to append to.
@param value - the value to append.

@return LinkedListError with exit code.
*/
LinkedListError append(LinkedList* list, int value){
    Node* tmp = list->head;

    if (tmp == NULL){
        return addFirstNode(list, value);
    }

    while (tmp->next != NULL){
        tmp = tmp->next;
    }

    return initNode(tmp->next, value);
}

/* 
Add element with the given value to the beginning of the given list.

@param list - list to prepend to.
@param value - value of the element to prepend.

@return LinkedListError with exit code.
*/
LinkedListError prepend(LinkedList* list, int value){
    Node* tmp = list->head;

    if (tmp == NULL) {
        return addFirstNode(list, value);
    }

    LinkedListError exit_value = initNode(list->head, value);

    if (exit_value != SUCCESS){
        return exit_value;
    }

    list->head->next = tmp;

    return SUCCESS;
}

/*
Insert element with the given value in the given index of the given list.

@param list - list to insert in.
@param index - index to insert at.
@param value - value of element to insert.

@return LinkedListError with exit code.
*/
LinkedListError insert(LinkedList* list, size_t index, int value){
    Node* tmp = list->head;

    if (index == 0){
        return prepend(list, value);
    }

    for(int i = 1; i < index; i++){
        
    }
}

