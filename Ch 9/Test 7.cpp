/*
Напишите класс, переменной-членом которого является строка.
Перегрузите оператор () для возврата подстроки, которая начинается с
индекса, указанного в значении первого параметра. Второй параметр должен
указывать требуемую длину подстроки.
*/

#include <iostream>
#include <string>

class Mystring
{
private:
    std::string m_string;

public:
    // Конструктор
    Mystring(std::string string = "")
    {
        m_string = string;
    }

    // Перегружаем оператор ()
    std::string operator()(int index, int length)
    {
        std::string temp; // Вводим временную переменую
        while (length > 0) // Пока длина подстроки не равна 0
        {
            temp += m_string[index++]; // Присваимваем во временную переменную
                                       // символы из искомой подстроки
            length--;   // Уменьшаем длину подстроки на единицу
        }
        return temp;    // Возвращаем получившуюся подстроку
    }
};

int main()
{
    Mystring string("Hello, world!");
    std::cout << string(7, 6);  //Вывод вызова будет world!

    return 0;
}