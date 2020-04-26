//
//  main.c
//  list
//
//  Created by Andrei Cristea on 2020. 04. 24..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <stdio.h>

struct node {
    int value;
    struct node *next;
};
typedef struct node node_t;


void print_node(node_t *head){
    node_t *current = head;
    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}

node_t new_node(int value){
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return *result;
}

int main(int argc, const char * argv[]) {
    node_t *head;
    node_t *temp;
    
    temp = new_node(1);
    head = temp;
    temp = new_node(23)
    
    
    
    
    
//    print_node(head);
    
    return 0;
}
