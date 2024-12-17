#include "main.hpp"

#include <iostream>
#include <string>

NUMB_TYPE add_str_number(const std::string &str)
{
  NUMB_TYPE sum = 0;
  for (char c : str)
  {
    if (isdigit(c))
    {
      sum += c - '0';
    }
  }
  return sum;
}

// int main() {
//   std::string input = "1234";
//   int result = add_str_number(input);
//   std::cout << "The sum of the digits in \"" << input << "\" is " << result << std::endl;
//   return 0;
// }