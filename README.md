# Custom Vector Implementation in C++

This repository contains a custom implementation of a dynamic array (similar to `std::vector`) in C++.

## Description

The `Vector` class provided in this repository offers a dynamic array that automatically adjusts its size as elements are added or removed. It includes essential functionalities such as insertion, deletion, accessing elements by index, and iterators.

## Features

- Dynamic resizing for efficient memory management.
- Support for insertion, deletion, and access operations.
- Iterators for traversing the elements of the vector.

## Usage

To utilize the `Vector` class in your C++ projects, follow these steps:

1. Clone or download this repository.
2. Include the `Vector.h` header file in your C++ program.
3. Instantiate objects of type `Vector<T>` to work with different data types.
4. Utilize the provided methods like `push_back`, `pop_back`, `insert`, `erase`, etc., as needed.

```cpp
#include "Vector.h"

int main() {
    // Example usage of Vector class
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    // ...
    return 0;
}
