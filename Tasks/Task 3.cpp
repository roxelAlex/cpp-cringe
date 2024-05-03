/*
Напишите программу, которая запрашивает у пользователя номер месяца и затем выводит 
соответствующее название времени года. В случае, если пользователь введет недопустимое 
число, программа должна вывести сообщение об ошибке.

Пример результата выполнения программы:

Введите номер месяца (число от 1 до 12): 12
Зима
*/

#include <iostream>

int main()
{
    unsigned int mounth; // Переменная для хранения номера месяца

    do  // В цикле запрашиваем номер месяца
    {
        std::cout << "Enter the number of mounth:\n";
        std::cin >> mounth;
    } while(mounth < 1 || mounth > 12); // для того, чтобы пользователь ввел только верное число

    switch(mounth)  // При помощи свича выдаем название времени года
    {
        case 12:
        case 1:
        case 2: 
        {
            std::cout << "Winter.";
            break;
        }
        case 3:
        case 4:
        case 5:
        {
            std::cout << "Spring";
            break;
        }
        case 6:
        case 7:
        case 8:
        {
            std::cout << "Summer";
            break;
        }
        case 9:
        case 10:
        case 11:
        {
            std::cout << "Fall";
            break;
        }
    }
    return 0;
}