#include "main.hpp"
#include "big_odd_number.hpp"

#include <iostream>
#include <string>
#include <random>

NUMB_TYPE generateBigOddNumber(std::string &number, int size)
{
    // Use random_device and mt19937 for randomness
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> digitDist(0, 9);
    std::uniform_int_distribution<> oddDist(1, 9);

    for (int i = 0; i < size - 1; ++i)
    {
        number[i] = '0' + digitDist(gen);
    }

    // Ensure the last digit is odd
    number[size - 1] = '0' + oddDist(gen) | 1; // Force the last digit to be odd

    return STON(number);
}

// int main(int argc, char* argv[]) {
//     int size = 40; // Default size
//     if (argc > 1) {
//         size = std::stoi(argv[1]);
//     }

//     // Create a string of the desired size
//     std::string number(size, '0');

//     // Generate the big odd number
//     generateBigOddNumber(number, size);

//     // Output the generated number
//     std::cout << number << std::endl;

//     return 0;
// }
