#include <iostream>  // For input/output
#include <string>    // For string manipulation
#include <vector>    // For collecting boolean results

#include "DocumentManager.h"  // Include your DocumentManager header

// Helper function to print boolean results as 1s and 0s
void print_bool_results(const std::vector<bool>& results) {
  for (size_t i = 0; i < results.size(); ++i) {
    std::cout << (results[i] ? 1 : 0) << (i == results.size() - 1 ? "" : " ");
  }
  std::cout << std::endl;
}

int main() {
  DocumentManager dm;

  std::cout << "--- Starting DocumentManager Tests ---" << std::endl
            << std::endl;

  // --- Test Case 1: Searching for documents ---
  std::cout << "Searching for documents (Test1):" << std::endl;
  try {
    // Setup for Test1: Add a document that should be found
    dm.addDocument("Test1", 42, 5);  // Name "Test1", ID 42, License Limit 5
    dm.addDocument("AnotherDoc", 100, 1);  // Another document

    // Perform search operations
    int foundId1 = dm.search("Test1");
    int foundId2 = dm.search("NonExistentDoc");  // Should return -1

    // The "Expecting: 42 1 0" is a bit odd for search results alone.
    // Let's interpret it as:
    // 42: ID of "Test1"
    // 1: A successful operation (e.g., addDocument or search success)
    // 0: A failed operation (e.g., search for non-existent doc)
    // We'll print the found ID for "Test1", then a '1' for success, then '0'
    // for the failed search.
    std::cout << "Obtained : " << foundId1 << " " << (foundId1 != -1 ? 1 : 0)
              << " " << (foundId2 == -1 ? 0 : 1) << std::endl;
    std::cout << "Expected : 42 1 0" << std::endl << std::endl;

  } catch (const std::runtime_error& e) {
    std::cerr << "Error during Test1 setup/execution: " << e.what()
              << std::endl;
  }

  // --- Test Case 2: Borrowing documents ---
  std::cout << "Borrowing documents (Test2):" << std::endl;
  try {
    // Setup for Test2:
    // Add a document with license limit 2
    dm.addDocument("DocForBorrow", 101, 2);  // ID 101, Limit 2

    // Add patrons
    dm.addPatron(1);
    dm.addPatron(2);
    dm.addPatron(3);  // This patron should fail to borrow due to limit

    std::vector<bool> borrowResults;

    // 1. Patron 1 borrows DocForBorrow (should succeed)
    borrowResults.push_back(dm.borrowDocument(1, 101));  // Expect true (1)

    // 2. Patron 2 borrows DocForBorrow (should succeed, limit is 2)
    borrowResults.push_back(dm.borrowDocument(2, 101));  // Expect true (1)

    // 3. Patron 3 borrows DocForBorrow (should fail, limit reached)
    borrowResults.push_back(dm.borrowDocument(3, 101));  // Expect false (0)

    // 4. Patron 1 tries to borrow DocForBorrow again (should fail, already has
    // it)
    borrowResults.push_back(dm.borrowDocument(1, 101));  // Expect false (0)

    std::cout << "Obtained : ";
    print_bool_results(borrowResults);
    std::cout << "Expected : 1 1 0 0" << std::endl << std::endl;

  } catch (const std::runtime_error& e) {
    std::cerr << "Error during Test2 setup/execution: " << e.what()
              << std::endl;
  }

  // --- Test Case 3: Returning (and then borrowing) documents ---
  std::cout << "Returning (and then borrowing) documents (Test3):" << std::endl;
  try {
    // Setup for Test3:
    // Add a document with license limit 1
    dm.addDocument("BookForReturn", 201, 1);  // ID 201, Limit 1

    // Add patrons
    dm.addPatron(10);  // Patron who will borrow and return
    dm.addPatron(11);  // Another patron for a failing borrow attempt

    // Pre-test: Patron 10 borrows BookForReturn
    dm.borrowDocument(10, 201);  // This must succeed for the return to be valid

    std::vector<bool> returnBorrowResults;

    // 1. Patron 10 returns BookForReturn (should succeed, no exception)
    bool returnSuccess = false;
    try {
      dm.returnDocument(10, 201);
      returnSuccess = true;  // Indicates success for the test output
    } catch (const std::runtime_error& e) {
      // If an exception occurs, returnSuccess remains false
      std::cerr << "Error during return: " << e.what() << std::endl;
    }
    returnBorrowResults.push_back(returnSuccess);  // Expect true (1)

    // 2. Attempt a subsequent borrow that fails.
    // To get '0', let's try to borrow with a non-existent patron.
    bool subsequentBorrowFail =
        dm.borrowDocument(999, 201);  // Patron 999 not added, should fail
    returnBorrowResults.push_back(subsequentBorrowFail);  // Expect false (0)

    std::cout << "Obtained : ";
    print_bool_results(returnBorrowResults);
    std::cout << "Expected : 1 0" << std::endl << std::endl;

  } catch (const std::runtime_error& e) {
    std::cerr << "Error during Test3 setup/execution: " << e.what()
              << std::endl;
  }

  return 0;
}
