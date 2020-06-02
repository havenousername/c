//
//  main.c
//  sample.c
//
//  Created by Andrei Cristea on 2020. 06. 01..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

char *deconstructors(char* input){
    char *out = malloc(SIZE*2);
    int  j = 0;
    int i = 0;
    while (*(input+i) != '\0') {
        if (*(input+i) == '[') {
            i++;
//            printf("%c\n", *(input+i));
            for (int l = (int)*(input+i) ; l <= (int)*(input+i+2); l++) {
                *(out+j) = (char)(l);
                j++;
            }
            i++;
            i+=3;
        }else{
            *(out+j) = *(input+i);
            j++;
            i++;
        }
    }
    return &out[0];
};

// This is [f-o] to demo [a-z] my [a-b] [b-b] program [b-d]
int main(int argc, const char * argv[]) {
    char work_out[SIZE];
    scanf("%[^\n]", work_out);
    char expected[] = "This is fghijklmno to demo abcdefghijklmnopqrstuvwxyz my ab b program bcd";
//    deconstructors(&work_out[0]);
    int cmp = strcmp(deconstructors(&work_out[0]), expected);
    printf("%d",  cmp);
    return 0;
}
