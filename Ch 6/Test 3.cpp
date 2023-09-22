/*
Выведите на экран следующий массив с помощью цикла:
    int array[] = { 7, 5, 6, 4, 9, 8, 2, 1, 3 };
*/

#include <iostream>

int main()
{
    int array[] = {7, 5, 6, 4, 9, 8, 2, 1, 3};
    const int arraySize = sizeof(array) / sizeof(array[0]);

    for (int count = 0; count < arraySize; count++)
    {
        std::cout << "Element #" << count << " of array is " << array[count] << std::endl;
    }
    return 0;
}