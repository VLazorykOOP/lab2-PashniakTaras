#include <iostream>
#include <string>
#include <clocale>
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

    /*  Задано текст до 128 символів. Доповнити пробілами до 128 символів. Шифрувати тексти 
        таким чином, щоб кожний символ тексту записувався у два байти. Два байти мають таку 
        структуру: 
            0 біт – біт парності (1 біт)
            у бітах 1-8 ASCII - код букви (8 біт), 
            у бітах 9-15 позиція букви у рядку (7 біти) */
    cout << "Data encryption using bitwise operations  \n";

    char S[128];
    unsigned short Rez[128];
    
    unsigned char c;
    unsigned short r, t, i, b;
    short j;
    cout << "Input text: ";
    cin.get(S, 128);        
    int n = strlen(S);          // Доповнення тексту пробілами
    for (int i = n; i < 128; i++) S[i] = '\0';
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

    struct bits {
        unsigned char c : 8;   // розмірність ASCII дорівнює максимум 8 бітів
        unsigned short r : 16; // займатиме максимум 16 бітів як зберігач результату
        unsigned short t : 16; // тимчасова змінна
        unsigned short i : 8;  // оскільки i<=128, то займатиме максимум 8 бітів
        unsigned short b: 1;   // займає тільки один біт
        short j: 5;            // оскільки j<=16, то займатиме максимум 5 бітів 
    };
    char S[128];
    unsigned short Rez[128];
    bits bit;
    cout << "Input text: ";
    cin.get(S, 128);
    cout << endl;
    int n = strlen(S);          // Доповнення тексту пробілами
    for (int i = n; i < 128; i++) S[i] = '\0';
    
    for (bit.i = 0; bit.i < 128; bit.i++) //
    {
        bit.r = 0;
        bit.t = 1;
        bit.b = 0;
        for (bit.j = 0; bit.j < 16; bit.j++) // обчислення біта парності
        {
            if (bit.r & bit.t) {
                if (bit.b == 0) bit.b = 1; else bit.b = 0;
            }
            bit.t <<= 1;
        }
        bit.r |= bit.b;         // 0 біт – біт парності (1 біт)

        bit.c = S[bit.i];       // у бітах 1-8 ASCII - код букви (8 біт)
        bit.t = bit.c;
        bit.r |= bit.t << 1;

        bit.r |= bit.i << 9;    // у бітах 9-15 позиція букви у рядку (7 біти)

        Rez[bit.i] = bit.r;
    }
    for (bit.i = 0; bit.i < 128; bit.i++) {
        cout << hex << Rez[bit.i] << "\t";
        if ((bit.i + 1) % 4 == 0) cout << endl;
    }

    cin.get();
    return;
}

string zsuv(string str, int shift) {
    int size = str.size();
    // Якщо зсув більше за розмір рядка, то зменшуємо його до значення, що не перевищує розмір рядка
    if (shift > size) {
        shift = shift % size;
    }
    // Якщо зсув дорівнює розміру рядка, то рядок не змінюється
    if (shift == size) {
        return str;
    }
    // Зсуваємо символи рядка
    for (int i = 0; i < size; i++) {
        // Обчислюємо індекс символу, який буде знаходитися на i-й позиції після зсуву
        int index = (i + shift) % size;
        // Замінюємо символ на i-й позиції символом, який знаходиться на index-й позиції
        char tmp = str[i];
        str[i] = str[index];
        str[index] = tmp;
    }
    return str;
}

void task4()
{   // Задача із використання побітових операцій
    // The problem of using bitwise operations
    // Зашифрувати рядок символів циклічним зсувом вліво його бітів на вказану величину
    cout << "Data encryption using structures with bit fields \n";

    setlocale(LC_CTYPE, "ukr");
    string str;
    cout << "Введiть рядок символiв: ";
    getline(cin, str);
    int shift;
    cout << "Введiть величину зсуву у бiтах: ";
    cin >> shift;

    string encrypted_str = zsuv(str, shift);

    cout << "Зашифрований рядок символiв: " << encrypted_str << endl;
    cin.get();
    return;
}





