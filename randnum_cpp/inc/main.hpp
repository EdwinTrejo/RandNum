#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <cmath>
#include <vector>

#define UINT128 unsigned __int128

std::string to_string_uint128(UINT128 value);
UINT128 stoi_uint128(const std::string &str);
size_t char_count_unsigned_uint128(UINT128 value);

#define NUMB_TYPE UINT128
#define STON(x) stoi_uint128(x)
#define TO_STRING(x) to_string_uint128(x)

#endif // MAIN_HPP