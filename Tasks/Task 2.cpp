/*
Напишите программу, которая определяет минимальное число в последовательности 
положительных чисел, которую ввел пользователь. Если в последовательности есть отрицательные 
числа, то вы должны сообщить об этом пользователю и предложить повторить ввод еще раз.
*/

#include <iostream>
#include <array>
#include <algorithm>

int main()
{
    const int arraySize = 5;    // Размер массива будет 5.
    std::array<int, arraySize> userArray;   // Создаем массив.

    std::cout << "Please enter 5 numbers:\n";
    // В цикле заполняем массив запрашивая числа у пользователя.
    for(int i = 0; i < arraySize; i++)
    {
        do
        {
            std::cout << i + 1 << ": ";
            std::cin >> userArray[i];
            if(userArray[i] < 0)    // Если пользователь ввел отрицательное число
                std::cout << "Please enter the positive one.\n";    // просим его повторить
        }while(userArray[i] < 0);   // пока он не введет положительное
    }
    
    std::sort(userArray.begin(), userArray.end());  // Сортируем массив по возврастанию

    // Так как массив отсортирован по возрастанию, то выводим 0 индекс массива, потому что
    // он является минимальным в массиве.
    std::cout << userArray[0] << " is the minimun number in your sequence.";

    return 0;
}