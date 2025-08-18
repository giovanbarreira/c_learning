#include <stdio.h>

float annual_income_first_tax_bracket = 22847.76;
float annual_income_second_tax_bracket = 33919.80;
float annual_income_third_tax_bracket = 45012.60;
float annual_income_fourth_tax_bracket = 55976.16;

float tax_rate_first_bracket = 0.0;
float tax_rate_second_bracket = 7.5;
float tax_rate_third_bracket = 15.0;
float tax_rate_fourth_bracket = 22.5;
float tax_rate_fifth_bracket = 27.5;

float calculate_tax_rate(float annual_income) {
    if (annual_income <= annual_income_first_tax_bracket) {
        return 0.0;
    } else if (annual_income <= annual_income_second_tax_bracket) {
        return 7.5;
    } else if (annual_income <= annual_income_third_tax_bracket) {
        return 15.0;
    } else if (annual_income <= annual_income_fourth_tax_bracket) {
        return 22.5;
    } else {
        return 27.5;
    }
}

void print_tax_rate(float annual_tax_rate) {
    printf("Your tax rate is: %.1f%%\n", annual_tax_rate);
}

float calculate_annual_tax(float annual_income) {
    // First tax bracket
    float remaining_income = annual_income - annual_income_first_tax_bracket;
    float annual_tax = 0.0;

    printf("Remaining income after first tax bracket: R$ %.2f\n", remaining_income);
    printf("Annual tax: R$ %.2f\n", annual_tax);

    // Second tax bracket
    if(remaining_income > 0 && annual_income <= annual_income_second_tax_bracket){
        annual_tax += remaining_income * (tax_rate_second_bracket / 100);
        return annual_tax;
    } else if(remaining_income > 0 && annual_income > annual_income_second_tax_bracket){
        remaining_income = annual_income - annual_income_second_tax_bracket;
        annual_tax += (annual_income_second_tax_bracket - annual_income_first_tax_bracket) * (tax_rate_second_bracket / 100);
    }

    printf("Remaining income after second tax bracket: R$ %.2f\n", remaining_income);
    printf("Annual tax: R$ %.2f\n", annual_tax);

    // Third tax bracket
    if(remaining_income > 0 && annual_income <= annual_income_third_tax_bracket){
        annual_tax += remaining_income * (tax_rate_third_bracket / 100);
        return annual_tax;
    } else if(remaining_income > 0 && annual_income > annual_income_third_tax_bracket){
        remaining_income = annual_income - annual_income_third_tax_bracket;
        annual_tax += (annual_income_third_tax_bracket - annual_income_second_tax_bracket) * (tax_rate_third_bracket / 100);
    }

    printf("Remaining income after third tax bracket: R$ %.2f\n", remaining_income);
    printf("Annual tax: R$ %.2f\n", annual_tax);

    // Fourth tax bracket
    if(remaining_income > 0 && annual_income <= annual_income_fourth_tax_bracket){
        annual_tax += remaining_income * (tax_rate_fourth_bracket / 100);
        return annual_tax;
    } else if(remaining_income > 0 && annual_income > annual_income_fourth_tax_bracket){
        remaining_income = annual_income - annual_income_fourth_tax_bracket;
        annual_tax += (annual_income_fourth_tax_bracket - annual_income_third_tax_bracket) * (tax_rate_fourth_bracket / 100);
    }

    printf("Remaining income after fourth tax bracket: R$ %.2f\n", remaining_income);
    printf("Annual tax: R$ %.2f\n", annual_tax); 

    // Fifth tax bracket
    if(remaining_income > 0){
        annual_tax += remaining_income * (tax_rate_fifth_bracket / 100);        
    }

    printf("Final annual tax: R$ %.2f\n", annual_tax);

    return annual_tax;
}

void print_annual_tax(float annual_tax) {
    printf("Your annual tax is: R$ %.2f\n", annual_tax);
}

int main() {
    float annual_income;
    printf("Enter annual income (R$): ");
    scanf("%f", &annual_income);
    
    float tax_rate = calculate_tax_rate(annual_income);
    print_tax_rate(tax_rate);

    float annual_tax = calculate_annual_tax(annual_income);
    print_annual_tax(annual_tax);
    
    return 0;
}


/*
#include <stdio.h>

int main() {
    double inc;
    printf("Enter inc (R$): ");
    scanf("%lf", &inc);
    double rt = 0.0;
    if (inc <= 22847.76) {
        rt = 0.0;
    } else if (inc <= 33919.80) {
        rt = 7.5;
    } else if (inc <= 45012.60) {
        rt = 15.0;
    } else if (inc <= 55976.16) {
        rt = 22.5;
    } else {
        rt = 27.5;
    }
    printf("Your rt is: %.1f%%\n", rt);
    return 0;
}
*/