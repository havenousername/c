//
//  main.c
//  binary_search
//
//  Created by Andrei Cristea on 2020. 06. 01..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define SIZE 20

int binary_search(int arr[], int l, int r,int x){
    while (l <= r) {
        int m = l + (r - l) / 2;
        
        // Check if it is in the center
        if (arr[m] == x) {
            return m;
        }
        
        // if x is greater ignore left side
        if (arr[m] < x) {
            l = m +1;
        }
        
        // if opposite ingnore right side
        else {
            r = m-1;
        }
    }
    return -1;
};

int main(int argc, const char * argv[]) {
//    int arr[] = {-2, 0, 5, 7, 11, 15, 23};
    int arr[SIZE];
    printf("Enter array:\n");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    int j = (sizeof(arr)/4);
//    int a = (sizeof(arr)/4);
    int index = 15;
    printf("Enter searched value:\n");
    scanf("%d", &index);
//    int out = -1;
//    int i = (sizeof(arr)/4);
//    if (sizeof(arr)/4 > 0) {
//        while (i != 0) {
//            i /=2;
//            if (index == arr[j]){
//                out = j;
//                break;
//            }
//            else if(index < arr[j]) {
//                j = abs((j-1)-(i/2));
//            }else if(index > arr[j]){
//
//                if (i < 3) {
//                    j+=i;
//                }else{
//                    j +=(i/2);
//                }
//            }
//        }
//        if (out > -1) {
//            printf("true : %d\n", out);
//        }else{
//            printf("false : %d\n ", out);
//        }
//    }else{
//        printf("No elements found\n");
//    }
    int result = binary_search(arr, 0, j-1, index);
    if (result == -1) {
        printf("No element in the array\n");
    }else{
        printf("Element has index: %d\n", result);
    }
    return 0;
}
