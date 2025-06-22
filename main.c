#include <stdio.h>

#include "linkedList.h"

int main(){
    // Test for LinkedList
    // Init list
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList*));
    LinkedListError exit_value = initList(list);

    // Append values 1-10
    for(int i = 1; i <= 10; i++) {
        exit_value = append(list, i);
        printf("%d", exit_value);
    }
    puts("\n");
    printList(list);

    // prepend 0
    exit_value = prepend(list, 0);
    printList(list);

    // print length
    printf("%ld\n", len(list));

    // insert 15 at index 5
    exit_value = insert(list, 5, 15);
    printList(list);

    // getAt test
    int x;
    for(int i = 0; i < 12; i++){
        exit_value = getAt(list, i, &x);
        printf("Exit code: %d, Value: %d\n", exit_value, x);
    }

    // setAt test
    for(int i = 0; i < 12; i++){
        exit_value = setAt(list, i, 12 - i);
    }
    printList(list);

    // remove tests
    exit_value = removeAt(list, 5);
    printList(list);

    exit_value = removeAt(list, 11);
    printList(list);
    printf("%d\n", exit_value);

    // indexOf test
    size_t y;
    exit_value = indexOf(list, 9, &y);
    printf("%ld\n", y);

    // RemoveAll test
    exit_value = append(list, 12);
    exit_value = removeAll(list, 12);
    printList(list);
}