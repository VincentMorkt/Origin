/*Постройте программу, которая отслеживает пожертвования в Общество Защиты Влиятельных Лиц. Она должна запрашивать у пользователя количество меценатов,
а затем приглашать вводить их имена и суммы пожертвований от каждого. Информация должна сохраняться в динамически выделяемом массиве структур.
Каждая структура должна иметь два члена: символьный массив (или объект string) для хранения имени и переменную-член типа double - для хранения суммы пожертвования.
После чтения всех данных программа должна отображать имена и суммы пожертвований тех, кто не пожалел $ 10 ООО и более. Этот список должен быть озаглавлен меткой
"Graпd Patroпs". После этого программа должна выдать список остальных жертвователей. Он должен быть озаглавлен "Patroпs".
Если в одной из двух категорий не окажется никого, программа должна напечатать "nоnе". Помимо отображения двух категорий, никакой другой сортировки делать не нужно.
*/

#include <iostream>
#include <string>

struct patrons
{
    std::string name;
    double donation;
};

int main()
{
    using namespace std;
    cout << "Enter number of patrons: ";
    int numOfPatrons = 0;

    // ввод данных ///////////////////////////////////////////////////////////////////////////////

    while (true) // ввод числа, отражающего количество меценатов
    {
        if (cin >> numOfPatrons && numOfPatrons > 0 && cin.get() == '\n') // если ввод удачный, число больше нуля и после числа следует символ переноса строки
            break;                                                        // прервать цикл. Проверка исключает ввод числа в некорректном формате или ввод другого символа
        else                                                              // иначе
        {
            cout << "Invalid input, please enter a positive number without spaces or punctuation: "; // вывести строку с подсказкой о корректном вводе
            cin.clear();                                                                             // снять флаг failbit объекта cin, если он был установлен попыткой ввода нечисловых символов
            while (cin.get() != '\n')                                                                // очистка потока ввода
                continue;                                                                            //
        }                                                                                            // поскольку внешний цикл может прервать только корректный ввод, соответствующий условию if, цикл будет продолжен
    }
    patrons *list = new patrons[numOfPatrons]; // объявление динамического массива структур, состоящего из количества элементов, введённого ранее
    for (int i = 0; i < numOfPatrons; i++)     // цикл для последовательно ввода значений переменных массива структур
    {
        cout << "Name of patrons #" << i + 1 << ": "; // введите имя мецената #i+1
        while (getline(cin, list[i].name))            // передать вводимую строку в объект cin с помощью вызова функции getline(cin,string). продолжать цикл, если не возникло ошибки ввода
            if (list[i].name != "")                   // если введённое значение не равно пустой строке. Проверка сделана на случай случайного нажатия Enter или попытки пропустить ввод имени.
                break;                                // Однако она примет пробел или \t
            else                                      // иначе
                cout << "Please enter a name: ";      // вывод строки "Пожалуйста, введите имя:". Далее цикл запустится заново. Фигурные скобки здесь не требуются
        cout << "Donation: ";
        while (true) // цикл ввода суммы пожертвования
        {
            if (cin >> list[i].donation && list[i].donation > 0 && cin.get() == '\n') // если ввод удачный, введённое значение больше нуля и после него не следует дополнительных символов
            {                                                                         // исключает ввод в формате 10 000, что было бы прочитанно программой как 10 без сообщения о некорректном вводе
                cout << endl;                                                         // перенос строки
                break;                                                                // прерывание цикла
            }
            else // иначе
            {
                cout << "Invalid input, please enter a positive number without spaces or punctuation: "; // подсказка о корректном вводе и далее очистка метки ошибки и очереди потока ввода
                cin.clear();
                while (cin.get() != '\n')
                    continue;
            }
        } // завершение цикла ввода суммы пожертвования
    }     // завершение внешнего цикла ввода

    // отображение данных ///////////////////////////////////////////////////////////////////////////

    cout << "\t Grand Patrons\n";
    bool noneMark = 0;                     // объявление переменной метки наличия прошедших проверку значений
    for (int i = 0; i < numOfPatrons; i++) // цикл вывода для списка Grand Patrons
        if (list[i].donation >= 10000)     // если сумма пожертвования больше 10000
        {
            cout << list[i].name << " - " << int(list[i].donation) << endl; // вывести имя и сумму пожертвования
            noneMark += 1;                                                  // увеличить значение метки
        }
    if (0 == noneMark)    // если метка не была ни разу увеличена (и, соответственно, отсутствуют значения, выводимые в списке Grand Patrons)
        cout << "none\n"; // вывести "none"

    cout << "\n\t Patrons\n";
    noneMark = 0;                          // обнуление метки
    for (int i = 0; i < numOfPatrons; i++) // цикл вывода для списка Patrons
        if (list[i].donation < 10000)      // далее всё аналогично кроме условия проверки (< вместо >=)
        {
            cout << list[i].name << " - " << list[i].donation << endl;
            noneMark += 1;
        }
    if (0 == noneMark)
        cout << "none\n";

    // завершение программы ///////////////////////////////////////////////////////////////////////////

    delete[] list; // освобождение памяти, занимаемой динамическим массивом структур

    cout << "\nPress <ENTER> to close.";
    cin.get(); // ожидание ввода для просмотра результатов работы программы
    return 0;
}