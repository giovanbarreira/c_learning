#include <stdio.h>
#include <string.h>

// Function to read and validate the name
void validateName(char* name) {
    do {
        printf("Digite o nome (maior que 3 caracteres): ");
        scanf("%s", name);

        // Use fgets to read the name with spaces 
        // fgets(name, 50, stdin); 
        // Remove the newline character at the end of the string
        // name[strcspn(name, "\n")] = '\0';

        if (strlen(name) <= 3) {
            printf("Erro: o nome deve ter mais de 3 caracteres.\n");
        }
    } while (strlen(name) <= 3);
}

// Function to read and validate the age
int validateAge() {
    int age;
    do {
        printf("Digite a idade (entre 0 e 150): ");
        scanf("%d", &age);
        if (age < 0 || age > 150) {
            printf("Erro: a idade deve estar entre 0 e 150.\n");
        }
    } while (age < 0 || age > 150);
    return age;
}

// Function to read and validate the salary
float validateSalary() {
    float salary;
    do {
        printf("Digite o salário (maior que zero): ");
        scanf("%f", &salary);
        if (salary <= 0) {
            printf("Erro: o salário deve ser maior que zero.\n");
        }
    } while (salary <= 0);
    return salary;
}

// Function to read and validate the gender
char validateGender() {
    char gender;
    do {
        printf("Digite o sexo (f ou m): ");
        scanf(" %c", &gender);
        if (gender != 'f' && gender != 'm') {
            printf("Erro: o sexo deve ser 'f' ou 'm'.\n");
        }
    } while (gender != 'f' && gender != 'm');
    return gender;
}

// Function to read and validate the marital status
char validateMaritalStatus() {
    char maritalStatus;
    do {
        printf("Digite o estado civil (s, c, v, d): ");
        scanf(" %c", &maritalStatus);
        if (maritalStatus != 's' && maritalStatus != 'c' && maritalStatus != 'v' && maritalStatus != 'd') {
            printf("Erro: o estado civil deve ser 's', 'c', 'v' ou 'd'.\n");
        }
    } while (maritalStatus != 's' && maritalStatus != 'c' && maritalStatus != 'v' && maritalStatus != 'd');
    return maritalStatus;
}

int main() {
    char name[50];
    int age;
    float salary;
    char gender;
    char maritalStatus;

    validateName(name);
    age = validateAge();
    salary = validateSalary();
    gender = validateGender();
    maritalStatus = validateMaritalStatus();

    printf("\nInformações Validadas:\n");
    printf("Nome: %s\n", name);
    printf("Idade: %d\n", age);
    printf("Salário: %.2f\n", salary);
    printf("Sexo: %c\n", gender);
    printf("Estado Civil: %c\n", maritalStatus);

    return 0;
}