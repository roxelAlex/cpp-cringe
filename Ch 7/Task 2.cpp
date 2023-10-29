/*
Лучшим алгоритмом определения того, существует ли значение в отсортированном
массиве или нет, является бинарный поиск.
Бинарный поиск работает следующим образом:
* Смотрим на центральный элемент массива.
* Если центральный элемент массива больше элемента, который мы ищем, то всё,
что находится справа от центрального элемента — отбрасываем.
* Если центральный элемент меньше элемента, который мы ищем, то отбрасываем
всё, что находится слева от центрального элемента.
* Если центральный элемент равен элементу, который мы ищем, то возвращаем
индекс этого элемента.
* Если перебрали весь массив и не нашли искомого значения, то возвращаем
контрольное значение с выводом not found.

(a) Напишите итеративную версию функции binarySearch().
(b) Напишите рекурсивную версию функции binarySearch().
*/

#include <iostream>

int binarySearch(int* array, int target, int min, int max)
{
    while (min <= max)
    {
        int mid = min + ((max - min) / 2);

        if (array[mid] > target)
            max = mid - 1;
        else if (array[mid] < target)
            min = mid + 1;
        else
            return mid;
    }
    return -1;
}

int binarySearchRecursion(int* array, int target, int min, int max)
{
    if (min > max)
        return -1;

    int mid = min + ((max - min) / 2);

    if (array[mid] > target)
        return binarySearchRecursion(array, target, min, mid - 1);
    else if (array[mid] < target)
        return binarySearchRecursion(array, target, mid + 1, max);
    else return mid;
}

int main()
{
    int array[] = { 4, 7, 9, 13, 15, 19, 22, 24, 28, 33, 37, 41, 43, 47, 50 };

    std::cout << "Enter a number: ";
    int x;
    std::cin >> x;

    int index = binarySearch(array, x, 0, 14);
    int indexRecursion = binarySearchRecursion(array, x, 0, 14);


    if (array[index] == x)
        std::cout << "Good! Your value " << x << " is on position " << index <<
        " in array!\n";
    else
        std::cout << "Fail! Your value " << x << " isn't in array!\n";

    if (array[indexRecursion] == x)
        std::cout << "Good! Your value " << x << " is on position " << index <<
        " in array!\n";
    else
        std::cout << "Fail! Your value " << x << " isn't in array!\n";
    return 0;
}