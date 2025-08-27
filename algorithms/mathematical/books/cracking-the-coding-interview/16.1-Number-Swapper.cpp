#include <iostream>

void swap(int &a, int &b)
{
    std::cout << "A:" << a << " B:" << b << std::endl;

    b = a ^ b;
    a = a ^ b;
    b = a ^ b;

    std::cout << "A:" << a << " "
              << "B:" << b
              << std::endl
              << std::endl;
}

int main()
{
    int a = 3;
    int b = 4;
    swap(a, b);

    a = 3;
    b = -4;
    swap(a, b);

    a = -3;
    b = -4;
    swap(a, b);

    return 0;
}