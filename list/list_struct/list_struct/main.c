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
#include <stdbool.h>


// Creating new structure for the future lint list
struct Person{
    char *name, *familyName;
    int yearOfBirth;
    struct Person * next;
    struct Person * previous;
};

typedef struct Person person;

// Creating new list function
person *createNewList(int year, char *name, char *family_name){
    // Allocating dynamic memory space for the list
    person *head = (person*)malloc(sizeof(person));
    
    // Dealing with strings
    char *n = (char*)malloc(sizeof(strlen(name)));
    char *f = (char*)malloc(sizeof(strlen(name)));
    strcpy(n, name);
    strcpy(f, family_name);
    
    // Asigning values to the structure elements
    head->familyName = f;
    head->name = n;
    head->yearOfBirth = year;
    
    head->previous = NULL;
    head->next = NULL;
    

    // Return value
    return head;
};

// Additional function
person *pushHead(person *head, person *new_head){
    new_head->previous = NULL;
    new_head->next = head;
    head->previous = new_head;
//    head = new_head;
    return new_head;
};

// Function which pushes creates and pushed new lint list inside lint list
void push(person *head,int year, char *name, char *family_name){
    person *current = head;
    while (current->next != NULL ) {
        current = current->next;
    }
    char *n = (char*)malloc(sizeof(strlen(name)));
    char *f = (char*)malloc(sizeof(strlen(name)));
    strcpy(n, name);
    strcpy(f, family_name);
    
    
    current->next = (person*)malloc(sizeof(person));
    current->next->yearOfBirth = year;
    current->next->familyName = f;
    current->next->name = n;
    
    if (current->next != NULL) {
        current->next->previous = current;
    }
    current->next->next = NULL;
}


// Auxiliary function which prints single person structure
void printP(person p){
    char n1[100];
    char f1[100];
    if (p.name != NULL) {
        strcpy(n1, p.name);
        strcpy(f1, p.familyName);
        printf("Name: %s, Family Name: %s, Birth: %d\n", n1, f1, p.yearOfBirth);
    }else{
        printf("You have entered empty linked list.\nPlease redo it and try again.\n");
    }
}


// Prints linked list(Great for debuging)
void printList(person *head){
    printP(*head);
    person *current = head->next;
    while (current != NULL) {
        printP(*current);
        current = current->next;
    }
};

// Auxiliary function which will be used later in printPerson function
bool isEqualString(char *n1,char *n2){
    while (*n1 != '\0' || *n2 != '\0') {
        if(*n1 != *n2){
            return false;
        }else{
            (n1++);
            (n2++);
        }
    }
    return true;
};

// Returns the last value of linked list
person tail(person *head){
    person error = {};
    if (head->next == NULL ) {
        return *head;
    }
    
    person *current = head->next;
    person tail = *head->next;
    while (current != NULL) {
        current = current->next;
        if (current->next == NULL) {
            tail = *current;
            break;
        }
    }
    return tail;
}



// Prints the person which was given as a parameter
person findPerson(person *head, char *string){
    person *current = head;
    person error = {};
    while (current != NULL) {
        bool i = isEqualString(current->name, string);
        if (i) {
            return *current;
        }else{
            current = current->next;
        }
    }
    error.name = string;
    return error;
};

person *tail_two(person *head){
    person *previous = NULL;
    while (head != NULL) {
        previous = head;
        head = head->next;
    }
    return previous;
};

void printPerson(person *head, char *string){
    char str[100];
    strcpy(str, string);
    person p = findPerson(head, string);
    if (p.familyName != NULL) {
        printP(p);
    }else{
        printf("There is no such person in the list\n");
    }
};


// Swaps two elemest in the linked list.
// You should include the struct which stand before wanted structs(2) to swap
// And the one after the swaped ones.
void swap(person *before, person *swap1, person *swap2, person *after){
    before->next = before->next->next;
    after->previous = after->previous->previous;
    
    swap2->next = swap1;
    swap2->previous = before;
    
    swap1->next = after;
    swap1->previous = swap2;
}

void swapOne(person *swap1, person *swap2){
    person before = *swap1->previous;
    person after = *swap2->next;
    
    swap1->previous->next = swap1->previous->next->next;
    swap2->next->previous = swap2->next->previous->previous;
    
    swap2->next = swap1;
    swap2->previous = &before;
    
    swap1->next = &after;
    swap1->previous = swap2;
}

// Playground to check the functions
int main(int argc, const char * argv[]) {
    // Create new head
    person head = *createNewList(1999, "Vasea", "Bosnikov");
    person p;
    
//    printP(tail(&p));
    // Push new linked list
    push(&head, 1998, "Markinurianos", "Antonoo");
    push(&head, 1965, "Pablo", "Escabar");
    push(&head, 2001, "Hesys", "Euosas");
    push(&head, 2001, "He", "Eu");
    
    // Create another liked list
    person new_head = *createNewList(2000, "Lihoi", "Stephan");
    
    // Swap function
//    swap(&head, head.next, head.next->next, head.next->next->next);
    // Not working yet one
//    swapOne(head.next, head.next->next);
    
    // Push to the head function
//    person new = *pushHead(&head, &new_head);
    
    // Print single person
//    printP(head);
    
    // Print selected one
//    printPerson(&new, "ST");
    
    // Print list
//    printList(&new);
    // find tail
//    tail(head);
//    printP(tail(head));
//    printP(*tail_two(&p));
    
    return 0;
}
