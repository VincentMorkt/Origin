/*Напишите программу, которая запрашивает у пользователя 10 результатов игры в гольф, сохраняя их в массиве.
При этом необходимо обеспечить возможность прекращения ввода до ввода всех 10 результатов.
Программа должна отобразить все результаты в одной строке и сообщить их среднее значение.
Реализуйте ввод, отображение и вычисление среднего в трех отдельных функциях, работающих с массивами.
*/
#include <iostream>
using namespace std;
int FunctEnter(int arr[], int size); // прототипы функций
void FunctCout(int arr[], int size);
double mean(int arr[], int size);
int main()
{
    const int Num = 10; // константа, определающая размер массива и соответственно лимит значений
    int golfScore[Num]; // объявление массива
    int temp = 0;       // переменная для возврата количества введённых значений и управления функциями
    while (true)        // бесконечный цикл
    {
        temp = FunctEnter(golfScore, Num); // фунуция принимает имя массива и его размер, а возвращает количество введённых значений
        if (temp < 0)                      // цикл прерывается, если функция ввода возвращает отрицательное значение, что соответствует вводу 'q'
            break;
        FunctCout(golfScore, temp); // функция принимает имя массива и количество введённых значений
    }
    cout << "\nQuit... Press <ENTER> to close."; // закрытие программы
    cin.get();                                   // ожидание ввода для просмотра результатов работы программы
    return 0;
}
int FunctEnter(int arr[], int size) // фунуция ввода, принимает имя массива и его размер, а возвращает количество введённых значений
{
    cout << "Enter up to " << size << " golf scores (enter '0' to complete, enter 'q' to exit):\n";
    int i = 0; // объявление переменных
    char ch = 0;
    for (i = 0; i < size; i++) // цикл для последовательного ввода значения в элементы массива
    {
        while (true)                            // бесконечный цикл, прерываемый корректным значением
        {                                       //
            cout << "Round #" << i + 1 << ": "; //
            cin >> arr[i];                      // ввод значения
            if (cin)                            // если ввод успешен (введено число)
            {                                   //
                while (cin.get() != '\n')       // очистка потока ввода
                    continue;                   //
                break;                          // прервать бесконечный цикл while
            }
            else                                  // иначе
            {                                     //
                cin.clear();                      // снять failbit
                while (cin.get(ch) && ch != '\n') // цикл очистки потока ввода
                    if (ch == 'q' || ch == 'Q')   // проверка на ввод 'q'
                    {                             // если в потоке найдено 'q' или 'Q'
                        while (cin.get() != '\n') // очистка потока ввода
                            continue;             //
                        return -1;                // завершение функции с возвратом значения -1, которое будет использовано для завершения программы
                    }
                cout << "Bad input! Please, enter integer.\n"; // если 'q' не обнаружено - сообщение об ошибке и продолжение цикла
            }
        }
        if (arr[i] == 0)                                   // если после успешного ввода обнаруживается, что введённое значение равно 0
        {                                                  //
            cout << "You entered '0', input complet.\n\n"; // сообщение о завершении ввода
            return i;                                      // возврат количества введённых значений
        }
    }
    cout << "You completed the input.\n\n"; // если счётчик цикла достиг лимита - сообщение о завершении ввода
    return i;                               // возврат количества введённых значений
}
void FunctCout(int arr[], int size) // функция вывода на экран, принимает имя массива и количество введённых значений, ничего не возвращает
{
    cout << "You entered " << size << " scores:\n";    // вы ввели size значений
    for (int i = 0; i < size; i++)                     // цикл вывода на экран
        cout << arr[i] << '\t';                        //
    cout << endl                                       //
         << "Mean score = " << mean(arr, size) << endl // вывод среднего значения, вызов функции для его нахождения
         << endl;
}
double mean(int arr[], int size) // функция принимает имя массива и количество введённых значений, а возвращает их среднее значение
{
    double sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum / size;
}