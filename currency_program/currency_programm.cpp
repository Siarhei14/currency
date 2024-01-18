#include <iostream>

#include "currency_structure.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"

using namespace std;

void output(currency_structure* item)
{
    cout << item->bank_name << ' ';
    cout << item->buy << ' ';
    cout << item->sell << ' ';
    cout << item->adress << ' ';
    cout << '\n';
}

void show_menu()
{
    cout << "------Меню------" << '\n';
    cout << "1. Вывод всех результатов" << '\n';
    cout << "2. Вывести всех студентов и их оценки по дисциплине «История Беларуси»" << '\n';
    cout << "3. Вывести всех студентов и дисциплины с оценками выше 7 баллов" << '\n';
    cout << "4. Сортировка вставками по возрастанию фамилии" << '\n';
    cout << "5. Сортировка вставками по возрастанию названия дисциплины" << '\n';
    cout << "6. Сортировка слиянием по возрастанию фамилии" << '\n';
    cout << "7. Сортировка слиянием по возрастанию названия дисциплины" << '\n';
    cout << "Для завершения введите -1" << '\n';
}

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Лабораторная работа #1. GIT\n";
    cout << "Вариант #4. Курсы валют\n";
    cout << "Савастеев Артем Денисович\n";
    cout << '\n';
    int size;
    int filter_size = 0;
    currency_structure* currency_list[MAX_FILE_ROWS_COUNT];
    currency_structure** currency_filter = new currency_structure * [0];
    try
    {
        readFromFile("data.txt", currency_list, size);
        for (int i = 0; i < size; i++)
        {
            output(currency_list[i]);
        }
        cout << '\n';
        cout << "Фильтр по Беларусбанку" << '\n';
        currency_filter = filter(currency_list, size, filter_currency_by_bank_name, filter_size);
        for (int i = 0; i < filter_size; i++)
        {
            output(currency_filter[i]);
        }
        cout << '\n';
        cout << "Фильтр по продаже" << '\n';
        currency_filter = filter(currency_list, size, filter_currency_by_sell, filter_size);
        for (int i = 0; i < filter_size; i++)
        {
            output(currency_filter[i]);
        }
        for (int i = 0; i < size; i++)
        {
            delete currency_list[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
}