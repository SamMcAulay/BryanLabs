#include <iostream>
#include <utility>

int main() {

    int a = 50;
    int b = 101;


    std::cout << "--- Before Swap ---" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << std::endl;


    std::swap(a, b);


    std::cout << "--- After Swap ---" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    return 0;
}