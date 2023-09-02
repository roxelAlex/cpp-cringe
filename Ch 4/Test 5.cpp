/*
У вас есть веб-сайт и вы хотите отслеживать, сколько денег вы зарабатываете
в день от размещенной на нем рекламы. Объявите структуру Advertising,
которая будет отслеживать:
 сколько объявлений вы показали посетителям (1);
 сколько процентов посетителей нажали на объявления (2);
 сколько вы заработали в среднем за каждое нажатие на объявления (3).
Значения этих трех полей должен вводить пользователь.
Передайте структуру Advertising в функцию, которая выведет каждое из этих
значений, а затем подсчитает, сколько всего денег вы заработали за день
(перемножьте все 3 поля).
*/

#include <iostream>

struct Advertising
{
    int howMuchAdv; // Сколько было показов рекламы
    double howManyPress; // Сколько людей перешло в процентах
    double salary; // Заработок с одного перехода
};

void printInfo(Advertising adv)
{
    std::cout << "Количество показанной рекламы: " << adv.howMuchAdv << std::endl;
    std::cout << "Процент перехода по рекламе: " << adv.howManyPress << std::endl;
    std::cout << "Стоимость одного перехода: " << adv.salary << std::endl;

    // Здесь я готовое число делю на 100, хотя нужно введеное пользователем
    // процент делить на 100 - результат выходит один и тот же
    double result = (adv.howMuchAdv * adv.howManyPress * adv.salary) / 100;

    std::cout << "Всего вы заработали: " << result << std::endl;
}

int main()
{
    setlocale(LC_ALL, "rus");

    Advertising advertising;

    std::cout << "Введите количество показов рекламы: ";
    std::cin >> advertising.howMuchAdv;

    std::cout << "Введите процент перехода по рекламе: ";
    std::cin >> advertising.howManyPress;

    std::cout << "Введите стоимость одного перехода: ";
    std::cin >> advertising.salary;

    printInfo(advertising);
    return 0;
}