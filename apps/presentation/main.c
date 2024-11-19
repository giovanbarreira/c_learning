#include <stdio.h>
#include <stdlib.h>
#include "db_operations.h"
#include "variables.h"

void process_message(char *operation) { 
	if (operation[0] == 'u') { 
		db_update(); 
	} else if (operation[0] == 'i') { 
		db_insert(); 
	} else { 
		puts("Invalid operation"); 
	} 
} 

int main(int argc, char *argv[]) { 
	if (argc != 4) puts("Did you forget something?");
	message = argv[1]; 
	priority = atoi(argv[2]); 
	operation = argv[3]; 
	 
	process_message(operation); 

	return 0; 
}
