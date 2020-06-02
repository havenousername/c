//
//  main.c
//  exam
//
//  Created by Andrei Cristea on 2020. 06. 02..
//  Copyright © 2020. Andrei Cristea. All rights reserved.
//

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "number_of_employees.h"
#include "find.h"
#include "one_day_in_company.h"

#define SIZE 5

int main(int argc, const char * argv[]) {
    // employees 
    employee Alex = {"Alex",100, 0};
    employee Roza = {"Roza",105, 365};
    employee Alexia = {"Alexia",300, 3658};
    employee Bob = {"Bob",115, 1095};
    employee Mahmud = {"Mahmud",150, 2000};
    // allocationg memory for array
    employee *Employees = (employee*)malloc(sizeof(employee)*SIZE);
    // array which I will not use after
    employee Employee[] = {Alex, Roza, Alexia, Bob, Mahmud};
    // initializing array on the heap
    for (int i = 0; i < SIZE; i++) {
        Employees[i] = Employee[i];
    }
    int size = SIZE;
    
    // 
    int number_of_interns = number_of_employees_at(Employees,  size,  Intern);
    int number_of_software_devs = number_of_employees_at(Employees,  size, Software_Developer);
    // Simulates 10000 days passed
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < SIZE ; j++ ) {
            Employees[j] = one_day_in_company(Employees[j]);
        }
    }
    // number_of_employees.h
    int number_of_seniors = number_of_employees_at(Employees,  size,  Senior_Developer);
    printf("%d %d %d\n", number_of_seniors, number_of_interns, number_of_software_devs);
    // find.h - find employee
    employee *found = find_employee(Employees, size, "Alex");
    printf("%p\n", found);
    
    free(Employees);
    return 0;
}
