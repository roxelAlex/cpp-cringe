/*
Реализуйте следующие два решения оптимизации алгоритма сортировки пузырьком,
который вы написали в предыдущем задании:
    Обратите внимание, с каждым выполнением сортировки пузырьком наибольшее
значения в массиве "пузырится" до конца. После первой итерации последний
элемент массива уже отсортирован. После второй итерации отсортирован
предпоследний элемент массива и т.д. С каждой новой итерацией нам не нужно
перепроверять элементы, которые уже были отсортированы. Измените свой цикл
соответствующим образом.
    Если на протяжении всей итерации не выполнится ни одной замены, то мы
знаем, что массив уже отсортирован. Внедрите проверку того, были ли сделаны
какие-либо замены в текущей итерации, и, если нет — завершите выполнение цикла.
Если цикл был завершен, то выведите информацию о том, на какой итерации
сортировка элементов завершилась.
*/

#include <iostream>
#include <algorithm>

int main()
{
    const int length(9);
    int array[length] = { 7, 5, 6, 4, 9, 8, 2, 1, 3 };

    // Проходимся по всей длине массива.
    for (int iteration = 0; iteration < length - 1; ++iteration)
    {
        int endOfArray = (length - iteration); // Следим, где заканчивается,
        // неотсортированный массив.

        bool swap = false; // Устанавливаем, что в начале цикла не произошло
        // сортировок в массиве.

        // Меняем элементы массива местами, если первый больше второго.
        for (int currentIndex = 0; currentIndex < endOfArray - 1; ++currentIndex)
        {
            if (array[currentIndex] > array[currentIndex + 1])
            {
                std::swap(array[currentIndex], array[currentIndex + 1]);
                swap = true; // Устанавливаем, что при итерации цикла 
                // была сортировка.
            }
        }
        // Если в течении одной итерации не было ни одной сортировки,
        // то выходим из всего цикла.
        if (!swap)
        {
            std::cout << "Early termination on iteration: " << iteration + 1 << std::endl;
            break;
        }
    }

    for (int index = 0; index < length; ++index)
    {
        std::cout << array[index] << " ";
    }
    return 0;
}