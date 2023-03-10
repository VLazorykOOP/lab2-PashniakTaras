#include <iostream>
using namespace std;
#include "Tasks.h"
#include "Examples.h"
void MenuTask()
{
    cout << "     Menu Task   \n";
    cout << "    1.  Calculation of expressions using bitwise operations  \n";
    cout << "    2.  Data encryption using bitwise operations \n";
    cout << "    3.  Data encryption using structures with bit fields \n";
    cout << "    4.  The problem of using bitwise operations \n";
    cout << "    5.  Examples of problems using bitwise operations \n";
    cout << "    6.  Exit \n";
}
void task1() {
    // Обчислення виразів з використанням побітових операцій
    // Calculation of expressions using bitwise operations 
    cout << " Calculation of expressions using bitwise operations  \n";
    setlocale(LC_CTYPE, "ukr");
    cout << "Задано цілі числа a, b, c та d.\nОбчислити вираз без використання операцій множення та ділення(замінивши на їх операцій зсувів).\n";
        cout << "Введіть a, b, c, d:";
        int a, b, c, d, r, r2;
        cin >> a >> b >> c >> d;
        r = 33 * b + (d * 15 + 12 * a) / 512 - 65 * c + d * 14;
        r2 = (b << 5) + b + ((d << 4) - d + (b << 3) + (b << 2)) >> 9 - (c << 6) + c + (d << 4) - (d << 1);
        cout << "Результат: \nЗвичайне обчислювання:" << r << "\nПобітові операції:" << r2;
        return;
}

void task2()
{
    // Шифрування даних з використання побітових операцій 
    // Data encryption using bitwise operations
    cout << " Data encryption using bitwise operations  \n";

}

void task3()
{
    // Шифрування даних з використання стуктур з бітовими полями 
    // Data encryption using structures with bit fields
    cout << "  Data encryption using structures with bit fields \n";
}


void task4()
{   // Задача із використання побітових операцій
    // The problem of using bitwise operations
    cout << " Data encryption using structures with bit fields \n";

}


int main() 
{
    char ch = '5';
    do {
        system("cls");
        MenuTask();
        ch = cin.get();

        cin.get();

        switch (ch) {
        case '1': task1();   break;
        case '2': task2();   break;
        case '3': task3();   break;
        case '4': task4();   break;
        case '5': cout << "No task5 available.";  break;
        case '6':
        return 0;
        }
        cout << " Press any key and enter\n";
        ch = cin.get();
    } while (ch != '6');

    return 0;
}


