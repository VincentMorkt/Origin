/*Напишите программу, которая использует массив char и цикл для чтения по одному слову за раз до тех пор, пока не будет введено слово done. 
Затем программа должна сообщить количество введенных слов (исключая done). Пример запуска должен быть таким:
Вводите слова (для завершения введите слово done):
anteater birthday category dumpster
envy finagle geometry done for sure
Вы в вели 7 слов.
Вы должны включить заголовочный файл cstring и применять функцию strcmp () для выполнения проверки. */

#include <iostream>
#include <cstring>
int main ()
{
    using namespace std;
    cout <<"Enter the words (to finish, enter the word done):\n";
    char word[25];      // объявление массива char
    int num = -1;       // num инициализированна значением -1, так как нам необходимо считать слова исключая done 
    do                  // do while гарантирует, что в маловероятном случае случайного значения в неинициализированном массиве, соответствующего слову "done" программа будет работать корректно
    {                   // также это позволяет работать с указателями char, не инициализируя значения  
        cin >> word;    // ввод слов. Использован объект cin, так как он принимает строки без пробельных символов. любой пробельный символ завершает ввод, а оставшиеся в буфере символы будут прочитаны
                        // в будущих запусках цикла. посчитав количество запусков цикла мы найдём количество слов, после которых следовал пробельный символ.
        num++;          // подсчёт количества запусков. Первый запуск присвоит переменной значение 0, на случай, если первым же словом будет введено "done"      
    } while (strcmp(word,"done"));   // функция strcmp() принимает в качестве аргументов две строки, а возвращает bool значение true если они не идентичны, и false если идентичны 
                                    // поэтому функция может быть использована как проверочное выражение
    cout << "You entered " << num <<" words.\n";    // вывод текстовой строки и количества введённых слов
    cin.get();
    cin.get();
    return 0;
}

