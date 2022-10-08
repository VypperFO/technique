#include <stdio.h>
#include <string.h>

struct Person {
    char name[50];
    int citNo;
    float salary;
} person1;

int main(){
    person1.salary = 20;
    printf("Salary: %.2f", person1.salary);

    return 0;
}