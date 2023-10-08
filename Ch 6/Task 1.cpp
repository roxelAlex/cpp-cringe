/*
Представьте, что вы пишете игру, в которой игрок может иметь 3 типа предметов:
зелья здоровья, факелы и стрелы. Создайте перечисление с этими типами
предметов и фиксированный массив для хранения количества каждого типа
предметов, которое имеет при себе игрок (используйте стандартные фиксированные
массивы, а не std::array). У вашего игрока должны быть при себе
3 зелья здоровья, 6 факелов и 12 стрел.
Напишите функцию countTotalItems(), которая возвращает общее количество
предметов, которые есть у игрока. В функции main() выведите
результат работы функции countTotalItems().
*/

#include <iostream>

namespace Item
{
    enum Item
    {
        HEALINGPOTION,
        TORCH,
        ARROW,
        MAX_ITEMS,
    };
}

int countTotalItems(int *array)
{
    int sumOfItems = 0;
    for(int index = 0; index < Item::MAX_ITEMS; index++)
        sumOfItems += array[index];

    return sumOfItems;
}

int main()
{
    int inventory[Item::MAX_ITEMS] = {3, 6, 12};

    std::cout << "You have " << countTotalItems(inventory) << " items, in your inventory.";

    return 0;
}