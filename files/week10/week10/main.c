//
//  main.c
//  week10
//
//  Created by Andrei Cristea on 2020. 05. 09..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define BUFFER 10

int main(int argc, const char * argv[]) {
    int f1 = 0;
    int f2 = 1;
    // Writing inside the file fibonnaci sequence
    for(int i = 0; i < 20; i++){
        FILE *myFile = fopen("fibonacci.txt","a");
        int next = 0;
        if (i == 0) {
            fprintf(myFile, "%d\n", f1);
        }else if (i == 1) {
            fprintf(myFile, "%d\n", f2);
        }else{
            next = f1 + f2;
            f1 = f2;
            f2 = next;
            fprintf(myFile, "%d\n", next);
        };
        fclose(myFile);
    }
    // Reading successor
    FILE *readFile = fopen("fibonacci.txt", "r");
    char buffer[BUFFER];
    while (fgets(buffer, BUFFER, readFile)) {
        printf("%d\n", atoi(buffer) + 1);
    }
    return 0;
}
