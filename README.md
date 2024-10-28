# MyVector: Custom Dynamic Array Implementation in C++

## Overview
`MyVector` is a custom implementation of a dynamic array in C++, inspired by the standard library's `std::vector` class. This implementation provides essential functionalities for dynamic array handling, such as automatic resizing, random access, and memory management. The project is designed to showcase understanding of C++ memory management, object-oriented programming principles, and efficient data structure implementation.

## Key Features
- **Dynamic Resizing**: Automatically adjusts the internal storage size when the array reaches capacity.
- **Customizable Capacity**: Start with a default capacity, and the vector will grow or shrink as elements are added or removed.
- **Element Access**: Access elements by index with bounds checking.
- **Memory Management**: Efficiently handles dynamic memory allocation and deallocation.
- **Exception Handling**: Handles out-of-bounds access and insufficient capacity with informative error messages.

## Implementation Details
### Header File Structure
The `MyVector` class template is defined in `MyVector.hpp`, supporting various data types (`int`, `double`, `std::string`, etc.).

### Public Member Functions
- **Constructors and Destructor**: Includes a default constructor, copy constructor, and destructor for memory cleanup.
- **Assignment Operator**: Allows assignment from another `MyVector` instance.
- **Capacity Management**:
  - `reserve(size_t capacity)`: Reserves additional capacity if needed.
  - `clear()`: Clears the vector while optionally resetting the capacity.
- **Element Access and Manipulation**:
  - `push_back(const T& element)`: Adds an element to the end, resizing if necessary.
  - `pop_back()`: Removes the last element, shrinking capacity as needed.
  - `insert(size_t index, const T& element)`: Inserts an element at a specific index.
  - `erase(size_t index)`: Removes an element at a specified index.
  - `at(size_t index)`: Provides bounds-checked access to elements.
- **Iterators**:
  - `begin()`: Returns a pointer to the first element.
  - `end()`: Returns a pointer just past the last element.

### Private Helper Functions
- **changeCapacity(size_t newCapacity)**: Adjusts the vector's internal storage size while preserving existing elements.

## Error Handling
`MyVector` handles invalid operations (e.g., accessing an out-of-bounds index) by throwing a `std::range_error` exception. Descriptive error messages are provided to assist in debugging.

## Example Usage

```cpp
#include <iostream>
#include "MyVector.hpp"

int main() {
    MyVector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    std::cout << "Vector elements: ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec.at(i) << " ";
    }
    std::cout << "\n";

    vec.pop_back();
    std::cout << "After pop_back, last element: " << vec.at(vec.size() - 1) << "\n";

    return 0;
}
```

Output:
```
Vector elements: 10 20 30 
After pop_back, last element: 20
```
3. **Run**:
   ```bash
   ./myvector
   ```
