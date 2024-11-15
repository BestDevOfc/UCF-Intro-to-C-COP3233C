#include <stdio.h>
#include <stdlib.h>
#include<string.h>

/*
Ardian Peach
Kevin Bernichio
Gabe Edwards
Muhammad Ali


*/

struct employee {
    int id;
    char name[50];
    float salary;
    int numberOfDependents;
    //---------------------
    struct employee * next;
    struct employee * below;
};
//----------------------- FUNCTION PROTOTYPES ---------------------------
//0.
int getId ( char * name);
/*
returns the sum of the ascii codes of the letters of name.
*/
//1.
void printEmployee ( struct employee );
/*
prints an employee in the format [id,name,net salary], where:
Net salary = salary*0.91 + (numberOfDependent *0.01*salary)
Examples: [562,AaBc xYz,1253.56] [562,bAac ZyX,6253.06]
*/
//2.
void printAllEmployees ( struct employee * list);
/*
prints all employees in the list. Loops through list and calls
printEmployee for each employee in list
*/
//3.
struct employee * addEmployee ( struct employee * list , struct employee e);
/*
adds e to list.
*/
//4.
int searchEmployee ( struct employee * list , char * name);
/*
returns 1 if name is found in list. Otherwise, it returns 0
*/
//5.
float highestNetSalary ( struct employee * list);
/*
returns the highest net salary.
*/
//----------------------- FUNCTION DEFINITIONS ---------------------------
//0.
int getId ( char * name ){
    int id = 0;
    for( int i = 0; i < strlen(name)-1; i++ ){
        char letter = name[i];
        if( letter >= 'A' && letter <= 'Z' ){
            // already uppercased
            id += letter;
        }
        else if( letter >= 'a' && letter <= 'z' ){
            // add the uppercased letter
            id += letter + ('A' - 'a');
        }
        else if( letter == ' ' ){
            id += 32;
        }
        else{
            // they messed up, name should NOT have any numbers in it:
            printf("[ Error, the name should only have letters and spaces in it! ]");
            exit(-1);
        }
    }
    
    return id;
}
//1.
void printEmployee ( struct employee ){
printf ("COMING UP\n");
}
//2.
void printAllEmployees ( struct employee * list){     

    struct employee* current = list;
    struct employee* prev = NULL;
    
    while( current != NULL ){
        
        printf("[ Name Next ]: %s \n", current->name);
        
        struct employee* belowList = current;
        while( belowList->below != NULL ){
            printf("Below Name: %s\n", belowList->name);
            belowList = belowList->below;
        }
        this works, now do other stuff it asks u to do 


        current = current->next;
    }

}
//3.
struct employee * addEmployee ( struct employee * list , struct employee e){
    // allocate memory bcs if we don't and we return out of func it will point to garbage data.
    struct employee* new_employee = (struct employee*)malloc( sizeof(struct employee) );
    
    // copying data into this ptr
    *new_employee = e;
    
    // have to do it ourselves bcs in main() it was not done.
    new_employee->below = NULL;
    new_employee->next = NULL;


    // first element, add it now
    if( list == NULL ){
        return new_employee;
    }

    struct employee* current = list;
    struct employee* prev = NULL;
    
    while( current != NULL ){
        if( current->id == e.id ){
            // add it to below
            struct employee* belowList = current;
            while( belowList->below != NULL ){
                belowList = belowList->below;
            }
            belowList->below = new_employee;
            return list;

        }

        prev = current;
        current = current->next;
    }

    // no employee with same ID
    prev->next = new_employee;
    return list;
}
//4.
int searchEmployee ( struct employee * list , char * name){
printf ("COMING UP\n");
return 0;
}
//5.
float highestNetSalary ( struct employee * list){
printf ("COMING UP\n");
return 0.0;
}

//DO NOT CHANGE ANYTHING IN main
int main() {
    struct employee * company = NULL , tempEmployee;
    int tempInt = 0;
    char tempName [50] = "Allal Kamch" ;
    char dummy;
    


    printf ("Enter 1 to add a new employee, 0 to stop: ");
    scanf ("%d", &tempInt);
    
    while ( tempInt == 1 ){
        printf("Enter Full Name: ");
        scanf("%c", &dummy);

        fgets(tempEmployee.name, 50, stdin);
        tempEmployee.id = getId ( tempEmployee.name );

        printf ("Enter salary-numberOfDependents: ");
        scanf ("%f-%d", &tempEmployee.salary, &tempEmployee.numberOfDependents);
        company = addEmployee ( company , tempEmployee );

        printf ("Enter 1 to add a new employee, 0 to stop: ");
        scanf ("%d", &tempInt);
    }
    printAllEmployees ( company ) ;
    printf ("Highest Net Salary = %.2f\n", highestNetSalary(company) );
    tempInt = searchEmployee ( company , tempName) ;
    if ( tempInt == 1 ) printf ("%s is found!\n", tempName);
    else printf ("%s is NOT found!\n", tempName);
    return 0;
}
