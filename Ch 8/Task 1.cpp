/*
a) Напишите класс с именем Point. В классе Point должны быть две
переменные-члены типа double: m_a и m_b со значениями по умолчанию 0.0.
Напишите конструктор для этого класса и функцию вывода print().

b) Теперь добавим метод distanceTo(), который будет принимать второй объект
класса Point в качестве параметра и будет вычислять расстояние между двумя
объектами. Учитывая две точки (a1, b1) и (a2, b2), расстояние между
ними можно вычислить следующим образом:
sqrt((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2)).
Функция sqrt находится в заголовочном файле cmath.

c) Измените функцию distanceTo() из метода класса в дружественную функцию,
которая будет принимать два объекта класса Point в качестве параметров.
Переименуйте эту функцию на distanceFrom().
*/

#include <iostream>
#include <cmath>

// Создаем класс Point
class Point
{
    // Указываем, что в классе будет две переменные, которые по умолчанию
    // равны 0.
private:
    double m_a = 0;
    double m_b = 0;

public:
    // Конструктор по умолчанию, чтобы переменные могли инициализироваться
    // с 0 по умолчанию.
    Point()
    {

    }
    // Создаем конструктор для присваивания значений.
    Point(double a, double b)
    {
        m_a = a;
        m_b = b;
    }

    // Метод print() будет выводить значения переменных объекта на экран.
    void print()
    {
        std::cout << "Point (" << m_a << ", " << m_b << ")\n";
    }

    // Метод distanceTo() принимает в качестве параметра второй объект и
    // вычисляет расстояние между двумя объектами.
    double distanceTo(Point &a)
    {
        return sqrt((m_a - a.m_a) * (m_a - a.m_a) + (m_b - a.m_b) * (m_b - a.m_b));
    }

    // Указываем, что функция distanceFrom() будет дружественная классу Point.
    friend double distanceFrom(Point &first, Point &second);
};

// Функция distanceFrom() делает то же самое, что и метод distanceTo(), но
// принимает в качестве параметра два объекта класса Point. 
double distanceFrom(Point &first, Point &second)
{
    return sqrt((first.m_a - second.m_a) * (first.m_a - second.m_a) + 
    (first.m_b - second.m_b) * (first.m_b - second.m_b));
}

int main()
{
    Point first;
    Point second(2.0, 5.0);

    first.print();
    second.print();

    std::cout << "Distance between two points: " << first.distanceTo(second) 
    << "\n";

    std::cout << "Distance between two points: " << distanceFrom(first, second) 
    << "\n";

    return 0;
}