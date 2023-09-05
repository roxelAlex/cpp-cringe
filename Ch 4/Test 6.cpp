/*
Создайте структуру для хранения дробных чисел. Структура должна иметь 2 члена:
целочисленный числитель и целочисленный знаменатель.
Объявите две дробные переменные и получите их значения от пользователя.
Напишите функцию multiply() (параметрами которой будут эти две переменные),
которая будет перемножать эти числа и выводить результат в виде
десятичного числа.
*/

#include <iostream>

struct Float_number
{
    int numerator;
    int denominator;
};

void multiply(Float_number FloatN1, Float_number FloatN2)
{
    int result_numerator = FloatN1.numerator * FloatN2.numerator;
    int result_denominator = FloatN1.denominator * FloatN2.denominator;

    // Используем оператор static_cast, чтобы при делении двух int не потерять
    // дробь числа. Применяем только к первому int, потому что второй преобразуется
    // автоматически.
    std::cout << "Результат перемножения двух дробей: " << static_cast<double>(result_numerator) / result_denominator;
}

Float_number getFloatNumber()
{
    Float_number FloatUser;
    std::cout << "Введите ваше дробное число (разделите их пробелом вместо точки или запятой): ";
    std::cin >> FloatUser.numerator >> FloatUser.denominator;
    return FloatUser;
}

int main()
{
    setlocale(LC_ALL, "rus");
    Float_number FloatN1, FloatN2;
    FloatN1 = getFloatNumber();
    FloatN2 = getFloatNumber();
    multiply(FloatN1, FloatN2);
    return 0;
}