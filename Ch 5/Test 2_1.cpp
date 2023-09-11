/*
Второй вариант решения предыдущего задания
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
    std::cout << "A " << getAnimalName(animal) << " has ";
    
    switch(animal)
    {
        case Animal::PIG:
        case Animal::GOAT:
        case Animal::CAT:
        case Animal::DOG:
        std::cout << "4 legs." << std::endl;
        break;

        case Animal::CHICKEN:
        case Animal::OSTRICH:
        std::cout << "2 legs" << std::endl;
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