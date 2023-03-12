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
    cout << "Задано цiлi числа a, b, c та d.\nОбчислити вираз без використання операцiй множення та дiлення(замiнивши на iх операцiй зсувiв).\n";
    cout << "Введiть a, b, c, d:";
    int a, b, c, d, r, r2;
    cin >> a >> b >> c >> d;
    r = 33 * b + (d * 15 + 12 * a) / 512 - 65 * c + d * 14;
    r2 = (b + (b << 5)) + (((d << 4) - d + (b << 3) + (b << 2)) >> 9) - ((c << 6) + c) + ((d << 4) - (d << 1));
    cout << "Результат: \nЗвичайне обчислювання:" << r << "\nПобiтовi операцiї:" << r2 << endl;
    cin.get();
    return;
}

void task2()
{
    // Шифрування даних з використання побітових операцій 
    // Data encryption using bitwise operations
    cout << "Data encryption using bitwise operations  \n";

    char S[128];
    unsigned short Rez[128];
    
    unsigned char c;
    unsigned short r, t, i, b;
    short j;
    cout << "Input text: ";
    cin.get(S, 128);
    cout << endl;
    for (i = 0; i < 128; i++) //
    {
        r = 0;
        t = 1;
        b = 0;
        for (j = 0; j < 16; j++) // обчислення біта парності
        {
            if (r & t) {
                if (b == 0) b = 1; else b = 0;
            }
            t <<= 1;
        }
        r |= b;         // 0 біт – біт парності (1 біт)

        c = S[i];       // у бітах 1-8 ASCII - код букви (8 біт)
        t = c;
        r |= t << 1;

        r |= i << 9;    // у бітах 9-15 позиція букви у рядку (7 біти)

        Rez[i] = r;
    }
    for (i = 0; i < 128; i++) {
        cout << hex << Rez[i] << "\t";
        if ((i+1) % 4 == 0) cout << endl;
    }
        
    cin.get();
    return;
}

void task3()
{
    // Шифрування даних з використання стуктур з бітовими полями 
    // Data encryption using structures with bit fields
    cout << "Data encryption using structures with bit fields \n";
    int h, x, mb1 = 1, mb3 = 1 << 2;
    cout << "Input h: ";
    cin >> h;
    if ((h & mb1) == 1 && ((h & mb3) >> 2) == 0) x = h << 2;
    else x = h >> 1;
    cout << "h= " << h << "; x= " << x << endl;
    cin.get();
}


void task4()
{   // Задача із використання побітових операцій
    // The problem of using bitwise operations
    cout << " Data encryption using structures with bit fields \n";

}


int Do() 
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
        cout << "Press any key and enter\n";
        ch = cin.get();
    } while (ch != '6');

    return 0;
}


