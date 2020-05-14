//
//  main.c
//  prep
//
//  Created by Andrei Cristea on 2020. 05. 11..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMBER_ONE 220
#define NUMBER_TWO 284

// Collatz sequence
int collatz_length(int n){
    int length = 1;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        }else{
            n = 3*n+1;
        }
        length++;
    }
    return length;
}

// divisors_sequence
int *divisors(int n){
    int *seq = malloc(sizeof(int)*100);
    int i = 1;
    int j = 0;
    while(i != n){
        if (n % i == 0) {
            int *ptr = (seq + j);
            *ptr = i;
            j++;
        }
        i++;
    }
    return seq;
};

int size_divisors(int n){
    int i = 1;
    int j = 0;
    while(i != n){
        if (n % i == 0) {
            j++;
        }
        i++;
    }
    return j;
};
int sumArray(int* arr, int size){
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    return sum;
};

bool areEqual(int* arr1, int size1 ,int* arr2,int size2){
    bool are_equal = false;
    if (sumArray(arr1, size1) == NUMBER_TWO && sumArray(arr2, size2) == NUMBER_ONE) {
        are_equal = true;
    }
    return are_equal;
};

int reverseNumber(int n){
    int reversed = 0;
    while ((n / 10) != 0) {
        reversed =(n % 10)+(reversed*10);
        n /= 10;
    }
    reversed =(n % 10)+(reversed*10);
    return reversed;
};

bool isPalidrome(int n){
    if (reverseNumber(n) == n) {
        return true;
    }
    return false;
}

void draw_piramid(int n){
    int mid = (n / 2);
    char **print = malloc(sizeof(char)*n*(n+1));
    
//    for (int i = 0; i < n; i++) {
//        int j = 0;
//        for (j =  0; j < n; j++) {
//            if (j != mid) {
//                *((*print + i) + j) = ' ';
//            }else{
//                **(print + i + j) = '#';
//            }
//        }
//        **(print + i + j + 1) = '\n';
//    }
//    for (int i = 0; i < n ; i++) {
//        int j = 0;
//        for ( j = 0; j < n; j++) {
//            printf("%c", **(print+i+j));
//        }
//         printf("%c",**(print+i+j+1));
//    }

};

int main(int argc, const char * argv[]) {
//    printf("%d", collatz_length(3));
//    int *arr = divisors(NUMBER_ONE);
//    int size = size_divisors(NUMBER_ONE);
//    int *arr2 = divisors(NUMBER_TWO);
//    int size2 = size_divisors(NUMBER_TWO);
//    printf("%d", areEqual(arr, size, arr2, size2));
    
//    printf("%d", isPalidrome(75357));
//
//    int n = 0;
//    scanf("%d", &n);
//    draw_piramid(n);
    return 0;
}
