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
    char name[50], familyName[50];
    int yearOfBirth;
    struct Person * next;
};

void PushToList(struct Person *next_person,struct Person *previous_person ){
    next_person = malloc(sizeof(struct Person));
    strcpy(next_person->name , "Some name");
    strcpy(next_person->familyName, "Some surname");
    next_person->yearOfBirth = 1998;
    
    printf("%p", previous_person);
    next_person->next = NULL;
    printf("%p", previous_person);
    previous_person->next = next_person;
    
//    free(next_person);
};

int main(int argc, const char * argv[]) {
    struct Person *head;
    
    head = malloc(sizeof(struct Person));
    strcpy(head->name, "Maria");
    head->yearOfBirth = 2000;
    head->next = NULL;
    strcpy(head->familyName, "Namikova");
    
    struct Person *person1 = NULL;
    person1 = malloc(sizeof(struct Person));
    struct Person *person2 = NULL;
    
    PushToList(person1, head);
    PushToList(person2, person1);
    
    struct Person *current = head;
    
    while (current != NULL) {
        printf("%d: , ", current->yearOfBirth);
        current = current->next;
    }
    
    
    return 0;
}
