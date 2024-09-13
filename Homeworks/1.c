// unit1.hw
// Muhammad Ali

#include <stdio.h>
#include <stdlib.h>

// since these are constants I'll just throw em up here 
const float CREDIT_HR_RATE = 120.25;
const float HEALTH_ID_FEE = 35.00;

int main(){

    // a structure would make more sense, but he'll teach it later I bet.
    float discount = 1.0;
    int student_id = 0;
    float student_gpa = 0.0;
    printf("Enter the Student’s Id: ");
    scanf("%d", &student_id);

    
    int crn_first = 0;
    int credit_hrs_first = 0;
    printf("Enter crn/credit hours for the first class : ");
    scanf("%d/%d", &crn_first, &credit_hrs_first);
    

    int crn_second = 0;
    int credit_hrs_second = 0;
    printf("Enter crn/credit hours for the second class: ");
    scanf("%d/%d", &crn_second, &credit_hrs_second);
    
    // calculate totals of each class
    float first_total = credit_hrs_first * CREDIT_HR_RATE;
    float second_total = credit_hrs_second * CREDIT_HR_RATE;
    
    printf("\nEnter the gpa of Student %d: ", student_id);
    scanf("%f", &student_gpa);

    // if discount = 1 nothing will change, which is nice.
    if ( student_gpa > 2.5 ){
        discount = 0.75; // 25% discount is 75% of the total price so it's 0.75
        printf("(25%% discount is applicable)\n");
    }
    else{
        printf("(25%% discount is not applicable)\n");
    }

    printf("\nThank you!\n");
    printf("Here IS THE FEE INVOICE...\n\n\n");

    
    // remember, the health fee does NOT get discounted from the total !
    float total_cost = ( ( first_total + second_total ) * discount ) + HEALTH_ID_FEE;

    // using multi-line C print statement, instead of individual print statements
    printf("SIMPLE COLLEGE\n"
        "ORLANDO FL 10101\n"
        "*************************\n"

        "Fee Invoice Prepared for:\n"
        "[Student: %d]\n"

        "1 Credit Hour = $%.2f\n"

        "CRN\t\tCREDIT HOURS\n"
        "%d\t\t%d\t\t$%.2f\n"
        "%d\t\t%d\t\t$%.2f\n"

        "Health & id fees	$%.2f\n"

        "----------------------------------------\n"
        "Total Payments\t$%.2f\n\n\n",
        student_id, CREDIT_HR_RATE, crn_first, credit_hrs_first, first_total, crn_second,
        credit_hrs_second, second_total, HEALTH_ID_FEE, total_cost);


    return 0;
}