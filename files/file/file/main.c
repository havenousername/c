//
//  main.c
//  file
//
//  Created by Andrei Cristea on 2020. 05. 09..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <stdio.h>

#define BUFFER 50

int main(int argc, const char * argv[]) {
    FILE *myFile = fopen("file.txt", "a");
    
    if (myFile == NULL) {
        printf("Error when I try to create a file\n");
    }
    int i = BUFFER;
    // Writing to a file
    fprintf(myFile, "I dislike this file name %d\n", i);
    fclose(myFile);
    
    // Reading from a file
    FILE *readFile = fopen("file.txt", "r");
    char buffer[BUFFER];
    while (fgets(buffer,BUFFER,readFile) != NULL) {
        printf("%s", buffer);
    }
    fclose(readFile);
    return 0;
}
