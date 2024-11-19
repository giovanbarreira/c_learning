// test_process_message.c
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "db_operations_mock.h"
#include "variables.h"

// Function declaration
void process_message(char *operation);

// Test case for process_message function
void test_process_message(void) {
    // Test update operation
    operation = "u";
    message = "12345678";
    process_message(operation);
    CU_ASSERT_STRING_EQUAL(message, "Mock: Data updated");

    // Test insert operation
    operation = "i"; 
    message = "12345678";
    process_message(operation);
    CU_ASSERT_STRING_EQUAL(message, "Mock: Data inserted");

    // Test invalid operation
    operation = "x"; 
    message = "12345678";
    process_message(operation);
    CU_ASSERT_STRING_EQUAL(message, "Invalid operation");
}

int main() {
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    // Add a suite to the registry
    CU_pSuite pSuite = CU_add_suite("Suite_ProcessMessage", 0, 0);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test_process_message test to the suite
    if (NULL == CU_add_test(pSuite, "test of process_message()", test_process_message)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run all tests using the basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}

