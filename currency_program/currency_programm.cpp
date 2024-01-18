#include <iostream>

#include "currency_structure.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"
#include "sort.h"
#include "processing.h"

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
    cout << "2. Вывести курсы валюты во всех отделениях банка «Беларусбанк» (с адресами)." << '\n';
    cout << "3. Вывести курсы валюты и адреса отделений банков, в которых продажа меньше 2,5." << '\n';
    cout << "4. Сортировка обменом по убыванию разницы между стоимостью продажи и покупки" << '\n';
    cout << "5. Сортировка обменом по возрастанию названию банка, а в рамках одного банка по возрастанию адреса отделения" << '\n';
    cout << "6. Сортировка слиянием по по убыванию разницы между стоимостью продажи и покупки" << '\n';
    cout << "7. Сортировка слиянием по возрастанию названию банка, а в рамках одного банка по возрастанию адреса отделения" << '\n';
    cout << "Для завершения введите -1" << '\n';
}

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Лабораторная работа #1. GIT\n";
    cout << "Вариант #4. Курсы валют\n";
    cout << "Плешко Сергей Владимирович\n";
    cout << '\n';
    int size;
    int filter_size = 0;
    int choise;
    currency_structure* currency_list[MAX_FILE_ROWS_COUNT];
    currency_structure** currency_filter = new currency_structure * [0];
    try
    {
        readFromFile("data.txt", currency_list, size);
        show_menu();
        cin >> choise;
        while (choise != -1)
        {
            switch (choise) {
            case 1:
                system("cls");
                cout << "----------Вывод всех результатов----------" << '\n';
                for (int i = 0; i < size; i++)
                {
                    output(currency_list[i]);
                }
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            case 2:
                system("cls");
                cout << "----------Вывести курсы валюты во всех отделениях банка «Беларусбанк» (с адресами)----------" << '\n';
                currency_filter = filter(currency_list, size, filter_currency_by_bank_name, filter_size);
                for (int i = 0; i < filter_size; i++)
                {
                    output(currency_filter[i]);
                }
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            case 3:
                system("cls");
                cout << "----------Вывести курсы валюты и адреса отделений банков, в которых продажа меньше 2,5.----------" << '\n';
                currency_filter = filter(currency_list, size, filter_currency_by_sell, filter_size);
                for (int i = 0; i < filter_size; i++)
                {
                    output(currency_filter[i]);
                }
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            case 4:
                system("cls");
                cout << "----------Сортировка обменом по убыванию разницы между стоимостью продажи и покупки----------" << '\n';
                bubble_sort(currency_list, size, compare_by_difference);
                for (int i = 0; i < size; i++)
                {
                    output(currency_list[i]);
                }
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            case 5:
                system("cls");
                cout << "----------Сортировка обменом по возрастанию названию банка, а в рамках одного банка по возрастанию адреса отделения----------" << '\n';
                bubble_sort(currency_list, size, compare_by_bank_name);
                for (int i = 0; i < size; i++)
                {
                    output(currency_list[i]);
                }
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            case 6:
                system("cls");
                cout << "----------Сортировка слиянием по по убыванию разницы между стоимостью продажи и покупки----------" << '\n';
                merge_sort(currency_list, 0, size - 1, compare_by_difference);
                for (int i = 0; i < size; i++)
                {
                    output(currency_list[i]);
                }
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            case 7:
                system("cls");
                cout << "----------Сортировка слиянием по возрастанию названию банка, а в рамках одного банка по возрастанию адреса отделения----------" << '\n';
                merge_sort(currency_list, 0, size - 1, compare_by_bank_name);
                for (int i = 0; i < size; i++)
                {
                    output(currency_list[i]);
                }
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            default:
                cout << "Такого пункта нет!" << '\n';
                show_menu();
                cin >> choise;
                break;
            }
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