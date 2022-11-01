/* Напишите короткую программу, которая записывает рост в футах и дюймах и вес в фунтах (для хранения используйте 3 переменных). 
Программа должна выдать индекс массы тела (BMI). Для этого сначала преобразуйте рост в дюймы (футы*12+дюймы). 
Затем преобразуйте рост в метры (дюймы*0.0254). Далее преобразуйте вес в фунтах в массу в килограммах, (фунты/2.2). 
После этого рассчитайте BMI, разделив массу в килограммах на квадрат роста в метрах. Для коэфициентов преобразований используйте символьные константы. */

#include <iostream>     // дирректива подключения заголовочного файла стандартного ввода-вывода
int main ()             // объявление функции main  
{
    using namespace std;    // подключение пространства имён std
    cout << "\t-- BMI calculator --\n\nEnter height in feets and inches:\n";   // вывод строки символов на экран
    cout << "Feets  : ";      // вывод строки символов на экран
    int heightFeet = 0;     // объявление переменной
    cin >> heightFeet;      // инициализация переменной введённым значением
    cout << "Inches : ";     // вывод строки символов на экран
    int heightInches = 0;   // объявление переменной
    cin >> heightInches;    // инициализация переменной введённым значением
    cout << "Enter weight in pounds: "; // вывод строки символов на экран
    short weightPounds = 0; // объявление переменной
    cin >> weightPounds;    // инициализация переменной введённым значением
    const int FeetToInches = 12;    // символьная константа, представляющая количество дюймов в одном футе
    const double InchesToMeters = 0.0254;   // символьная константа, представляющая количество метров в одном дюйме
    const double PoundsToKilograms = 2.2;   // символьная константа, представляющая количество фунтов в одном килограмме
    cout << "\n\tBMI = " << weightPounds/PoundsToKilograms/((heightFeet*FeetToInches+heightInches)*InchesToMeters*(heightFeet*FeetToInches+heightInches)*InchesToMeters);
                    //  <<знач. в фунтах/       2.2       /((знач. в футах * 12 + знач. в дюймах )*    0.0254    *(знач. в футах * 12 + знач. в дюймах )*    0.0254    );
    cin.get();      // использование функции-члена .get() - ожидание ввода любого символа, для приостановки выполнения программы и просмотра результата
    cin.get();
    return 0;       // оператор возврата
}