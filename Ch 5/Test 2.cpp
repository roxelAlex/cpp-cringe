/*
Определите перечисление (или класс enum) Animal, которое содержит
следующих животных: pig, chicken, goat, cat, dog и ostrich. Напишите функцию
getAnimalName(), которая принимает параметр Animal и использует switch
для возврата типа животного в качестве строки. Напишите еще одну функцию —
printNumberOfLegs(), которая использует switch для вывода количества лап 
соответствующего типа животного. Убедитесь, что обе функции имеют кейс
default, который выводит сообщение об ошибке. Вызовите printNumberOfLegs()
в main(), используя в качестве параметров cat и chicken.
*/

#include <iostream>

enum class Animal
{
    PIG,
    CHICKEN,
    GOAT,
    CAT,
    DOG,
    OSTRICH,
};

std::string getAnimalName(Animal animal)
{
    switch(animal)
    {
        case Animal::PIG:
            return "Pig";
            break;
        case Animal::CHICKEN:
            return "Chicken";
            break;
        case Animal::GOAT:
            return "Goat";
            break;
        case Animal::CAT:
            return "Cat";
            break;
        case Animal::DOG:
            return "Dog";
            break;
        case Animal::OSTRICH:
            return "Ostrich";
            break;
        default:
        std::cout << "Error." << std::endl;
        break;

    }
}

void pringNumberOfLegs(Animal animal)
{
    switch(animal)
    {
        case Animal::PIG:
        std::cout << "A " << getAnimalName(animal) << " has 4 legs." << std::endl;
        break;

        case Animal::CHICKEN:
        std::cout << "A " << getAnimalName(animal) << " has 2 legs" << std::endl;
        break;

        case Animal::GOAT:
        std::cout << "A " << getAnimalName(animal) << " has 4 legs." << std::endl;
        break;

        case Animal::CAT:
        std::cout << "A " << getAnimalName(animal) << " has 4 legs." << std::endl;
        break;

        case Animal::DOG:
        std::cout << "A " << getAnimalName(animal) << " has 4 legs." << std::endl;
        break;

        case Animal::OSTRICH:
        std::cout << "A " << getAnimalName(animal) << " has 2 legs." << std::endl;
        break;

        default:
        std::cout << "Error." << std::endl;
        break;
    }
}

int main()
{
    pringNumberOfLegs(Animal::CAT);
    pringNumberOfLegs(Animal::CHICKEN);
    return 0;
}