/*
Напишите программу, которая просит у пользователя ввести его имя,
фамилию и возраст. В результате, укажите пользователю,
сколько лет он прожил на каждую букву из его имени и фамилии
(чтобы было проще, учитывайте также пробелы).
*/

#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter your full name: ";
    std::string myName;
    std::getline(std::cin, myName);

    std::cout << "Enter your age: ";
    int age;
    std::cin >> age;

    std::cout << "You've lived " << static_cast<double>(age) / myName.length() << " years for each letter in your name.";
    return 0;
}