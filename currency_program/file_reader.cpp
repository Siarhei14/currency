#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>

void readFromFile(const char* file_name, currency_structure* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            currency_structure* item = new currency_structure;
            file >> item->bank_name;
            file >> item->buy;
            file >> item->sell;
            file.read(tmp_buffer, 1);
            file.getline(item->adress, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка чтения файла!";
    }
}