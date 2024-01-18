#ifndef FILTER_H
#define FILTER_H

#include "currency_structure.h"

currency_structure** filter(currency_structure* array[], int size, bool (*check)(currency_structure* element), int& result_size);

bool filter_currency_by_bank_name(currency_structure* element);

bool filter_currency_by_sell(currency_structure* element);

#endif