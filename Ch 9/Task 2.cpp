/*
Напишите свой собственный класс-массив целых чисел IntArray
(не используйте std::array или std::vector). Пользователи должны передавать
размер массива при создании объекта этого класса, а сам массив
(переменная-член) должен выделяться динамически. Используйте стейтменты
assert для проверки передаваемых значений, а также свой конструктор
копирования и перегрузку оператора присваивания, если это необходимо.
*/

#include <iostream>
#include <cassert>

class IntArray
{
    private:
        int *m_array;   // Указатель на массив
        int m_length;   // Длина массива
    
    public:
        // Конструктор класса
        IntArray(int length)
        {
            // Длина массива должна быть положительным числом
            assert(length > 0 && "IntArray length should be a positive integer");
            m_length = length;  // Устанавливаем длину масива
            m_array = new int[m_length];    // Выделяем динамически память
                                            // под массив
        }
        // Деструктор класса
        ~IntArray()
        {
            delete[] m_array;
        }
        // Копирующий конструктор
        IntArray(const IntArray& source)
        {
            m_length = source.m_length; // Копируем длину массива

            m_array = new int[m_length];    // Создаем новый массив
     
            for(int i = 0; i < m_length; i++)
            {
                m_array[i] = source.m_array[i]; // Копируем в новый массив
                                                // значения
            }
        }
        // Перегужаем оператор присваивания с глубоким копированием
        IntArray operator= (const IntArray& source)
        {   
            // Проверка на самоприсваивание
            if(this == &source)
                return *this;

            delete[] m_array; // Удаляем массив

            m_length = source.m_length; // Копируем длину массива

            m_array = new int[m_length];    // Создаем новый массив

            for(int i = 0; i < m_length; i++)
                m_array[i] = source.m_array[i]; // Копируем в новый массив
                                                // значения

            return *this; // Возвращаем объект
        }
        // Перегружаем оператор вывода
        friend std::ostream& operator<< (std::ostream &out, const IntArray &array)
        {
            // При помощи цикла выводим каждое значение массива на экран
            for (int i = 0; i < array.m_length; i++) 
            {
                out << array.m_array[i] << ' ';
            }

        return out;
        }
        // Перегружаем оператор индексации
        int& operator[] (const int index)
        {
            assert(index >= 0);
            assert(index < m_length);
            return m_array[index];
        }
};

IntArray fillArray()
{
    IntArray a(6);
    a[0] = 6;
    a[1] = 7;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;
    a[5] = 8;

    return a;
}

int main()
{
    IntArray a = fillArray();
    std::cout << a << "\n";

    IntArray b(1);
    a = a;
    b = a;

    std::cout << b << '\n';

    return 0;
}