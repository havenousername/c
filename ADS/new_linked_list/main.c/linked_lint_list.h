//
//  linked_lint_list.h
//  main.c
//
//  Created by Andrei on 11/29/20.
//

#ifndef linked_lint_list_h
#include "action_type.h"

// integer list
struct int_linked_list {
    int value;
    struct int_linked_list* next;
};

typedef struct int_linked_list int_linked_list;

// methods

// append new value to the list
void append(int_linked_list** list, int value, int type) {
    // allocating memory for the new b
    int_linked_list* headList = (int_linked_list*)malloc(sizeof(int_linked_list));
    
    headList->value = value;
    headList->next = NULL;

    if (*list == NULL) {
        *list = headList;
    } else if((ActionType)type == BACK) {
        int_linked_list* temp = *list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = headList;
    } else if((ActionType)type == FRONT) {
        headList->next = *list;
        *list = headList;
    } else {
        int_linked_list* temp = *list;
        
        while (temp != NULL) {
            if (temp->value == type) {
                break;;
            }
            temp = temp->next;
        }
        if (temp != NULL) {
            headList->next = temp->next;
        } else {
            temp = headList;
        }
        temp->next = headList;
    }
}

// delete the last element in list
void delete(int_linked_list** list, ActionType type) {
    int_linked_list* temp = *list;
    if (temp == NULL) {
        return;
    }
    if (type == FRONT) {
        *list = temp->next;
    } else {
        if (temp->next == NULL) {
            *list = NULL;
        } else {
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            temp->next = NULL;
        }
    }
};

int_linked_list search(int_linked_list* list, int searchValue) {
    int_linked_list* temp = list;
    
    while (temp != NULL && temp->value != searchValue) {
        temp = temp->next;
    }
    if (temp == NULL) {
        int_linked_list l;
        l.value = -1;
        l.next = NULL;
        return  l;
    }
    
    return *temp;
}

int_linked_list* getListMaximum(int_linked_list* list){
    if (list == NULL) {
        return NULL;
    } else {
        int_linked_list* max = list;
        int_linked_list* temp = list;
        
        while (temp != NULL) {
            if (temp->value > max->value) {
                max = temp;
            }
            temp = temp->next;
        }
        return max;
    }
};

int_linked_list* getListSecondMaximum(int_linked_list* list) {
    if (list == NULL) {
        return NULL;
    } else if(list->next == NULL) {
        return NULL;
    } else {
        int_linked_list* temp = list;
        int_linked_list* max = (int_linked_list*)malloc(sizeof(int_linked_list));
        int_linked_list* second_max = (int_linked_list*)malloc(sizeof(int_linked_list));
        
        if (temp->value < temp->next->value) {
            max = temp->next;
            second_max = temp;
        } else {
            max = temp;
            second_max = temp->next;
        }
        
        temp = temp->next->next;
        
        while (temp != NULL) {
            if (temp->value < second_max->value) {
                break;
            } else if(temp->value < max->value) {
                second_max = temp;
            } else {
                second_max = max;
                max = temp;
            }
            
            temp = temp->next;
        }
        
        return second_max;
    }
}

// MaxSelection Sort Algorithm
int_linked_list* maxSelectionSort(int_linked_list* list) {
    int_linked_list* sorted = NULL;
    
    while (list != NULL) {
        int_linked_list* max = list;
        int_linked_list* max_prev = NULL;
        
        int_linked_list* temp = list->next;
        int_linked_list* pprev = list;
        while (temp != NULL) {
            if (temp->value > max->value) {
                max = temp;
                max_prev = pprev;
            }
            
            pprev = temp;
            temp = temp->next;
        }
        if (max_prev == NULL) {
            list = max->next;
        } else {
            max_prev->next = max->next;
        }
        
        max->next = sorted;
        sorted = max;
    }
   
    return sorted;
};

// Insertion sort of list
int_linked_list* insersionSort(int_linked_list* list) {
    int_linked_list* sorted = NULL;

    while (list != NULL) {
        int_linked_list* temp = list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        int_linked_list* temp_sorted = sorted;
        int_linked_list* temp_prev = NULL;
        int isInserted = 0;
        while (temp_sorted != NULL) {
            if (temp_sorted->value > temp->value) {
                isInserted = 1;
                if (temp_prev == NULL) {
                    append(&sorted, temp->value, BACK);
                } else {
                    append(&sorted, temp->value, temp_prev->value);
                }
                break;
            }
            temp_prev = temp_sorted;
            temp_sorted = temp_sorted->next;
        }
        if (isInserted == 0) {
            if (sorted == NULL) {
                append(&sorted, temp->value, FRONT);
            } else {
                append(&sorted, temp->value, BACK);
            }
        }
        delete(&list, BACK);
    }
    
    return sorted;
};

void insersionSortVoid(int_linked_list** list) {
    int_linked_list* sorted = NULL;
    int_linked_list* local = *list;
    
    while (local != NULL) {
        int_linked_list* temp = local;
        local = local->next;
        int_linked_list* sorted_temp = sorted;
        
        if (sorted == NULL) {
            temp->next = NULL;
            sorted = temp;
        } else {
            if (temp->value <= sorted_temp->value) {
                temp->next = sorted_temp;
                sorted = temp;
            } else {
                while (sorted_temp->next != NULL && sorted_temp->value <= temp->value) {
                    sorted_temp = sorted_temp->next;
                }
                temp->next = sorted_temp->next;
                sorted_temp->next = temp;
            }
        }
    }
    
    *list = sorted;
};


// print list
void print_list(int_linked_list* list) {
    int_linked_list *temp = list;
    if (temp == NULL) {
        printf("NULL\n");
        return;
    }
    printf("[");
    do {
        printf(" %d -> ", temp->value);
        temp = temp->next;
    } while(temp != NULL);
    printf("]\n");
}





// overriding the name

#define linked_lint_list_h


#endif /* linked_lint_list_h */
