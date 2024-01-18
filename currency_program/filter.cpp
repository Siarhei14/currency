#include "filter.h"
#include <cstring>
#include <iostream>

currency_structure** filter(currency_structure* array[], int size, bool (*check)(currency_structure* element), int& result_size) {
	currency_structure** result = new currency_structure * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;

}

bool filter_currency_by_bank_name(currency_structure* element)
{
	return element->bank_name.compare("Беларусбанк") == 0;
}

bool filter_currency_by_sell(currency_structure* element)
{
	return element->sell < 2.5 ? true : false;
}