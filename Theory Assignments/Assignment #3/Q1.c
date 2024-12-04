// Write a program that contains a structure named Employee which contains the following
// data members:
// ● employeeCode
// ● employeeName
// ● dateOfJoining
// Perform the following operations:
// 1. Define a function that assigns user-defined values to these variables. 2. Create an array of 4 Employee structs and initialize them with user-defined values. 3. Define a function that asks the user to enter the current date, calculates the tenure of each
// employee, and checks if the tenure is more than three years. Display the details of
// employees with tenure of more than three years and the count of such employees.

#include <stdio.h>

struct Employee
    {
        int employeeCode;
        char employeeName[50];
        char dateOfJoining[50];
    };

void assignVal(struct Employee *emp){
    printf("Enter the employee code: ");
    scanf("%d", &emp->employeeCode);
    printf("Enter the employee name: ");
    scanf("%s", emp->employeeName);
    printf("Enter the date of joining: ");
    scanf("%s", emp->dateOfJoining);
}

int jobDuration(struct Employee *emp, char current_date[50]){
    static count = 0;
    
    int day, month, year;
    int join_day, join_month, join_year;
    
    sscanf(current_date, "%d-%d-%d", &day, &month, &year);
    sscanf(emp->dateOfJoining, "%d-%d-%d", &join_day, &join_month, &join_year);
    int duration = (year - join_year)*365 + (month - join_month)*30 + (day - join_day);
    if (duration > 1095){
        printf("Employee: %s with employee code %d has been working for more than 3 years\n", emp->employeeName, emp->employeeCode);
        count += 1;
    }
    return count;
}

int main(){
    int emp_count;
    char current_date[50];
    struct Employee emp1;
    
    struct Employee array[4];
    for(int i=0; i<2; i++){
        assignVal(&array[i]);
        
    }
    printf("Enter the current date: ");
    scanf("%s", current_date);
    for(int i = 0; i<2; i++){
        emp_count = jobDuration(&array[i], current_date);
    }
    printf("The number of employees working for more than 3 years are: %d\n", emp_count);
    
}