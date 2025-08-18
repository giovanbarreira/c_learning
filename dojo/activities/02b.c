#include <stdio.h>
#include <string.h>

struct Person {
	char name[50];
	int age;
};

int main() {
	struct Person person;

	puts("Enter a name:");
	fgets(person.name, sizeof(person.name),stdin);
	person.name[strcspn(person.name, "\n")] = '\0';

	puts("Enter an age:");
	scanf("%d", &person.age);

	printf("%s is %d years old.", person.name, person.age);

	return 0;	
}
