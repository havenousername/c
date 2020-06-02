//
//  main.c
//  substring_search
//
//  Created by Andrei Cristea on 2020. 06. 01..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <stdio.h>

#define SIZE_STR 100
#define SIZE_SUB_STR 20

// str = This is my first string
// sub_str = first
// ecpected output = 2

int main(int argc, const char * argv[]) {
    char str[SIZE_STR];
    char sub_str[SIZE_SUB_STR];
    
    printf("Please provide string:\n");
    scanf("%[^\n]", str);
    printf("Please provide substring:\n");
    scanf("%s", sub_str);
    
    int index = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char sub[SIZE_SUB_STR];
        int k = 0;
        for (int j = i; str[j] != ' '; j++) {
            sub[k] = sub[j];
            k++;
        }
        int j = 0;
        while (sub_str[j] != '\0' && sub_str[j] == sub[j]) {
            j++;
        }
        if (str[j] == '\0') {
            index = j;
        }
    }
    
    printf("\n");
    printf("%d", index);
    
    return 0;
}
