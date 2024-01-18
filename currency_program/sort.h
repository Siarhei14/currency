#ifndef SORT_H
#define SORT_H

#include "currency_structure.h"

int compare_by_difference(currency_structure* first, currency_structure* second);

int compare_by_bank_name(currency_structure* first, currency_structure* second);

void bubble_sort(currency_structure* array[], int size, int (*check)(currency_structure* first, currency_structure* second));

void merge_sort(currency_structure* array[], int l, int r, int (*check)(currency_structure* first, currency_structure* second));

#endif