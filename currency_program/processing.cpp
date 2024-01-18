#include <iostream>

#include "processing.h"

using namespace std;

double get_max_difference(currency_structure* array[], int size)
{
	double max_difference = 0;
	for (int i = 0; i < size; i++) {
		if ((array[i]->buy - array[i]->sell) > max_difference) {
			max_difference = array[i]->buy - array[i]->sell;
		}
	}
	return max_difference;
}
