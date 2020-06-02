//
//  main.c
//  heckerrank
//
//  Created by Andrei Cristea on 2020. 05. 15..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char *arr;
    int output[] = {0,0,0,0,0,0,0,0,0,0};
    size_t len;
    arr = NULL;
    getline(&arr, &len, stdin);
    int i = 0, place = 0;
    while(*(arr+i) != '\0'){
        if(*(arr+i) >= 48 && *(arr+i)  <= 57 && *(arr+i)  != ' '){
            char num = *(arr+i) ;
            place = (int)num;
            output[place] += 1;
        }
        i++;
    }
    for(int i = 0; i < 10; i++){
       printf("%d ", output[i]);
    }

    return 0;
}
