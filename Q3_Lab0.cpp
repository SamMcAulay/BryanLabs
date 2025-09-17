#include <iostream>

void printPattern1(int rows) {
    for (int i = 1; i <=rows; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void printPattern2(int rows) {
    for (int i = 1; i <= rows; ++i) {
        for (int s = 1; s <= (rows - i); ++s) {
            std::cout << " ";
        }
        for (int j = 1; j <= (2 * i - 1); ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void printPattern3(int rows) {
    int num = 1;
    for (int i = 1; i <=rows; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << num << " ";
            num++;
        }
        std::cout << std::endl;
    }
}

int main() {
    int height = 5;
    int heightNum = 4;
    std::cout << "----- a -----" << std::endl;
    printPattern1(height);

    std::cout << std::endl;

    std::cout << "----- b -----" << std::endl;
    printPattern2(height);

    std::cout << std::endl;

    std::cout << "----- c -----" << std::endl;
    printPattern3(heightNum);

    std::cout << std::endl;



    return 0;
}