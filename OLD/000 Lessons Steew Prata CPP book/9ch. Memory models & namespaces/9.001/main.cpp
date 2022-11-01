// Постройте многофайловую Программу на основе этого заголовочного файла.
// Один файл по имени golf.cpp должен содержать определения функций, которые соответствуют прототипам заголовочного файла.
// Второй файл должен содержать функцию main() и обеспечивать реализацию всех средств прототипированных функций.
// Например, цикл должен запрашивать ввод массива структур типа golf и прекращать ввод после заполнения массива,
// либо когда вместо имени игрока в гольф пользователь вводит пустую строку.
// Чтобы получить доступ к структурам типа golf, функция main() должна использовать только прототипированные функцйи.
#include <iostream>
#include "golf.h"

namespace // пространство имён, содержащее массив структур для управления доступа к именам
{
    const int Num = 10;
    golf List[Num] = {0};
}
using std::cin; // объявление имён для работы с вводом-выводом
using std::cout;
using std::endl;

// Функция главного меню, предлагает выбрать пункты меню от 1 до 4 и возвращает соответствующее значение
int mainMenu(void);
// Функция верификации ввода, просит ввести Y/N и возвращает 1, если введено Y и 0, если введено N
int VerificationChoice(void);
// Функция записи новой базы данных в массив структур, возвращает фактическое количество введённых значений
int newList(golf l[], int num);
// Функция просмотра существующей базы данных
void showList(const golf l[], int num);
// Функция выбора члена массива структур и редактирования гендикапа
void editList(golf l[], int num);

int main()
{
    int factNum = 0; // переменная для сохранения фактического количества значений в базе данных
    while (1)        // цикл работы с меню
    {
        int choice = mainMenu(); // объявление переменной, определяемой выбором пункта меню с помощью функции меню
        switch (choice)          // в зависимости от выбранного пункта меню
        {
        case 1:                                             // создание нового списка
            if (List->fullname[0] != '\0' && !VerificationChoice()) // если уже существует список и НЕ пройдена верификация
                continue;                                   // начать новый цикл
            factNum = newList(List, Num);                   // если списка не существовало, или была пройдена верификация выполнение функции создания нового списка и запись количества введённых значений
            continue;                                       // начать новый цикл
            ;
        case 2:               // просмотр списка
            if (factNum == 0) // если ранее не было введено никаких значений
            {
                cout << "Empty list!\n"; // сообщение о пустом списке
                continue;                // новый цикл
            }
            showList(List, factNum); // иначе вызов функции просмотра списка
            continue;                // новый цикл
        case 3:                      // редактирование гендикапа
            if (factNum == 0)        // так же, как в предыдущем пункте
            {
                cout << "Empty list!\n";
                continue;
            }
            editList(List, factNum); // вызов функции редактирования
            continue;                // новый цикл
        case 4:                      // завершение работы
            break;                   // прерывание switch
        }
        break; // прерывание цикла
    }

    cout << "Closing...";
    cin.get();
    return 0;
}

int mainMenu(void) // функция главного меню
{
    while (1)
    {
        cout << endl
             << "1) New List     \t2) Show List\n" // пункты меню
                "3) Edit handicap\t4) Close\n"
                "Enter you choice: ";
        int choice = 0;       // переменная для записи выбора
        if (!(cin >> choice)) // если ввод не успешн (введено не число)
        {
            cout << "Bad input! (mainMenu input eror)\n"; // сообщение об ошибке
            ClearIStream();                               // очистка потока ввода
            continue;                                     // новая попытка
        }
        if (choice > 4 || choice < 1) // проверка соответствия ввода доступным пунктам меню
        {
            cout << "Bad input! (mainMenu unavailable choice)\n"; // сообщение об ошибке
            ClearIStream();                                       // очистка потока ввода
            continue;                                             // новая попытка
        }
        ClearIStream(); // если ввод успешн и соответсвует пунктам меню
        cout << endl;   // декоративный отступ
        return choice;  // возврат введённого значения
    }
}

int VerificationChoice(void) // функция верификации выбора
{
    char ch;  // переменная для ввода выбора
    while (1) // цикл ввода выбора
    {
        cout << "You deleted old list. Are you sure?(Y/N): "; // верификация выбора
        cin >> ch;                                            // ввод выбора
        if (ch == 'N' || ch == 'n')                           // если введено "нет"
        {
            ClearIStream(); // очистка потока ввода
            return 0;       // вернуть 0
        }
        if (ch == 'Y' || ch == 'y') // если введено "да"
        {
            ClearIStream(); // очистка потока ввода
            return 1;       // вернуть 1
        }
        cout << "Bad input! (VerificationChoice)\n"; // иначе начать новый цикл
        ClearIStream();                              // очистка потока ввода
    }
}

int newList(golf l[], int num) // Функция записи новой базы данных в массив структур
{
    int factNum = 0; // счётчик фактических значений
    cout << "Enter names & handicaps. Enter empty name to break.\n\n";
    while (factNum < num) // цикл ввода
    {
        cout << "Player #" << factNum + 1 << endl; // номер игрока
        if (!setgolf(l[factNum]))                  // если функция ввода значений не возвращает 1
            break;                                 // остановка цикла ввода
        factNum++;                                 // инкремент счётчика
    }
    if (factNum == num)
        cout << "Input limit! \n";
    else
        cout << "You break input! \n";
    return factNum; // возврат фактического количества введённых структур
}

void showList(const golf l[], int num) //Функция отображения существующей базы данных
{
    for (int i = 0; i < num; i++) // цикл отображения массива структур
    {
        cout << "#" << i + 1 << ": "; // отображение номера игрока
        showgolf(l[i]);               // функция отбражения содержимого структуры
    }
}

void editList(golf l[], int num) // Функция выбора члена массива структур и редактирования гендикапа
{
    while (1)
    {
        int choice = 0;                                                // переменная для выбора номера игрока для редактирования
        cout << "Enter num of player to edit handicap (0 to break): "; // введите номер игрока
        if (!(cin >> choice))                                          // если ввод не успешн
        {
            cout << "Bad input! (showList input eror)\n"; // сообщение об ошибке
            ClearIStream();                               // очистка ввода
            continue;                                     // новый цикл
        }
        if (choice < 0 || choice > num) // если введено недоступное значение
        {
            cout << "Bad input! (showList unavailable choice)\n"; // сообщение об ошибке
            ClearIStream();                                       // очистка ввода
            continue;                                             // новый цикл
        }
        if (choice == 0) // если введён 0
            break;       // прерывание цикла и завершение функции
        while (1)        // цикл ввода гендикапа
        {
            cout << "Enter new handicap: "; // введите гендикап
            int newHandicap = 0;            // переменная для ввода
            if (!(cin >> newHandicap))      // если ввод не успешн
            {
                cout << "Bad input! (editList handicap input eror)\n"; // сообщение об ошибке и новая попытка
                ClearIStream();
                continue;
            }
            handicap(l[choice - 1], newHandicap); // вызов функции, переписывающей гендикап
            break;                                // завершение цикла ввода гендикапа
        }
    }
}