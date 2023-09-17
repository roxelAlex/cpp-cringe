/*
Измените программу из последнего подраздела «Вложенные циклы» так,
чтобы она выводила следующее:

5 4 3 2 1
4 3 2 1
3 2 1
2 1
1
*/

#include <iostream>

int main()
{
    int outer = 5;
    while (outer >= 1)
    {
        int inner = outer;
        while (inner >= 1)
            std::cout << inner-- << " ";
        std::cout << "\n";
        --outer;
    }
    return 0;
}