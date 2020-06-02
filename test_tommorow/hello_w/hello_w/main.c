//
//  main.c
//  hello_w
//
//  Created by Andrei Cristea on 2020. 06. 02..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>



int *divisible(int n, int count){
//    int *count = (int*)malloc(sizeof(count));
    int *arr = (int*)malloc(sizeof(arr)*100);
    int j = 0;
    for (int i = 1; i <= n; i++) {
        if (i % count == 0) {
            *(arr+j) = i;
            j++;
        }
    }
    *(arr+j) = -1;
    return arr;
};

int main(int argc, const char * argv[]) {
    int n = 50;
    int count = 0;
    int *res = divisible(n, ++count);
    
    int i = 0;
    while (*(res+i) != -1 ) {
        printf("%d\n", *(res+i));
        i++;
    }
    free(divisible(n, count));
    printf("\n");
    i = 0;
    int *res2 = divisible(n, ++count);
    while (*(res2+i) != -1 ) {
        printf("%d\n", *(res2+i));
        i++;
    }
    free(divisible(n, count));
    i = 0;
    int *res3 = divisible(n, ++count);
    while (*(res3+i) != -1 ) {
        printf("%d\n", *(res3+i));
        i++;
    }
    return 0;
}
