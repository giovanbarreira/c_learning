#include <stdio.h> 
#include "db_operations.h" 
#include "variables.h"

void db_update() { 
	printf("Data updated: %s\n", message); 
} 

void db_insert() { 
	printf("Data inserted: %s\n", message);
}
