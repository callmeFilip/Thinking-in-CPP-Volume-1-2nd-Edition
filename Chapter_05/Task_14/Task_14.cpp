#include <iostream>
#include "Stack_Of_Int.h"

int main()
{
    Stack_Of_Int intStorage;
    int age = 23;

    intStorage.push(&age);
    std::cout << *intStorage.peek() << std::endl;

    age = 44;
    intStorage.push(&age);
    std::cout << *intStorage.pop() << std::endl;

    std::cout << *intStorage.peek() << std::endl;

    std::cout << *intStorage.pop() << std::endl;

    return 0;
}
