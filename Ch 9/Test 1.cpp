/*
a) Напишите класс Fraction, который имеет два целочисленных члена: числитель
и знаменатель. Реализуйте функцию print(), которая будет выводить дробь.

b) Добавьте перегрузку оператора умножения (*) для выполнения операции
умножения объекта класса Fraction на целочисленное значение и для перемножения
двух объектов класса Fraction. Используйте способ перегрузки оператора через
дружественную функцию.

c) Дробь 2/4 — это та же дробь, что и 1/2, только 1/2 не делится до минимальных
неделимыхзначений. Мы можем уменьшить любую заданную дробь до наименьших значений,
найдя наибольший общий делитель (НОД) для числителя и знаменателя, а затем
выполнить деление как числителя, так и знаменателя на НОД.
Добавьте эту функцию nod() в ваш класс и реализуйте метод reduce(), который будет
уменьшать дробь. Убедитесь, что дробь будет максимально и корректно уменьшена.
*/

#include <iostream>

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(int numerator = 0, int denominator = 1) :
        m_numerator(numerator), m_denominator(denominator)
    {
        reduce();
    }

    void print() const
    {
        std::cout << m_numerator << " / " << m_denominator << std::endl;
    }

     static int nod(int a, int b)
    {
        return (b == 0) ? (a > 0 ? a : -a) : nod(b, a % b);
    }

    void reduce()
    {
        int nod = Fraction::nod(m_numerator, m_denominator);
        m_numerator /= nod;
        m_denominator /= nod;
    }

    friend Fraction operator*(int value, const Fraction& v);
    friend Fraction operator*(const Fraction& v, int value);
    friend Fraction operator*(const Fraction& v1, const Fraction& v2);
};

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
    Fraction f1(3, 4);
    f1.print();

    Fraction f2(2, 7);
    f2.print();

    Fraction f3 = f1 * f2;
    f3.print();

    Fraction f4 = f1 * 3;
    f4.print();

    Fraction f5 = 3 * f2;
    f5.print();

    Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
    f6.print();

    return 0;
}