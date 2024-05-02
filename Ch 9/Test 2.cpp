/*
Используя класс Fraction, представленный ниже, добавьте перегрузку операторов << и >>.
*/

#include <iostream>

// Класс Fraction
class Fraction
{
private:
    int m_numerator; // Числитель
    int m_denominator; // Знаменатель

public:

    // Конструктор класса, с методом сокращения дроби
    Fraction(int numerator = 0, int denominator = 1) :
        m_numerator(numerator), m_denominator(denominator)
    {
        reduce();
    }

    // Метод вывода дроби на экран
    void print() const
 
    {
        std::cout << m_numerator << " / " << m_denominator << std::endl;
    }

    // Статический метод поиска наибольшего общего знаменателя
     static int nod(int a, int b)
    {
        return (b == 0) ? (a > 0 ? a : -a) : nod(b, a % b);
    }

    // Метод для сокращения дроби
    void reduce()
    {
        int nod = Fraction::nod(m_numerator, m_denominator);
        m_numerator /= nod;
        m_denominator /= nod;
    }

    // Прототипы перегрузки оператора *
    friend Fraction operator*(int value, const Fraction& v);
    friend Fraction operator*(const Fraction& v, int value);
    friend Fraction operator*(const Fraction& v1, const Fraction& v2);

    // Прототипы перегрузки операторов ввода и вывода
    friend std::ostream& operator<<(std::ostream& out, const Fraction &fraction);
    friend std::istream& operator>>(std::istream& in, Fraction &fraction);

};

// Перегружаем оператор вывода
std::ostream& operator<< (std::ostream &out, const Fraction &fraction)
{
    out << fraction.m_numerator << " / " << fraction.m_denominator;
    return out;
}

// Перегружаем оператор ввода
std::istream& operator>> (std::istream &in, Fraction &fraction)
{
    char c;
    in >> fraction.m_numerator;
    in >> c;
    in >> fraction.m_denominator;

    fraction.reduce();

    return in;
}

// Перегружаем операторы умножения
Fraction operator*(const Fraction& v1, const Fraction& v2)
{
    return Fraction(v1.m_numerator * v2.m_numerator, v1.m_denominator * v2.m_denominator);
}

Fraction operator*(int value, const Fraction& v)
{
    return Fraction(value * v.m_numerator, v.m_denominator);
}

Fraction operator*(const Fraction& v, int value)
{
    return Fraction(value * v.m_numerator, v.m_denominator);
}

int main()
{
    Fraction f1;
    std::cout << "Enter fraction 1: ";
    std::cin >> f1;

    Fraction f2;
    std::cout << "Enter fraction 2: ";
    std::cin >> f2;

    std::cout << f1 << " * " << f2 << " is " << f1 * f2 << std::endl;

    return 0;
}