//
//  main.c
//  quadratic
//
//  Created by Andrei Cristea on 2020. 06. 01..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

bool quadratic_eq(int *x1, int *x2){
    int a = 0, b = 0, c = 0;
    
    printf("Please write down a b and c for quadratic");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    
    if (a == 0) {
        return false;
    }else{
        int det = b*b - 4*a*c;
        if (det > 0) {
            int y1 = (-b + det) / (2*a);
            int y2 = (-b - det) / (2*a);
            if(*x1 == y1 && *x2 == y2){
                return true;
            }else{
                return false;
            }
        }else if(det == 0){
            int y1 = (-b) / (2*a);
            if(*x1 == y1 || *x2 == y1){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
