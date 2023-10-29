/*
Теперь попробуем что-то посложнее. Напишите класс, который реализует
функционал стека. Класс Stack должен иметь:
* закрытый целочисленный фиксированный массив длиной 10 элементов;
* закрытое целочисленное значение для отслеживания длины стека;
* открытый метод с именем reset(), который будет инициализировать значением
0 длину и все значения элементов;
* открытый метод с именем push(), который будет добавлять значение в стек.
Метод push() должен возвращать значение false, если массив уже заполнен, в
противном случае — true;
* открытый метод с именем pop() для возврата значений из стека. Если в стеке
нет значений, то должен выводиться стейтмент assert;
* открытый метод с именем print(), который будет выводить все значения стека.
*/

#include <iostream>
#include <cassert>

class Stack
{
private:
    int m_stack[10];
    int m_length;

public:
    void reset()
    {
        m_length = 0;

        for (int i = 0; i < 10; i++)
            m_stack[i] = 0;
    }

    bool push(int a)
    {
        if (m_length == 10)
            return false;
        
        m_stack[m_length] = a;

        m_length++;

        return true;
    }

    void pop()
    {
        assert(m_length > 0);

        m_length--;

        m_stack[m_length] = 0;

    }

    void print()
    {
        std::cout << "( ";
        for (int i = 0; i < 10; i++)
        {
            if (m_stack[i] != 0)
                std::cout << m_stack[i] << " ";
        }
        std::cout << ")\n";
    }
};

int main()
{
    Stack stack;
    stack.reset();

    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.print();

    return 0;
}