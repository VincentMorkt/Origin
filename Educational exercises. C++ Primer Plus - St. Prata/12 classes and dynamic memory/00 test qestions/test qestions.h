// 1. Пусть класс String содержит следующие закрытые члены:
// class String
// {
// private:
//     char *str; // указывает на строку, распределенную операцией new
//     int len;   // хранит длину строки
//...
// };

// а. Что неправильно в следующем конструкторе по умолчанию?
// String::String() {}
// в этом конструкторе нет ничего, что должен делать конструктор. Объект будет хранить мусор, и память для str не будет выделена
// необходимо инициализировать указатель операцией new или NULL

// б. Что неправильно в следующем конструкторе?
// String::String(const char *s)
// {
//     str = s;
//     len = strlen(s);
// }
// конструктор не создаёт новую строку, а копирует адрес существующей.

// в.Что неправильно в следующем конструкторе ?
// String::String(const char *s)
// {
//     strcpy(str, s);
//     len = strlen(s);
// }
// конструктор не выделяет память для хранения скопированной строки

// 2. Назовите три проблемы, которые могут возникнуть при определении класса,
// в котором указатель-член инициализируется с помощью операции new.
// Укажите, как их можно устранить.
// Все проблемы связаны с созданием автоматических конструкторов копирования, присваивания и деструктора, что приводит к
// 1. отсутсвию необходимого освобождения памяти
// 2. лишним попыткам освободить уже освобождённую память
// 3. ситуациям, когда два указателя указывают на один и тот же объект
// Эти проблемы можно утранить, обеспечив класс соответствующими корректными конструкторами и деструкторами.

// 3. Какие методы класса компилятор генерирует автоматически, если они не представлены явно? Опишите, как ведут себя эти неявно сгенерированные функции.
// 1. Конструктор по умолчанию, Имя_Класса() {}, не делает ничего
// 2. Деструктор по умолчанию, ~Имя_Класса() {}, и также не делает ничего
// 3. Конструктор копирования,  Имя_Класса(const Имя_Классса &) { выполняет почленное присваивание нестатических членов }
// 4. Операция присваивания, Имя_Класса &Имя_Класса::operator=(const Имя_Класса &) { выполняет почленное присваивание нестатических членов }
// 5. Операция взятия адреса, Имя_Класса &Имя_Класса::operator*() { return this; }

// 4. Найдите и исправьте ошибки в следующем объявлении класса:
#include <iostream>
#include <cstring>
class nifty
{
    // Данные
private:               // отсутствовали слова private и public. Если с private это не критично, все члены классов приватны по умолчанию, то для методов необходимо указать их открытость
    char *personality; // судя по методам personality должен быть указателем на char;
    int talents;
    // Методы
public:
    nifty();
    nifty(char *s);
    friend std::ostream &operator<<(std::ostream &os, const nifty &n); // нужно включить имя ostream в область видимости.
    // метод должен быть friend-функцией
    // необходимо добавить конструкторы копирования и присваивания и деструктор
    ~nifty() { delete[] personality; }
    nifty(const nifty &n);
    nifty &operator=(const nifty &n);
};
nifty::nifty() // операция разрешения контекста выглядит как два двоеточия ::
{
    personality = NULL; //
    talents = 0;
}

nifty::nifty(char *s)
{
    personality = new char[strlen(s) + 1]; // необходимо доабавить + 1 для нулевого символа в конце строки
    strcpy(personality, s);                // для копирования необходима функция strcpy из файла cstring
    talents = 0;
}

std::ostream &operator<<(std::ostream &os, const nifty &n) // nifty:: лишнее, это дружественная функция
{
    using std::endl;
    os << "personality: " << n.personality << endl
       << "talents: " << n.talents << endl;
    return os;
}

nifty::nifty(const nifty &n)
{
    personality = new char[strlen(n.personality) + 1];
    strcpy(personality, n.personality);
    talents = n.talents;
}

nifty &nifty::operator=(const nifty &n)
{
    if (this == &n)
        return *this;
    delete[] personality;
    personality = new char[strlen(n.personality) + 1];
    strcpy(personality, n.personality);
    talents = n.talents;
    return *this;
}

// 5. Имеется следующее объявление класса:
class Golfer
{
private:
    char *fullname; // указывает на строку, содержащую имя игрока в гольф
    int games;      // хранит количество сыгранных игр
    int *scores;    // указывает на первый элемент массива счетов игр
public:
    Golfer();
    Golfer(const char *name, int g = 0);
    // Создает пустой динамический массив из g элементов, если g > 0
    Golfer(const Golfer &g);
    ~Golfer();
};

// а. Какие методы класса будут вызываться следующими операторами?
// int main()
// {
//     Golfer nancy;                      // конструктор по умолчанию Golfer();
//     Golfer lulu("Li ttle Lulu");       // конструктор Golfer(const char *name, int g = 0);
//     Golfer roy("Roy Hobbs ", 12);      // конструктор Golfer(const char *name, int g = 0);
//     Golfer *par = new Golfer;          // конструктор по умолчанию Golfer();
//     Golfer next = lulu;                // конструктор Golfer(const Golfer &g); затем операция присваивания по умолчанию
//     Golfer hazzard = "Weed Thwa cker"; // конструктор конструктор Golfer(const char *name, int g = 0); затем операция присваивания по умолчанию
//     *par = nancy;                      // операция присваивания по умолчанию
//     nancy = "Nancy Putter";            // конструктор конструктор Golfer(const char *name, int g = 0); для преобразования типа, а после автоматическая перегруженная операция присваивания
// }
// б. Ясно, что классу требуется больше методов для того, чтобы он был действительно полезным.
// Какой дополнительный метод нужен для защиты данных от разрушения?
// классу необходима операция присваивания, которая выполняет глубокое копирование (копирует данные, а не адреса, на которые те указывают)