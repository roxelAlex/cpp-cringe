/*
Используя массив из задания №1:
Попросите пользователя ввести число от 1 до 9. Если пользователь введет
что-либо другое — попросите его снова ввести число и так до тех пор,
пока он не введет корректное значение из заданного диапазона.
Как только пользователь введет число от 1 до 9, выведите массив на экран.
Затем найдите в массиве элемент с числом, которое ввел пользователь, и
выведите его индекс.
*/

#include <iostream>

int getUserNumber()
{
    int userNumber = 0;
    do
    {
        std::cout << "Enter the number from 1 to 9: ";
        std::cin >> userNumber;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
    } while (userNumber == 0 || userNumber > 9);
    return userNumber;
}

int main()
{
    int array[] = { 7, 5, 6, 4, 9, 8, 2, 1, 3 };
    const int arraySize = sizeof(array) / sizeof(array[0]);
    int userNumber = getUserNumber();

    for (int count = 0; count < arraySize; count++)
    {
        std::cout << "Element #" << count << " of array is " << array[count] << std::endl;
    }

    for (int count = 0; count < arraySize; count++)
    {
        if (userNumber == array[count])
            std::cout << "Index of your number is " << count;
    }
    return 0;
}