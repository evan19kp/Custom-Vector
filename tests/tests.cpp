#include <iostream>
#include <stdexcept>
#include "Vector.hpp"

int main() {
    MyVector<int> vec;

    // Test 1: Default constructor, empty vector
    std::cout << "Test 1: " << (vec.size() == 0 && vec.capacity() == vec.DEFAULT_CAPACITY ? "Passed" : "Failed") << std::endl;

    // Test 2: Empty vector check
    std::cout << "Test 2: " << (vec.empty() ? "Passed" : "Failed") << std::endl;

    // Test 3: push_back on empty vector
    vec.push_back(5);
    std::cout << "Test 3: " << (vec.size() == 1 && vec[0] == 5 ? "Passed" : "Failed") << std::endl;

    // Test 4: push_back multiple elements
    vec.push_back(10);
    vec.push_back(15);
    vec.push_back(20);
    std::cout << "Test 4: " << (vec.size() == 4 && vec[3] == 20 ? "Passed" : "Failed") << std::endl;

    // Test 5: Reserve more capacity
    vec.reserve(100);
    std::cout << "Test 5: " << (vec.capacity() == 100 ? "Passed" : "Failed") << std::endl;

    // Test 6: Access elements with at()
    std::cout << "Test 6: " << (vec.at(2) == 15 ? "Passed" : "Failed") << std::endl;

    // Test 7: Out-of-bounds at() exception
    bool exceptionThrown = false;
    try {
        vec.at(10);
    } catch (const std::range_error&) {
        exceptionThrown = true;
    }
    std::cout << "Test 7: " << (exceptionThrown ? "Passed" : "Failed") << std::endl;

    // Test 8: Set element at specific index
    vec.set(2, 30);
    std::cout << "Test 8: " << (vec[2] == 30 ? "Passed" : "Failed") << std::endl;

    // Test 9: pop_back on non-empty vector
    int last = vec.pop_back();
    std::cout << "Test 9: " << (last == 20 && vec.size() == 3 ? "Passed" : "Failed") << std::endl;

    // Test 10: pop_back until empty
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();
    std::cout << "Test 10: " << (vec.size() == 0 && vec.empty() ? "Passed" : "Failed") << std::endl;

    // Test 11: pop_back on empty vector exception
    exceptionThrown = false;
    try {
        vec.pop_back();
    } catch (const std::range_error&) {
        exceptionThrown = true;
    }
    std::cout << "Test 11: " << (exceptionThrown ? "Passed" : "Failed") << std::endl;

    // Test 12: Insert element at beginning
    vec.push_back(10);
    vec.push_back(20);
    vec.insert(0, 5);
    std::cout << "Test 12: " << (vec[0] == 5 && vec.size() == 3 ? "Passed" : "Failed") << std::endl;

    // Test 13: Insert in middle
    vec.insert(1, 15);
    std::cout << "Test 13: " << (vec[1] == 15 && vec.size() == 4 ? "Passed" : "Failed") << std::endl;

    // Test 14: Insert at end
    vec.insert(4, 25);
    std::cout << "Test 14: " << (vec[4] == 25 && vec.size() == 5 ? "Passed" : "Failed") << std::endl;

    // Test 15: erase element from beginning
    vec.erase(0);
    std::cout << "Test 15: " << (vec[0] == 15 && vec.size() == 4 ? "Passed" : "Failed") << std::endl;

    // Test 16: erase element from middle
    vec.erase(1);
    std::cout << "Test 16: " << (vec[1] == 20 && vec.size() == 3 ? "Passed" : "Failed") << std::endl;

    // Test 17: erase element from end
    vec.erase(vec.size() - 1);
    std::cout << "Test 17: " << (vec.size() == 2 ? "Passed" : "Failed") << std::endl;

    // Test 18: clear vector
    vec.clear();
    std::cout << "Test 18: " << (vec.size() == 0 && vec.empty() ? "Passed" : "Failed") << std::endl;

    // Test 19: insert elements to reach minimum capacity
    for (int i = 0; i < vec.MINIMUM_CAPACITY; ++i) {
        vec.push_back(i);
    }
    std::cout << "Test 19: " << (vec.size() == vec.MINIMUM_CAPACITY ? "Passed" : "Failed") << std::endl;

    // Test 20-30: insert and check elements in larger vector
    bool allCorrect = true;
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i * 2);
    }
    for (int i = 0; i < 10; ++i) {
        if (vec[vec.size() - 10 + i] != i * 2) {
            allCorrect = false;
            break;
        }
    }
    std::cout << "Tests 21-30: " << (allCorrect ? "Passed" : "Failed") << std::endl;

    // Test 31: Assignment operator
    MyVector<int> vec2;
    vec2 = vec;
    std::cout << "Test 31: " << (vec2.size() == vec.size() ? "Passed" : "Failed") << std::endl;

    // Test 32: Copy constructor
    MyVector<int> vec3(vec);
    std::cout << "Test 32: " << (vec3.size() == vec.size() ? "Passed" : "Failed") << std::endl;

    // Test 33-40: Clear, push, and check elements
    vec.clear();
    allCorrect = true;
    for (int i = 0; i < 8; ++i) vec.push_back(i);
    for (int i = 0; i < 8; ++i) {
        if (vec[i] != i) {
            allCorrect = false;
            break;
        }
    }
    std::cout << "Tests 33-40: " << (allCorrect ? "Passed" : "Failed") << std::endl;

    // Test 41: begin iterator
    std::cout << "Test 41: " << (*vec.begin() == 0 ? "Passed" : "Failed") << std::endl;

    // Test 42: end iterator
    std::cout << "Test 42: " << (*(vec.end() - 1) == 7 ? "Passed" : "Failed") << std::endl;

    // Test 43: begin and end difference equals size
    std::cout << "Test 43: " << ((vec.end() - vec.begin()) == vec.size() ? "Passed" : "Failed") << std::endl;

    std::cout << "All tests completed." << std::endl;
    return 0;
}
