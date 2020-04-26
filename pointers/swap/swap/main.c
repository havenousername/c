//
//  main.c
//  swap
//
//  Created by Andrei Cristea on 2020. 04. 10..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void swap(char** n,char** s){
    char *tempArr = *n;
    *n = *s;
    *s = tempArr;
};

void swapTwo(char *n1,char *n2){
    char *temp = (char *)malloc((strlen(n1) + 1) * sizeof(char));
    strcpy(temp, n1);
    strcpy(n1, n2);
    strcpy(n2, temp);
    free(temp);
}

void revert(char *str_one,char *str_two){
    long length, len;
    int index;
    
    char tempOne;
    char tempTwo;
    
    length = strlen(str_one);
    len = strlen(str_two);
    
    char *startTwo = str_two;
    char *endTwo = str_two + len - 1;
    
    char *startOne = str_one;
    char *endOne = str_one + length - 1;
    
    for (index = 0; index < len / 2; index++) {
        tempTwo = *endTwo;
        *endTwo = *startTwo;
        *startTwo = tempTwo;
        
        startTwo++;
        endTwo--;
    }
    
    for (index = 0; index < length / 2; index++) {
        tempOne = *endOne;
        *endOne = *startOne;
        *startOne = tempOne;
        
        startOne++;
        endOne--;
    }
};

int main(int argc, const char * argv[]) {
    char name[] = "George";
    char secondName[] = "Fillip";
    swapOne(&name[0], &secondName[0]);
//    swapTwo(&name, &secondName);
//    printf("%s %s\n",name, secondName);
//
//    char n1[] = "George";
//    char n2[] = "Fillip";
//    swapTwo(n1, n2);
//    printf("%s %s\n", n1, n2);
//
    
//    revert(name, secondName);
    
    printf("%s %s\n", name, secondName);

    
    return 0;
}
