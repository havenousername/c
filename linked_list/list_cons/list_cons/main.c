//
//  main.c
//  list_cons
//
//  Created by Andrei Cristea on 2020. 05. 01..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct list{
    int num;
    struct list *prev;
    struct list *next;
};

typedef struct list List;


List* newList(int in){
    List *newList = (List*)malloc(sizeof(List));
    newList->num = in;
    newList->next = NULL;
    newList->prev = NULL;
    
    return newList;
};

int main(int argc, const char * argv[]) {
    List head = *newList(12);
    
    
    printf("%d\n",head.num);
    return 0;
}
