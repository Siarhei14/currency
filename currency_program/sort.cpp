#include "sort.h"
#include <iostream>

using namespace std;

int compare_by_difference(currency_structure* first, currency_structure* second)
{
	if ((first->buy - first->sell) < (second->buy - second->sell)) {
		return 1;
	}
	else if ((first->buy - first->sell) == (second->buy - second->sell)) {
		return 0;
	}
	return -1;
}

int compare_by_bank_name(currency_structure* first, currency_structure* second)
{
	if (first->bank_name.compare(second->bank_name) == 0) {
		if (strcmp(first->adress, second->adress) > 0) {
			return 1;
		}
		else if (strcmp(first->adress, second->adress) == 0) {
			return 0;
		}
		else {
			return -1;
		}
	}
	else if (first->bank_name.compare(second->bank_name) > 0) {
		return 1;
	}
	return -1;
}

void bubble_sort(currency_structure* array[], int size, int (*check)(currency_structure* first, currency_structure* second))
{
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (check(array[j], array[j + 1]) > 0) {
				currency_structure* temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void merge(currency_structure* arr[], int l, int m, int r, int (*check)(currency_structure* first, currency_structure* second)) {
    int n1 = m - l + 1;
    int n2 = r - m;

    currency_structure** L = new currency_structure * [n1];
    currency_structure** R = new currency_structure * [n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0;

    int k = l;
    while (i < n1 && j < n2) {
        if (check(L[i], R[j]) <= 0) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void merge_sort(currency_structure* array[], int l, int r, int (*check)(currency_structure* first, currency_structure* second)) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(array, l, m, check);
        merge_sort(array, m + 1, r, check);
        merge(array, l, m, r, check);
    }
}