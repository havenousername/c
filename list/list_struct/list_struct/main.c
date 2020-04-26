//
//  main.c
//  list_struct
//
//  Created by Andrei Cristea on 2020. 04. 24..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person{
    char *name, *familyName;
    int yearOfBirth;
    struct Person * next;
};

typedef struct Person person;



void push(person *head,int year, char *name, char *family_name){
    person *current = head;
    while (current->next != NULL ) {
        current = current->next;
    }
    char *n = (char*)malloc(sizeof(name));
    char *f = (char*)malloc(sizeof(family_name));
    strcpy(n, name);
    strcpy(f, family_name);
    
    current->next = (person*)malloc(sizeof(person));
    current->next->yearOfBirth = year;
    current->next->familyName = f;
    current->next->name = n;
    
    current->next->next = NULL;
}

void print_list(person *head){
    person *current = head->next;
    while (current != NULL) {
        printf("Name: %s, Family Name: %s, Birth: %d\n", current->name, current->familyName, current->yearOfBirth);
        current = current->next;
    }
};

int main(int argc, const char * argv[]) {
    person *head;
    
    head = malloc(sizeof(person));
    head->next = NULL;
//    strncpy(head->name, "Maria", sizeof(char));
//    head->yearOfBirth = 2000;
    
//    strcpy(head->familyName, "Namikova");
    
    push(head, 1998, "Mark", "Antonoo");
    push(head, 1965, "Pablo", "Escabar");
    push(head, 2001, "Hesys", "Euosas");
    
    print_list(head);
    
    free(head);
    
    return 0;
}
