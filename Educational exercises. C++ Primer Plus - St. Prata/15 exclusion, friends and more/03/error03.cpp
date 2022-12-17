// 3. Это упражнение подобно упражнению 2, но исключения должны быть производными 
// от базового класса (потомка logic_error), который хранит два значения аргументов. 
// Исключения должны содержать метод, который выводит эти значения и имя функции, 
// и единственный блок catch, который используется для обоих исключений. 
// Каждое исключение должно приводить к прекращению цикла обработки.

// 2. Измените код в листинге 15.11 так, чтобы два типа исключений были классами,
// производными от класса logic_error, определенного в заголовочном файле <stdexcept>.
// Сделайте так, чтобы каждый метод what() сообщал имя функции и суть проблемы.
// Объекты исключений не должны содержать значение ошибки,
// они должны просто поддерживать метод what().

// error4.cpp -- using exception classes
#include <iostream>
#include <cmath> // or math.h, unix users may need -lm flag
#include "exc_mean.h"
// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);
int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    double x, y, z;

    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try
        { // start of try block
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y
                 << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y
                 << " is " << gmean(x, y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }                     // end of try block
        // catch (my_err &bg) // start of catch block
        // {
        //     std::cout << bg.what();
        //     cout << "Try again.\n";
        //     continue;
        // }
        catch (my_err &hg)
        {
            std::cout << hg.what();
            cout << "Sorry, you don't get to play any more.\n";
            break;
        } // end of catch block
    }
    cout << "Bye!\n";
    cin.get();
    cin.get();
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean("hmean()", a, b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean("gmean()", a, b);
    return std::sqrt(a * b);
}
