// Функция с именем max(), которая принимает два значения типа double
// и возвращает большее из них.
double max(const double a, const double b);

// Функция swap(), которая меняет местами два целых числа.
void swap(int &a, int &b);

// Функция getLargestElement(), которая принимает динамически выделенный
// массив целых чисел и возвращает наибольшее число таким образом, что
// caller может изменить значение возвращаемого элемента
// (не забудьте о параметре-длине).
int& getLargestElement(int *array, const int length);