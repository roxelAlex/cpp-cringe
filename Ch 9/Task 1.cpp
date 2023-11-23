/*
Напишите класс Average, который будет вычислять среднее значение всех
передаваемых ему целых чисел. Используйте два члена: первый должен быть
типа int32_t и использоваться для вычисления суммы всех передаваемых чисел,
второй должен быть типа int8_t и использоваться для вычисления количества
передаваемых чисел. Чтобы найти среднее значение, нужно разделить сумму на
количество.
*/

#include <iostream>

class Average
{
    private:
        int32_t m_sum;  // Сумма чисел
        int8_t m_count; // Количество чисел

    public:
        // Конструктор
        Average(int32_t sum = 0, int8_t count = 0) :
        m_sum(sum), m_count(count)
        {

        }
        // Перегружаем оператор +=, в качестве возвращаемого объекта используем
        // ссылку на объект класса, чтобы можно было выполнять цепочки операций
        Average& operator+=(int add)
        {
            m_sum = m_sum + add;    // вычисляем сумму чисел
            m_count++;  // инкрементируем счетчик количества чисел

            return *this;   // возвращаем объект класса
        }

        // делаем функцию перегрузки оператора вывода дружественной классу
        friend std::ostream& operator<< (std::ostream &out, const Average &a);
};

// Перегружаем оператор вывода
std::ostream& operator<< (std::ostream &out, const Average &a)
{
    out << a.m_sum / a.m_count; // находим среднее значение

    return out;
}

int main()
{
    Average avg;

    avg += 5;
    std::cout << avg << "\n";

    avg += 9;
    std::cout << avg << "\n";

    avg += 19;
    std::cout << avg << "\n";

    avg += -9;
    std::cout << avg << "\n";

    (avg += 7) += 11;
    std::cout << avg << "\n";

    Average copy = avg;
    std::cout << copy << "\n";

    return 0;
}