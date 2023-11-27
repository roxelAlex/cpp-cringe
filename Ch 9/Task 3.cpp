/*
Значение типа с плавающей точкой — это число с десятичной дробью, где
количество цифр после точки (дробная часть) может меняться. Значение типа с
фиксированной точкой — это число с дробью, где дробь (после точки)
фиксированная.

Вам нужно написать класс для реализации значений типа с фиксированной точкой
с двумя цифрами после точки (например, 11.47, 5.00 или 1465.78).
Диапазон класса должен быть от -32768.99 до 32767.99, в дробной части могут
быть любые две цифры, не допускайте проблем с точностью.
a) Какого типа данных переменную-член следует использовать для реализации
значений типа с фиксированной точкой с 2-мя цифрами после точки? (Обязательно
прочитайте ответ, прежде чем приступать к выполнению следующего задания)
b) Напишите класс FixedPoint, который реализует рекомендуемое решение из
предыдущего задания. Если дробная или целая части значения являются
отрицательными, то число должно рассматриваться, как отрицательное.
Реализуйте перегрузку необходимых операторов и напишите необходимые
конструкторы.
c) Теперь добавьте конструктор, который будет принимать значение типа double.
Вы можете округлить целую часть (слева от точки) с помощью функции round()
(которая находится в заголовочном файле cmath).
d) Выполните перегрузку следующих операторов: ==, >>, − (унарный) и
+ (бинарный).
*/

#include <iostream>
#include <cmath>

class FixedPoint
{
    private:
        int16_t m_integer;  // Целая часть
        int8_t m_fraction;  // Дробная часть

    public:
        // Конструктор
        FixedPoint(int16_t integer, int8_t fraction)
        {
            m_integer = integer;
            m_fraction = fraction;

            // Если дробная часть больше 99
            if(m_fraction > 99)
            {
                m_fraction -= 100; // То выравниваем дробную часть
                m_integer++;    // Увеличиваем на единицу целую часть
            }
            
            // Если дробная часть меньше -99
            if(m_fraction < -99)
            {
                m_fraction += 100; // То выравниваем дробную часть
                m_integer--;    // Уменьшаем на единицу целую часть
            }

            // Если целая или дробная части отрицательные
            if(m_integer < 0.0 || m_fraction < 0.0)
            {
                // Проверяем целую часть
                if(m_integer > 0.0)
                   m_integer = -m_integer;
                // Проверяем дробную часть
                if(m_fraction > 0.0)
                   m_fraction = -m_fraction;
            }
        }
        // Конструктор, который принимает число типа double
        FixedPoint(double num)
        {
            m_integer = static_cast<int16_t>(num);  // Выделяем целую часть из дроби
            // Выделяем дробную часть из дроби:
            // 1. Вычитаем из дроби целую часть
            // 2. Умножаем число на 100, чтобы сдвинуть запятую на две цифры влево
            // 3. Округляем число при помощи функции round()
            // 4. Явно приводим к типу int8_t
            m_fraction = static_cast<int8_t>(round((num - m_integer) * 100));
        }

        // Перегружаем оператор преобразования в тип double
        operator double() const
        {
            return m_integer + static_cast<double>(m_fraction) / 100;
        }

        // Перегружаем оператор вывода
        friend std::ostream& operator<< (std::ostream &out, FixedPoint &point)
        {
            out << static_cast<double>(point);
            return out;
        }

        // Перегружаем оператор ввода
        friend std::istream& operator>> (std::istream &in, FixedPoint &point)
        {
            double d;
            in >> d;
            point = FixedPoint(d);  // Создаем анонимный объект, чтобы отработали
                                    // все необходимые конструкторы

            return in;
        }
        // Перегружаем оператор + бинарный
        friend FixedPoint operator+ (const FixedPoint &p1, const FixedPoint &p2);
        // Перегружаем оператор сранения ==
        friend bool operator== (const FixedPoint &p1, const FixedPoint &p2);
        // Перегружаем унарный -
        FixedPoint operator- () const
        {
            return FixedPoint(-m_integer, -m_fraction);
        }
};

FixedPoint operator+(const FixedPoint &p1, const FixedPoint &p2)
{   
    // Складываем два объекта явно приводя их к типу double
    return FixedPoint(static_cast<double>(p1) + static_cast<double>(p2));
}

bool operator== (const FixedPoint &p1, const FixedPoint &p2)
{   
    // Сравниваем сначала целую часть обоих объектов, затем дробные части
    return (p1.m_integer == p2.m_integer &&
            p1.m_fraction == p2.m_fraction);
}

void SomeTest()
{
    std::cout << std::boolalpha;

    std::cout << (FixedPoint(0.75) + FixedPoint(1.23) == FixedPoint(1.98)) <<
    std::endl;

    std::cout << (FixedPoint(0.75) + FixedPoint(1.50) == FixedPoint(2.25)) <<
    std::endl;

    std::cout << (FixedPoint(-0.75) + FixedPoint(-1.23) == FixedPoint(-1.98)) <<
    std::endl;

    std::cout << (FixedPoint(-0.75) + FixedPoint(-1.50) == FixedPoint(-2.25)) <<
    std::endl;

    std::cout << (FixedPoint(0.75) + FixedPoint(-1.23) == FixedPoint(-0.48)) <<
    std::endl;

    std::cout << (FixedPoint(0.75) + FixedPoint(-1.50) == FixedPoint(-0.75)) <<
    std::endl;

    std::cout << (FixedPoint(-0.75) + FixedPoint(1.23) == FixedPoint(0.48)) <<
    std::endl;

    std::cout << (FixedPoint(-0.75) + FixedPoint(1.50) == FixedPoint(0.75)) <<
    std::endl;
}

int main()
{
    SomeTest();

    FixedPoint a1(-0.48);
    std::cout << a1 << std::endl;

    std::cout << -a1 << std::endl;

    std::cout << "Enter a number: ";
    std::cin >> a1;

    std::cout << "You entered: " << a1 << std::endl; 

    return 0;
}