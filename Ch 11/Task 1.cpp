#include <iostream>

class Fruit
{
    private:
        std::string m_name; // Название фрукта
        std::string m_color;    // Его цвет
    
    public:
    // Конструктор класса
    Fruit(std::string name, std::string color):
        m_name(name), m_color(color)
        {

        }

    std::string getName()   { return m_name; }  // Геттер названия фрукта
    std::string getColor()  { return m_color; } // Геттер его цвета
};

// Дочерний класс Apple, родитель Fruit
class Apple : public Fruit
{     
    public:
        // Конструктор, который принимает цвет фрукта, но в конструктор Fruit
        // по умолчанию передается название apple
        Apple(std::string color = "red")
            : Fruit("apple", color)
        {

        }
        // Второй конструктор класса который принимает оба значения
        Apple(std::string name, std::string color)
            : Fruit(name, color)
            {

            }
};

// Дочерний класс Banana, родительский Fruit
class Banana : public Fruit
{   
    // Конструктор класса, который передает два значения по умолчанию
    // в родительский конструктор
    public:
        Banana(): Fruit("banana", "yellow")
        {

        }
};

// Дочерний класс GrannySmith, родительский Apple
class GrannySmith : public Apple
{
    // Конструктор, который передает в родительский конструктор Apple два
    // предустановленных значения
    public:
        GrannySmith() : Apple("Granny Smith apple", "green")
    {
        
    }
};

int main()
{
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}