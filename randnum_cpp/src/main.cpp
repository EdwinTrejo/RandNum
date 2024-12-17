#include "main.hpp"
#include "big_odd_number.hpp"
#include "add_str_number.hpp"

#include <cstring>  // Include this header for strlen
#include <iostream> // Include this header for std::cout
#include <string>   // Include this header for std::string

int main(int argc, char *argv[])
{
  long size = 40; // Default size
  if (argc > 1)
  {
    size = std::stol(argv[1]);
  }

  std::cout << "Size: " << std::to_string(size) << std::endl;

  // Create a string of the desired size
  std::string number(size, '0');

  // Generate the big odd number
  NUMB_TYPE rawnumber = generateBigOddNumber(number, size);
  std::cout << number << std::endl;
  std::cout << "----------------------------------------" << std::endl;

  while (number.length() > 1)
  {
    rawnumber = add_str_number(number);
    number = TO_STRING(rawnumber);
    std::cout << number << std::endl;
    std::cout << "----------------------------------------" << std::endl;
  }

  // Convert the string number to an integer
  // NUMB_TYPE num = STON(number);

  if ((rawnumber % 3) == 0)
  {
    std::cout << "The number is divisible by 3" << std::endl;
  }
  else
  {
    std::cout << "The number is not divisible by 3" << std::endl;
  }

  return 0;
}

std::string to_string_uint128(UINT128 value)
{
  if (value == 0)
    return "0";

  size_t char_count = char_count_unsigned_uint128(value);
  std::string result(char_count, '0'); // Pre-allocate string with the required size

  for (size_t i = char_count; i > 0; --i)
  {
    result[i - 1] = '0' + (value % 10); // Set the last character
    value /= 10;                        // Move to the next digit
  }

  return result;
}

UINT128 stoi_uint128(const std::string &str)
{
  UINT128 result = 0;
  for (char c : str)
  {
    if (c < '0' || c > '9')
    {
      throw std::invalid_argument("Invalid character in input string");
    }
    UINT128 digit = c - '0';
    if (result > (std::numeric_limits<UINT128>::max() - digit) / 10)
    {
      throw std::out_of_range("Value exceeds unsigned __int128 range");
    }
    result = result * 10 + digit;
  }
  return result;
}

size_t char_count_unsigned_uint128(UINT128 value)
{
  if (value == 0)
    return 1; // Special case for 0
  size_t count = 0;
  while (value > 0)
  {
    count++;
    value /= 10; // Reduce the number by one digit
  }
  return count;
}