/*
Создайте класс Numbers, который содержит два целых числа. Этот класс
должен иметь две переменные-члены для хранения этих двух целых чисел.
Вы также должны создать два метода:
* метод set(), который позволит присваивать значения переменным;
* метод print(), который будет выводить значения переменных.
*/

#include <iostream>

class Numbers
{
    public:
        int m_first;
        int m_second;

        void set(int a, int b)
        {
            m_first = a;
            m_second = b;
        }

        void print()
        {
            std::cout << "Numbers(" << m_first << ", " << m_second << ")";
        }
};

int main()
{
    Numbers n1;
    n1.set(3, 3);

    Numbers n2 {4, 4};

    n1.print();
    n2.print();

    return 0;
}