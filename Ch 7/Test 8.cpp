/*
Используйте std::sort() и лямбду в следующем коде для сортировки времен
года по возрастанию средней температуры.
*/

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

struct Season
{
    std::string_view name{};
    double averageTemperature{};
};

int main()
{
    std::array<Season, 4> seasons{
        { {"Spring", 285.0},
          {"Summer", 296.0},
          {"Fall", 288.0},
          {"Winter", 263.0} }
    };

    // Решение задачи начинается здесь.
    std::sort(seasons.begin(), seasons.end(), [](const auto &a, const auto &b)
    {
        return (a.averageTemperature < b.averageTemperature);
    }); // И кончается тут.

    for (const auto &seasons : seasons)
    {
        std::cout << seasons.name << '\n';
    }

    return 0;
}