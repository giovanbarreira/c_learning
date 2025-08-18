#include <stdio.h>

int main() {
	float number;

	puts("Type a number:");
	scanf("%f",&number);

	if(number > 0) puts("Positive.");
    else if(number == 0) puts("Zero.");
    else puts("Negative."); 

	return 0;
}