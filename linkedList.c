#include "linkedList.h"

LinkedListError initList(LinkedList* list){
    list->head = NULL;
}

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
        return ALLOCATION_ERROR;
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

LinkedListError append(LinkedList* list, int value){
    Node* iterator = list->head;

    if (iterator == NULL){
        return addFirstNode(list, value);
    }

    while (iterator->next != NULL){
        iterator = iterator->next;
    }

    return initNode(iterator->next, value);
}

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
Points the given pointer to the element at the given index of the given list.

@param list - given list.
@param index - given index.
@param pointer - given pointer.

@return LinkedListError with exit code.
*/
LinkedListError getNodeAt(LinkedList* list, size_t index, Node* pointer){
    Node* iterator = list->head;

    if (iterator == NULL){
        return INDEX_ERROR;
    }

    for (int i = 0; i < index; i++){
        if (iterator->next == NULL){
            return INDEX_ERROR;
        }

        iterator = iterator->next;
    }

    pointer = iterator;
    return SUCCESS;
}

LinkedListError insert(LinkedList* list, size_t index, int value){
    Node* iterator;

    if (index == 0){
        return addFirstNode(list, value);
    }
    
    LinkedListError exit_value = getNodeAt(list, index - 1, iterator);

    if (exit_value != SUCCESS){
        return exit_value;
    }

    Node* tmp;
    LinkedListError exit_value = initNode(tmp, value);

    if (exit_value != SUCCESS){
        return exit_value;
    }

    tmp->next = iterator->next;
    iterator->next = tmp;

    return SUCCESS;
}

/*
Removes the first node of a list.

@param list - list to remove node from.

@return LinkedListError with exit code.
*/
LinkedListError removeFirstNode(LinkedList* list){
    Node* tmp = list->head->next;

    if (tmp == NULL){
        return INDEX_ERROR;
    }

    free(list->head);
    list->head = tmp;

    return SUCCESS;
}

LinkedListError removeAt(LinkedList* list, size_t index){
    Node* iterator;

    if (index == 0){
        return removeFirstNode(list);
    }

    LinkedListError exit_value = getNodeAt(list, index - 1, iterator);

    if (exit_value != SUCCESS){
        return exit_value;
    }

    Node* tmp = iterator->next;
    free(iterator->next);
    iterator->next = tmp;

    return SUCCESS;
}

LinkedListError getAt(LinkedList* list, size_t index, int* value){
    Node* tmp;
    LinkedListError exit_value = getNodeAt(list, index, tmp);

    if (exit_value != SUCCESS){
        return exit_value;
    }

    *value = tmp->value;

    return SUCCESS;
}

LinkedListError setAt(LinkedList* list, size_t index, int value){
    Node* tmp;

    LinkedListError exit_value = getNodeAt(list, index, tmp);

    if (exit_value != SUCCESS){
        return exit_value;
    }

    tmp->value = value;

    return SUCCESS;
}

size_t len(LinkedList* list){
    size_t size = 0;
    Node* iterator = list->head;

    while (iterator != NULL){
        size++;
        iterator = iterator->next;
    }

    return size;
}

void printList(LinkedList* list){
    Node* iterator = list->head;

    if (iterator == NULL){
        printf("\n");
    }
    else{
        while (iterator->next != NULL){
            printf("%d %s ", iterator->value, CONNECTING_SIGN);
        }
        printf("%d\n", iterator->value);
    }
}

