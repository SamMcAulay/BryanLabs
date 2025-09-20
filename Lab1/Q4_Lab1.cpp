#include <iostream>
#include <string>
#include <vector>
#include <limits> // Required for std::numeric_limits
#include <new>    // Required for std::bad_alloc2

int main() {

    int num_names = 0;
    std::cout << "How many names do you wish to enter? ";
    std::cin >> num_names;


    while (std::cin.fail() || num_names <= 0) {
        std::cout << "Invalid input. Please enter a whole number greater than 0: ";

        std::cin.clear();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> num_names;
    }


    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    std::string* names_array = nullptr;

    try {

        names_array = new std::string[num_names];
        std::cout << "Successfully allocated memory for " << num_names << " names." << std::endl;


        std::cout << "\nPlease enter the names:\n";
        for (int i = 0; i < num_names; ++i) {
            std::cout << "Name #" << i + 1 << ": ";
            std::getline(std::cin, names_array[i]);
        }


        std::cout << "\n--- Your List of Names ---\n";
        for (int i = 0; i < num_names; ++i) {
            std::cout << names_array[i] << std::endl;
        }
        std::cout << "--------------------------\n";


        std::cout << "\nDoubling the size of the array..." << std::endl;
        int new_size = num_names * 2;


        auto resized_array = new std::string[new_size];


        for (int i = 0; i < num_names; ++i) {
            resized_array[i] = names_array[i];
        }


        delete[] names_array;


        names_array = resized_array;

        std::cout << "Array successfully resized." << std::endl;
        std::cout << "Initial capacity: " << num_names << std::endl;
        std::cout << "New capacity: " << new_size << std::endl;

    } catch (const std::bad_alloc& e) {

        std::cerr << "\nError: Memory allocation failed." << std::endl;
        std::cerr << "You requested space for too many names (" << num_names << ")." << std::endl;
        std::cerr << "Exception details: " << e.what() << std::endl;


        names_array = nullptr;
    }

    delete[] names_array;


    return 0; // Indicate successful execution
}
