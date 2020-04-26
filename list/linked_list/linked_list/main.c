//
//  main.c
//  linked_list
//
//  Created by Andrei Cristea on 2020. 04. 24..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct point {
    int x,y;
    char name[50];
    struct point * next;
};



int main(int argc, const char * argv[]) {
    struct point *head;
//    char *myString = strdup("My String");
//
    head = malloc(sizeof(struct point));
    head->x = 1;
    head->y = 2;
    strcpy(head->name, "George");
    head->next = NULL;
    
    struct point * p1;
    struct point * previous;
    
    p1 = malloc(sizeof(struct point));
    head->next = p1;
    p1->x = 2;
    p1->y = 3;
    strcpy(p1->name, "Fedor");
    p1->next = NULL;
    previous = p1;
    
    p1 = malloc(sizeof(struct point));
    previous->next = p1;
    p1->x = 3;
    p1->y = 5;
    strcpy(p1->name, "Eric");
    p1->next = NULL;
    
    
    struct point *current = head;
    while (current != NULL) {
        printf("x = %d; y = %d; name = %s;\n", current->x, current->y, current->name);
        current = current->next;
    }
    
    
    return 0;
}
