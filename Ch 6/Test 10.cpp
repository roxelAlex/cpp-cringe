/*
Напишите программу, которая:
    спрашивает у пользователя, сколько имен он хочет ввести;
    просит пользователя ввести каждое имя;
    вызывает функцию для сортировки имен в алфавитном порядке;
    выводит отсортированный список имен.
*/

#include <iostream>
#include <algorithm>

// Сортируем массив методом пузырька в порядке возрастания (алфавитном)
void sortArray(std::string *array, int length)
{
    for (int iteration = 0; iteration < length - 1; iteration++)
    {
        int endOfArray = length - iteration;
        bool swap = false;
        for (int currentIndex = 0; currentIndex < endOfArray - 1; currentIndex++)
        {
            if (array[currentIndex] > array[currentIndex + 1])
            {
                std::swap(array[currentIndex], array[currentIndex + 1]);
                swap = true;
            }
        }
        if (!swap)
        {
            break;
        }
    }
}

int main()
{
    // Запрашиваем у пользователя сколько имен он хочет ввести, чтобы определить
    // размер необходимого массива.
    std::cout << "How many names would you like to enter? ";
    int length;
    std::cin >> length;

    // Создаем динамический массив для хранения имен.
    std::string *names = new std::string[length];

    // Заполянем этот массив именами запрашивая их пользователя.
    for (int count = 0; count < length; count++)
    {
        std::cout << "Enter name #" << count + 1 << ": ";
        std::cin >> names[count];
    }
    
    // Передаем массив с именами и длину массива для сортировки.
    sortArray(names, length);

    // Выводим отсортированный массив на экран.
    std::cout << "Here is your sorted list:" << std::endl;
    for (int count = 0; count < length; count++)
    {
        std::cout << "Name #" << count << ": " << names[count] << std::endl;
    }

    // Освобождаем динамически выделенную память и создаем нулевой указатель.
    delete[] names;
    names = nullptr;

    return 0;
}