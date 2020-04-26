//
//  main.c
//  string_operators
//
//  Created by Andrei Cristea on 2020. 04. 11..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <stdio.h>

int length(char* str){
    int i = 0;
    char *pointer = str;
    while (*(pointer+i) != '\0') {
        i++;
    }
    return i;
};

void copy_string(char* dist, char* src){
    for (int i = 0; i < length(src); i++) {
        *(dist + i) = *(src + i);
    }
}

void concat_string(char* first_string, char* second_string){
    
    while (*first_string) {
        first_string++;
    }
    
    while (*second_string) {
        *first_string = *second_string;
        second_string++;
        first_string++;
    }
    *first_string = '\0';
};

int main(int argc, const char * argv[]) {
    char str[] = "Hello";
    char str_two[] = "there";
//    int l = length(&str[0]);
    copy_string(&str[0], &str_two[0]);
//    concat_string(str, str_two);
    printf("%s\n", str);
    return 0;
}
