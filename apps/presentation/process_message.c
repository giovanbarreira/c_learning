#include <string.h>
#include "db_operations_mock.h"
#include "variables.h"

void process_message(char *operation) {
    if (strcmp(operation, "u") == 0) {
        db_update();
        message = "Mock: Data updated";
    } else if (strcmp(operation, "i") == 0) {
        db_insert();
        message = "Mock: Data inserted";
    } else {
        message = "Invalid operation";
    }
}
