#ifndef FILE_READER_H
#define FILE_READER_H

#include "currency_structure.h"

void readFromFile(const char* file_name, currency_structure* array[], int& size);

#endif