/*
Создайте перечисление со следующими перечислителями:
chicken, lion, giraffe, elephant, duck и snake.
Поместите перечисление в пространство имен. Объявите массив, где элементами
будут эти перечислители и, используя список инициализаторов, инициализируйте
каждый элемент соответствующим количеством лап определенного животного.
В функции main() выведите количество ног у слона, используя перечислитель.
*/

#include <iostream>

namespace Animals
{
    enum Animals
    {
        CHICKEN,
        LION,
        GIRAFFE,
        ELEPHANT,
        DUCK,
        SNAKE,
        MAX_ANIMALS,
    };
}

int main()
{
    int legsOfAnimals[Animals::MAX_ANIMALS] = {2, 4, 4, 4, 2, 0};
    std::cout << "Elephant has " << legsOfAnimals[Animals::ELEPHANT] << " legs";
    return 0;
}