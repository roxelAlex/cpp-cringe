/*
Создайте структуру Student, которая будет хранить имя и баллы студента.
Создайте массив студентов и используйте функцию std::max_element() для
поиска студента с наибольшими баллами, а затем выведите на экран имя
найденного студента. Функция std::max_element() принимает begin и end
списка, и функцию с двумя параметрами, которая возвращает true, если первый
аргумент меньше второго.
*/

#include <iostream>
#include <array>

struct Student
{
    std::string name;
    int score;
};

int main()
{
    std::array<Student, 8> arr{
        { {"Albert", 3},
            {"Ben", 5},
            {"Christine", 2},
            {"Dan", 8},
            {"Enchilada", 4},
            {"Francis", 1},
            {"Greg", 3},
            {"Hagrid", 5} }
    };

    auto best{
    std::max_element(arr.begin(), arr.end(), [](const auto &a, const auto &b) 
    {
        return (a.score < b.score);
    })
    };

    std::cout << best -> name << " is the best student";
    
    return 0;
}