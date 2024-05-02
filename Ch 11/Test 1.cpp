/*
Реализуем наш пример с Фруктом, о котором мы говорили на уроке №161.
Создайте родительский класс Fruit, который имеет два закрытых члена: name
(std::string) и color (std::string). Создайте класс Apple, который наследует
свойства Fruit. У Apple должен быть дополнительный закрытый член:
fiber (тип double). Создайте класс Banana, который также наследует класс
Fruit. Banana не имеет дополнительных членов.
*/

#include <iostream>

class Fruit
{
    private:
        std::string m_name; // Имя фрукта
        std::string m_color;    // Цвет фрукта

    public:
        // Конструктор класс Fruit
        Fruit(std::string name, std::string color) :
            m_name(name), m_color(color)
        {

        }

        std::string getName() const { return m_name; }  // Возращаем имя
        std::string getColor() const    { return m_color; } // Возращаем цвет
};
// Дочерний класс Apple родителем является Fruit
class Apple : public Fruit
{
    private:
        double m_fiber; // Я хз что это для яблока, надо было по заданию
    
    public:
        // Конструктор класса Apple, который вызывает конструктор класса Fruit
        Apple(std::string name, std::string color, double fiber) :
            Fruit(name, color), m_fiber(fiber)
        {

        }

        double getFiber() const { return m_fiber; } // Возращаем значение
       
        // Перегружаем оператор вывода
        friend std::ostream& operator<< (std::ostream &out, const Apple &a);
};
// Дочерний класс Banana родителем является Fruit
class Banana : public Fruit
{
    public:
        // Конструктор класса Banana, который вызывает конструктор Fruit
        Banana(std::string name, std::string color) :
            Fruit(name, color)
        {

        }

    // Перегружаем оператор вывода
    friend std::ostream& operator<< (std::ostream &out, const Banana &b);
};
// Перегружаем оператор вывода
std::ostream& operator<< (std::ostream &out, const Apple &a)
{
    out << "Apple(" << a.getName() << ", " << a.getColor() << ", " << a.getFiber() <<
    ")" << std::endl;

    return out;
}
// Перегружаем оператор вывода
std::ostream& operator<< (std::ostream &out, const Banana &b)
{
    out << "Banana(" << b.getName() << ", " << b.getColor() << ")" << std::endl;

    return out;
}


int main()
{
    const Apple a("Red delicious", "red", 7.3);
    std::cout << a;

    const Banana b("Cavendish", "yellow");
    std:: cout << b;

    return 0;
}