//
//  main.c
//  main.c
//
//  Created by Andrei on 11/20/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_lint_list.h"
#include "action_type.h"

typedef struct int_linked_list int_linked_list;

int main(int argc, const char * argv[]) {
    // decrale and initialize list
    int_linked_list* list = NULL;
    
    
    // test append
//    srand((unsigned)time(NULL));
//    for (int i = 0; i < 50; i++) {
//        append(&list, rand() % 100, BACK);
//    }

    
    append(&list, 6, BACK);
    append(&list, 8, BACK);
    append(&list, 3, BACK);
    append(&list, 5, 8);
    append(&list, 9, 5);
    

    
    // debug and print
    print_list(list);
    
//    int_linked_list l = search(list, 1000);
//    int_linked_list* max = getListMaximum(list);
//    int_linked_list* second_max = getListSecondMaximum(list);
//    int_linked_list* sorted = maxSelectionSort(list);
//    printf("%d", max->value);
//    printf("%d", second_max->value);
    
//    int_linked_list* s =  maxSelectionSort(second_max);
//    int_linked_list* sorted = insersionSort(list);
    insersionSortVoid(&list);
    print_list(list);
//    print_list(sorted);

    
    return 0;
}
