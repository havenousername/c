//
//  main.c
//  matrixes
//
//  Created by Andrei Cristea on 2020. 04. 10..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int** multiply_matrixes(int *matrix_one, int *matrix_two, int* m3){
    // decrarinf the multiplied variable
    int **matrix;
//    allocating memory in the dymamic memory to access it outside of the function
    matrix = malloc(sizeof(int*)*3);
//    because its two dimentional we need a for loop for allocating mamory for all indexes
    for (int i = 0; i < 3; i++) {
        matrix[i] = malloc(sizeof(int*)*3);
    }
//    indexes initicalization
    int indexOne = 0, indexTwo = 0;
    
    
//    for loop
    for (int i = 0; i < 3;i++ ) {
        if (i == 1) {
//          if first column is ready we change firsst matrixes index to 4
            indexOne = 3;
        }
        if (i == 2) {
//          if second column is ready we change firsst matrixes index to 4
            indexOne = 6;
        }
        
        for (int j = 0; j < 3; j++) {
//            asigning pointer values to the matrix
            matrix[i][j] = (*(indexOne + matrix_one)) * (*(indexTwo + matrix_two + j)) + (*(indexOne + matrix_one + 1)) * (*(indexTwo + matrix_two + j + 3)) + (*(indexOne + matrix_one + 2)) * (*(indexTwo + matrix_two + j + 6));
        }
    }
    
//    checker for loop inside the function
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0 ; j < 3; j++) {
//            printf("%d ", multiply[i][j]);
//        }
//        printf("\n");
//    }
    
//    int* pointer_multiply = &multiply[0][0];
    
//    matrix return
    return matrix;
}



int main(int argc, const char * argv[]) {
    int m1[3][3] = {
        {1,1,1},
        {2,2,2},
        {3,3,3}
    };
    int m2[3][3] = {
        {3,2,1},
        {3,2,1},
        {3,2,1}
    };
    int m3[3][3];
//    int* m1_pointer = &m1[0][0];
//    int* m2_pointer = &m2[0][0];
    
    printf("Please enter first matrix(3*3)\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
//            m1[i][j] = i+j;
//            m2[i][j] = i+j+10;
            scanf("%d", &m1[i][j]);
//            scanf("%d", &m2[i][j]);
        }
    }
    
    printf("Please enter second matrix(3*3)\n");
    for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++){
    //            m1[i][j] = i+j;
    //            m2[i][j] = i+j+10;
//                scanf("%d", &m1[i][j]);
                scanf("%d", &m2[i][j]);
            }
        }
//    int* pointer_first_arr = &m1[0][0];
    int **pointer_multiply = multiply_matrixes(&m1[0][0], &m2[0][0], &m3[0][0]);
    
    printf("Multiplied matrixes\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            printf("%d ", pointer_multiply[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < 3; i++) {
        free(pointer_multiply[i]);
    }
    free(pointer_multiply);

    return 0;
}

// Note !!!
// In internet I found out that there is an other solution using structs!
