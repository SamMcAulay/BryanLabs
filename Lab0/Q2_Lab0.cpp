#include <iostream>

int main() {

    int a;
    int b;

    std::cout << "--- Please enter your first number ---" << std::endl;
    std::cin >> a;

    std::cout << "--- Please enter your second number ---" << std::endl;
    std::cin >> b;

    int sum = a + b;

    std::cout << "The sum is: " << sum << std::endl;

}