//
//  main.c
//  main
//
//  Created by Andrei Cristea on 2020. 03. 27..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <stdio.h>

void update(int *a, int *b){
    int a1 = *a;
    int *pa1 = &a1;
    *a = *a + *b;
    if((*pa1 - *b) < 0){
        *b = -(*pa1 -*b);
    }else{
        *b = *pa1 - *b;
    }

}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", *pa, *pb);

    return 0;
}
