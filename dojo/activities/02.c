#include <stdio.h>
#include <string.h>

int main() {
	char name[50];
	int age;

	puts("Enter a name:");
	fgets(name, sizeof(name), stdin);
	name[strcspn(name, "\n")] = '\0';

	puts("Enter an age:");
	scanf("%d", &age);

	printf("%s is %d years old.\n\r", name, age);

	return 0;
}
