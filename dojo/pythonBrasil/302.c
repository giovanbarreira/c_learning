#include <stdio.h>
#include <string.h>

// Define a struct to hold user credentials
struct User {
    char username[50];
    char password[50];
};

int main() {
    struct User user;

    do {
        printf("Digite o nome de usuário: ");
        scanf("%s", user.username);

        printf("Digite a senha: ");
        scanf("%s", user.password);

        // Check if the password is the same as the username
        if (strcmp(user.username, user.password) == 0) {
            printf("Erro: a senha não pode ser igual ao nome de usuário. Tente novamente.\n");
        } else {
            printf("Usuário e senha válidos.\n");
        }
    } while (strcmp(user.username, user.password) == 0);

    return 0;
}