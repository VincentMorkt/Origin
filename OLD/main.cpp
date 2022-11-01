/* Напишите программу, запрашивающую у пользователя ввод двух целых чисел. Затем программа должна вычислить и выдать сумму всех целых чисел, лежащих между этими двумя целыми. 
Предполагается, что меньшее значение вводится первым. Например, если пользователь ввел 2 и 9, программа должна сообщить, что сумма всех целых чисел от 2 до 9 равна 44. */

#include <iostream> // дирректива подключения заголовочного файла ввода-вывода 
int main ()         // объявление функции main
{           
    using namespace std;    // дирректива подключения пространства имён std
    int x = 0, y = 0;       // объявление и преинициализация переменных x и y. Использована операция (,) для комбинирования двух выражений в одном операторе объявления
    cout << "Enter two integer (lower first):\n"; // вывод на экран строковой константы
    cin >> x;               // ввод значений и присваиваивание их переменным
    cin >> y;
    cin.get();              // вызов функции-члена .get для отсечения ввода символа переноса строки
    int sum = 0;            // объявление переменной, которая будет хранить сумму диапазона
    for (int i=x;i<=y;i++)  // объявление цикла, инициализация переменной счётчика i и присваивание ей значения x. (нам нужно сохранить x для вывода на экран в будущем).
                            // проверочное выражение i<=y выдаст false при выходе счётчика за пределы указанного диапазона (нам нужно считать сумму включительно с заданным значением y)
                            // обновляющее выражение использует постфиксную операцию инкремента, увеличивая счётчик на 1
    sum += i;               // сумма считается с помощью оператора +=, который присваивает левому операнду значение суммы левого и правого операндов. Конец оператора цикла (;)
    cout << "SUM of range from " <<x <<" to " <<y <<" is " << sum <<endl; // вывод на экран строковых констант, введённых ранее значений и результата работы программы согластно ТЗ
    cin.get();  // вызов функции члена сin.get для приостановки выполнения программы и просмотра результата
    return 0;   // оператор возврата
}