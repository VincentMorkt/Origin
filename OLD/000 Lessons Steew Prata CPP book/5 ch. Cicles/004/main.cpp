/*Дафна инвестировала $100 под простые 10%. Другими словами, ежегодно инвестиция должна приносить 
10% инвестированной суммы, т.е. $10 каждый год: прибыль = 0,10 х исходный баланс.
В то же время Клео инвестировала $100 под сложные 5%. Это значит, что прибьль составит 5% от текущего баланса, 
включая предыдущую накопленную прибьmь: прибыль = 0,05 х текущий баланс.
Клео зарабатывает 5% от $100 в первый год, что дает ей $105. 
На следующий год она зарабатывает 5% от $105, что составляет $5.25, и т.д. 
Напишите программу, которая вычислит, сколько лет понадобится для того, чтобы сумма баланса Клео превысила сумму баланса Дафны, 
с отображением значений обоих балансов за каждый год. */

#include <iostream>
int main ()
{   
    const double StartDeposit = 100;     // объявление констант, необходимых для расчётов. Константы отражают стартовое значение для обоих депозитов, а также коэфициенты роста.
    const double DafnaInterest = 0.1;   
    const double KleoInterest = 0.05;
    double dafnaDeposit = StartDeposit, kleoDeposit = StartDeposit; // объявление переменных, отражающих состояние депозитов. Переменные инициализированны значением нулевого года.
    int year=0;                         // объявление переменной, отражающей год, для подсчёта шагов цикла и вывода этого значения на экран
    std::cout << "\tYear \t | Dafna deposit |  Kleo deposit" << std::endl;  // вывод строки, которая является заголовком таблицы
    std::cout << "\t "<< year <<"\t\t" << dafnaDeposit <<"\t\t" << kleoDeposit << std::endl;    // вывод значений нулевого года 
    while (dafnaDeposit>=kleoDeposit)   // объявление цикла while. 
    {
        year++;                         // я не стал использовать for и помещать год в обновляющее выражение, поскольку он не связан с проверочным
        dafnaDeposit += StartDeposit*DafnaInterest; // расчёт состояния депозита Дафны
        kleoDeposit += kleoDeposit*KleoInterest;    // расчёт состояния депозита Клео
        std::cout <<"\t " << year <<"\t\t" << dafnaDeposit <<"\t\t" << kleoDeposit << std::endl;// вывод на экран года и состояний депозитов. 
        // Вывод на экран сделан после расчётов, чтобы включить данные за год, в котором депозит Клео превысит депозит Дафны, после чего цикл будет прерван.
    };  // Похоже, нет простого способа вывести значения нулевого года и последнего года внутри цикла, и приходится выносить одну из этих строк за цикл. 
    std::cin.get(); 
    return 0;
}