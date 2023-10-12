/*
Напишите функцию для вывода строки C-style символ за символом.
Используйте указатель для перехода и вывода каждого символа поочерёдно.
Остановите вывод при столкновении с нуль-терминатором.
В функции main() протестируйте строку Hello, world!.
*/

#include <iostream>

void outputCStyle(char *array)
{
    while (*array != '/0')
    {
        std::cout << *array << "\n";
        array++;
    }
}

int main()
{
    char string[] = "Hello, world";

    outputCStyle(string);
    return 0;
}