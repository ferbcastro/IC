#include "aux.hpp"

void get (int64_t &var)
{
    std::cin >> var;
    while (std::cin.get () != '\n');
}