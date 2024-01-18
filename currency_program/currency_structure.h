#ifndef CURRENCY_STRUCTURE_H
#define CURRENCY_STRUCTURE_H

#include <string>

#include "constants.h"

struct currency_structure
{
    std::string bank_name;
    double buy;
    double sell;
    char adress[MAX_STRING_SIZE];
};

#endif