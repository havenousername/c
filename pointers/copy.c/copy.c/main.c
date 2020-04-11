//
//  main.c
//  copy.c
//
//  Created by Andrei Cristea on 2020. 04. 11..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_LENGTH 5
#define CHAR_LENGTH 10

struct Person {
    char name[CHAR_LENGTH];
    char family_name[CHAR_LENGTH];
    int year_of_birth;
};

void scanP(struct Person *users){
    for (int i = 0; i < ARRAY_LENGTH; i++) {
//        strcpy(users[i].family_name, "Vendatta");
//        strcpy(users[i].name, "V");
//        users[0].year_of_birth = 2090;
        printf("Enter name:\n");
        scanf("%s", (users+i)->name);
        printf("Enter surname:\n");
        scanf("%s", (users+i)->family_name);
        printf("Enter year of birth:\n");
        scanf("%d", &(users+i)->year_of_birth);
    }
}

void printP(struct Person *users){
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        printf("%s\n", (users+i)->name);
        printf("%s\n", (users+i)->family_name);
        printf("%d\n", (users+i)->year_of_birth);
    }
}

int main(int argc, const char * argv[]) {
    struct Person users[ARRAY_LENGTH];
    
    strcpy(users[0].family_name, "Vasea");
    strcpy(users[0].name, "Vasea");
    users[0].year_of_birth = 1990;
    scanP(&users[0]);
    printP(&users[0]);
    struct Person* u_point = &users[0];
//    scanf("%s", (u_point)->family_name);
    printf("%s", (u_point)->family_name);
    return 0;
}
