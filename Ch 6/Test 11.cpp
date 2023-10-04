/*
Объявите фиксированный массив со следующими именами: Sasha, Ivan, John,
Orlando, Leonardo, Nina, Anton и Molly. Попросите пользователя ввести имя.
Используйте цикл foreach для проверки того, не находится ли имя, введенное
пользователем, уже в массиве.
*/

#include <iostream>

int main()
{
    std::string names[] = { "Sasha", "Ivan", "John", "Orlando", "Leonardo", "Nina", "Anton", "Molly" };

    std::string getName;
    std::cout << "Enter a name: ";
    std::cin >> getName;

    bool found = false;

    for (const auto& name : names)
    {
        if (getName == name)
            found = true;
            break;
    }

    if (found)
        std::cout << getName << " was found.";
    else
        std::cout << getName << " was not found.";

    return 0;
}